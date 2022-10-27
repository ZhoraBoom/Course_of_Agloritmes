#include <cmath>
#include <iostream>
#include <vector>

class MaxHeap {
 public:
  void Insert(int64_t x, int lim);
  void ExtractMax();
  int GetMax() const;
  int Size() const;

 private:
  void SiftDown(std::vector<int64_t>& array, int iter);
  void SiftUp(std::vector<int64_t>& array, int iterator);
  std::vector<int64_t> perm_arr_;
};

void MaxHeap::SiftUp(std::vector<int64_t>& array, int iterator) {
  while (iterator != 0) {
    if (array[(iterator - 1) / 2] < array[iterator]) {
      std::swap(array[(iterator - 1) / 2], array[iterator]);
      iterator = (iterator - 1) / 2;
    } else {
      break;
    }
  }
}

void MaxHeap::SiftDown(std::vector<int64_t>& array, int iter) {
  while (2 * iter + 2 < (int)array.size()) {
    if (array[iter] < std::max(array[2 * iter + 1], array[2 * iter + 2])) {
      if (array[2 * iter + 1] > array[2 * iter + 2]) {
        std::swap(array[iter], array[2 * iter + 1]);
        iter = 2 * iter + 1;
      } else {
        std::swap(array[iter], array[2 * iter + 2]);
        iter = 2 * iter + 2;
      }
    } else {
      break;
    }
  }
  if ((int)array.size() - 1 == 2 * iter + 1 &&
      array[iter] < array[iter * 2 + 1]) {
    std::swap(array[iter], array[2 * iter + 1]);
  }
}

int MaxHeap::Size() const { return (int)perm_arr_.size(); }

void MaxHeap::Insert(int64_t x, int lim) {
  if ((int)perm_arr_.size() == lim) {
    if (x < GetMax()) {
      ExtractMax();
      perm_arr_.push_back(x);
      SiftUp(perm_arr_, (int)perm_arr_.size() - 1);
    }
  } else {
    perm_arr_.push_back(x);
    SiftUp(perm_arr_, (int)perm_arr_.size() - 1);
  }
}

int MaxHeap::GetMax() const { return perm_arr_[0]; }

void MaxHeap::ExtractMax() {
  std::swap(perm_arr_[0], perm_arr_[perm_arr_.size() - 1]);
  perm_arr_.pop_back();
  SiftDown(perm_arr_, 0);
}

void Reading(MaxHeap& heap) {
  int number;
  int couter;
  int64_t elem, x, y;
  std::cin >> number;
  std::cin >> couter;
  std::cin >> elem >> x >> y;
  int modul = pow(2, 30);
  for (int i = 0; i < number; ++i) {
    elem = (x * elem + y) % modul;
    heap.Insert(elem, couter);
  }
}

void Worker(MaxHeap& heap, std::vector<int64_t>& arr, int size_of) {
  for (int i = 0; i < size_of; ++i) {
    arr.push_back(heap.GetMax());
    heap.ExtractMax();
  }
}

void Print(std::vector<int64_t>& arr, int size_of) {
  for (int i = size_of - 1; i >= 0; --i) {
    std::cout << arr[i] << " ";
  }
}

int main() {
  MaxHeap heap;
  Reading(heap);
  std::vector<int64_t> arr;
  int size_of = heap.Size();
  Worker(heap, arr, size_of);
  Print(arr, size_of);
}
