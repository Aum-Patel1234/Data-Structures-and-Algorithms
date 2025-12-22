#include <cstdint>
#include <iostream>
#include <iterator>
#include <list>
#include <unordered_map>

class LFUCache {
 private:
  struct Node {
    uint32_t val, count;
    std::list<uint32_t>::iterator it;
  };

  std::unordered_map<uint32_t, Node> map;                  // key,  Node
  std::unordered_map<uint32_t, std::list<uint32_t>> freq;  // count, key

  // here minCount signifies the least key in freq that has node
  uint16_t size, capacity;
  uint32_t minCount;

 public:
  LFUCache(int capacity) : capacity(capacity), size(0), minCount(0) {}

  int get(int key) {
    auto itMap = map.find(key);
    if (itMap == map.end()) return -1;

    Node& node = itMap->second;
    uint32_t count = node.count;
    freq.at(count).erase(node.it);
    // check if size of the currCount is 0 means each node has freq greater than node->count
    if (count == minCount && freq.at(node.count).empty()) minCount++;
    node.count++;
    freq[node.count].push_back(key);
    node.it = std::prev(freq[node.count].end());
    return node.val;
  }

  void put(int key, int value) {
    if (map.count(key)) {
      // remove from freq and add to next count
      // if 1->node then shift ahead : 2 -> node
      auto& [val, count, it] = map.at(key);
      val = value;
      freq.at(count).erase(it);
      // check if size of the currCount is 0 means each node has freq greater than node->count
      if (minCount == count && freq.at(count).empty()) minCount++;
      count++;
      freq[count].push_back(key);
      it = std::prev(freq[count].end());
      return;
    }

    if (size >= capacity) {
      uint32_t key = freq[minCount].front();
      freq[minCount].pop_front();
      map.erase(key);
      size--;  // to complement ++
    }
    freq[1].push_back(key);
    map[key] = {uint32_t(value), 1, std::prev(freq[1].end())};
    minCount = 1;
    size++;
  }
};

int main() {
  // ---------- 🧪 Test Case 1: Basic operations ----------
  {
    LFUCache cache(2);
    cache.put(1, 10);
    cache.put(2, 20);

    std::cout << "Test Case 1: Basic operations\n";
    std::cout << "get(1): " << cache.get(1) << " (Expected: 10)\n";
    cache.put(3, 30);  // evicts key 2
    std::cout << "get(2): " << cache.get(2) << " (Expected: -1)\n";
    std::cout << "get(3): " << cache.get(3) << " (Expected: 30)\n\n";
  }

  // ---------- 🧪 Test Case 2: Frequency-based eviction ----------
  {
    LFUCache cache(2);
    cache.put(1, 10);
    cache.put(2, 20);

    cache.get(1);  // freq(1) = 2
    cache.get(1);  // freq(1) = 3

    cache.put(3, 30);  // evicts key 2 (freq = 1)

    std::cout << "Test Case 2: Frequency-based eviction\n";
    std::cout << "get(1): " << cache.get(1) << " (Expected: 10)\n";
    std::cout << "get(2): " << cache.get(2) << " (Expected: -1)\n";
    std::cout << "get(3): " << cache.get(3) << " (Expected: 30)\n\n";
  }

  // ---------- 🧪 Test Case 3: LRU tie-breaking ----------
  {
    LFUCache cache(2);
    cache.put(1, 10);
    cache.put(2, 20);

    cache.get(1);  // freq(1) = 2
    cache.get(2);  // freq(2) = 2 → same freq, 1 is LRU

    cache.put(3, 30);  // evicts key 1

    std::cout << "Test Case 3: LRU tie-breaking\n";
    std::cout << "get(1): " << cache.get(1) << " (Expected: -1)\n";
    std::cout << "get(2): " << cache.get(2) << " (Expected: 20)\n";
    std::cout << "get(3): " << cache.get(3) << " (Expected: 30)\n\n";
  }

  return 0;
}
