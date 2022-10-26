#include <iostream>
#include <vector>

bool Detector(const int* arr_det, int n) {
  int minim = arr_det[0];
  int maxim = arr_det[0];
  for (int i = 1; i < n; ++i) {
    if (arr_det[i] > maxim) {
      maxim = arr_det[i];
    }
    if (arr_det[i] < minim) {
      minim = arr_det[i];
    }
  }
  return maxim == minim;
}

void Builder(int* array, const int* add, int place, int add_size) {
  for (int i = 0; i < add_size; ++i) {
    array[i + place] = add[i];
  }
}

void QuikSort(int* arr, int number) {
  if (number == 1 || Detector(arr, number)) {
    return;
  }
  int med = arr[number / 2], lef = 0, mid = 0, rig = 0;
  int* left_arr = new int[number];
  int* right_arr = new int[number];
  int* middle_arr = new int[number];
  for (int i = 0; i < number; ++i) {
    arr[i] < med
        ? left_arr[lef] = arr[i]
        : (arr[i] == med ? middle_arr[mid] = arr[i] : right_arr[rig] = arr[i]);
    arr[i] < med ? ++lef : (arr[i] == med ? ++mid : ++rig);
  }
  if (lef > 0) {
    QuikSort(left_arr, lef), Builder(arr, left_arr, 0, lef);
  }
  if (mid > 0) {
    Builder(arr, middle_arr, lef, mid);
  }
  if (rig > 0) {
    QuikSort(right_arr, rig), Builder(arr, right_arr, lef + mid, rig);
  }
  delete[] left_arr;
  delete[] right_arr;
  delete[] middle_arr;
}

void Reading(size_t number, int* first) {
  for (size_t i = 0; i < number; ++i) {
    std::cin >> *first;
    ++first;
  }
}

void Couter(size_t number, int* first) {
  for (size_t i = 0; i < number; ++i) {
    std::cout << *first << " ";
    ++first;
  }
}

int main() {
  size_t number;
  std::cin >> number;
  int* array = new int[number];
  int* link_to_first = array;
  Reading(number, link_to_first);
  QuikSort(array, number);
  int* new_link_to_first = array;
  Couter(number, new_link_to_first);
  delete[] array;
}
