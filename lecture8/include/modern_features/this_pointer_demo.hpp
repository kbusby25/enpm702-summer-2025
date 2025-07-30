#include <iostream>

class Box {
private:
  int width;

public:
  Box(int width) {
    this->width = width; // Disambiguates member from parameter
  }

  Box &double_size() {
    this->width *= 2;
    return *this; // Enables method chaining
  }

  void print() const { std::cout << "Width: " << this->width << '\n'; }
};