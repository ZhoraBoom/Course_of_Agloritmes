#include <iostream>

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
int main() {
  int number;
  std::cin >> number;
  int* array = new int[number];
  for (int i = 0; i < number; ++i) {
    std::cin >> array[i];
  }
  int* left_edge_link = &array[0];
  int* const_link_to_the_first_element = &array[0];
  int* right_edge_link = &array[number - 1];
  if (array[0] < array[number - 1]) {
    std::cout << 0;
  } else {
    std::cout << BinarySearch(left_edge_link, right_edge_link,
                              const_link_to_the_first_element);
  }
  delete[] array;
  return 0;
}
