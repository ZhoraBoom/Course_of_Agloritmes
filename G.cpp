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
    if (arr[i] < med) {
      left_arr[lef] = arr[i];
      ++lef;
    } else if (arr[i] > med) {
      right_arr[rig] = arr[i];
      ++rig;
    } else {
      middle_arr[mid] = arr[i];
      ++mid;
    }
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
  delete[] left_arr, delete[] right_arr, delete[] middle_arr;
}

int main() {
  int number;
  std::cin >> number;
  int* array = new int[number];
  for (int i = 0; i < number; ++i) {
    std::cin >> array[i];
  }
  QuikSort(array, number);
  for (int i = 0; i < number; ++i) {
    std::cout << array[i] << " ";
  }
  delete[] array;
}
