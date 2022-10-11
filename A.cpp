#include <iostream>

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

int main() {
  int left_edge;
  int target;
  int right_edge;
  int number;
  std::cin >> number;
  int* array = new int[number + 1];
  for (int i = 0; i < number; ++i) {
    std::cin >> array[i];
  }
  array[number] = array[number - 1];
  int call;
  std::cin >> call;
  for (int i = 0; i < call; ++i) {
    std::cin >> left_edge;
    std::cin >> right_edge;
    std::cin >> target;
    int* right_edge_link = &array[right_edge];
    int* left_edge_link = &array[left_edge];
    if (BinarySearch(left_edge_link, right_edge_link, target)) {
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
  }
  delete[] array;
  return 0;
}
