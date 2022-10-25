#include <iostream>

void Reading(size_t number, int* first) {
  int a;
  for (size_t i = 0; i < number; ++i) {
    std::cin >> a;
    *first = a;
    first = first + 1;
  }
  *first = *(first - 1);
}

bool BinarySearch(int* left_edge, int* right_edge, int target) {
  if (target > *right_edge || target < *left_edge) {
    return false;
  }
  if (left_edge + 1 != right_edge) {
    int difference = (right_edge - left_edge) / 2;
    if (target < *(left_edge + difference)) {
      right_edge = left_edge + difference;
      return BinarySearch(left_edge, right_edge, target);
    }
    left_edge = left_edge + difference;
    return BinarySearch(left_edge, right_edge, target);
  }
  return *left_edge == target;
}

void Couter(int* first) {
  size_t call;
  std::cin >> call;
  int left_edge;
  int target;
  int right_edge;
  for (size_t i = 0; i < call; ++i) {
    std::cin >> left_edge;
    std::cin >> right_edge;
    std::cin >> target;
    int* right_edge_link = right_edge + first;
    int* left_edge_link = left_edge + first;
    if (BinarySearch(left_edge_link, right_edge_link, target)) {
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
  }
}

int main() {
  size_t number;
  std::cin >> number;
  int* array = new int[number + 1];
  int* link_to_first = &array[0];
  Reading(number, link_to_first);
  int* new_link_to_first = &array[0];
  Couter(new_link_to_first);
  delete[] array;
  return 0;
}

