#include <iostream>

void Reading(size_t number, int* first) {
  for (size_t i = 0; i < number; ++i) {
    std::cin >> *first;
    ++first;
  }
}

int BinarySearch(int* left_edge, int* right_edge, int* const_link) {
  if (left_edge + 1 == right_edge) {
    return right_edge - const_link;
  }
  int middle = (right_edge - left_edge) / 2;
  if (*left_edge < *(left_edge + middle)) {
    left_edge = left_edge + middle;
    return BinarySearch(left_edge, right_edge, const_link);
  }
  right_edge = left_edge + middle;
  return BinarySearch(left_edge, right_edge, const_link);
}

void Couter(int* left_edge_link, int* right_edge_link,
            int* const_link_to_the_first_element) {
  if (*left_edge_link < *right_edge_link) {
    std::cout << 0;
  } else {
    std::cout << BinarySearch(left_edge_link, right_edge_link,
                              const_link_to_the_first_element);
  }
}

int main() {
  size_t number;
  std::cin >> number;
  int* array = new int[number];
  int* link_to_first = &array[0];
  Reading(number, link_to_first);
  int* left_edge = &array[0];
  int* const_link_to_first = &array[0];
  int* right_edge = &array[number - 1];
  Couter(left_edge, right_edge, const_link_to_first);
  delete[] array;
  return 0;
}
