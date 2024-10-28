#include <iostream>
#include <list>

int main() {
    // Declaration of a list
    std::list<int> myList;
    std::list<int> ll = {1,2,3,4,5,6};
    std::cout<<std::endl;
    for (auto it = ll.begin(); it != ll.end(); it++) {
        std::cout<< *it << " ";
    }
    std::cout<<std::endl<<std::endl;

    // push_back() - Adds elements at the end
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    
    // push_front() - Adds elements at the beginning
    myList.push_front(5);
    myList.push_front(1);

    // Display the list
    std::cout << "List after push_front and push_back: ";
    for (auto it = myList.begin(); it != myList.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // pop_back() - Removes the last element
    myList.pop_back();

    // pop_front() - Removes the first element
    myList.pop_front();

    // Display the list
    std::cout << "List after pop_front and pop_back: ";
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Access the front element
    std::cout << "Front element: " << myList.front() << std::endl;

    // Access the back element
    std::cout << "Back element: " << myList.back() << std::endl;

    // Check if the list is empty
    if (myList.empty()) {
        std::cout << "The list is empty." << std::endl;
    } else {
        std::cout << "The list is not empty." << std::endl;
    }

    // Get the size of the list
    std::cout << "Size of the list: " << myList.size() << std::endl;

    // Using iterator to display elements again
    std::cout << "Final list elements: ";
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
