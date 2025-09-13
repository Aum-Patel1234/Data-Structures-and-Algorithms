#include <iostream>

class Patterns {
public:
  void triangle(int n) {
    int left = n, stars = 1;
    int total = n * 2 + 1;
    for (int i = 0, temp = 0; i <= n; i++) {
      temp = 0;
      while (temp++ < left)
        std::cout << " ";
      temp = 0;
      while (temp++ < stars)
        std::cout << "* ";
      stars++;
      left--;
      std::cout << std::endl;
    }
  }

  void starPattern(int n) { // n should be odd
    triangle(n);
    int stars = n;
    for (int i = 0, temp = 0, left = 1; i < n; i++) {
      temp = 0;
      while (temp++ < left)
        std::cout << " ";
      temp = 0;
      while (temp++ < stars)
        std::cout << "* ";
      stars--;
      left++;
      std::cout << std::endl;
    }
  }
};

int main() {
  Patterns *p;
  p->starPattern(5);
  std::cout << std::endl;
  p->triangle(2);
  return 0;
}
