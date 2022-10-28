#include <cmath>
#include <iostream>
#include <vector>

class MaxHeap {
 public:
  void Insert(int64_t x, int lim);
  void ExtractMax();
  int GetMax();
  int Size();

 private:
  std::vector<int64_t> hp_max_;
};

void SiftUpMax(std::vector<int64_t>& array, int iterator) {
  while (iterator != 0) {
    if (array[(iterator - 1) / 2] < array[iterator]) {
      std::swap(array[(iterator - 1) / 2], array[iterator]);
      iterator = (iterator - 1) / 2;
    } else {
      break;
    }
  }
}

void SiftDownMax(std::vector<int64_t>& array, int iter) {
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

int MaxHeap::Size() { return (int)hp_max_.size(); }

void MaxHeap::Insert(int64_t x, int lim) {
  if ((int)hp_max_.size() == lim) {
    if (x < GetMax()) {
      ExtractMax();
      hp_max_.push_back(x);
      SiftUpMax(hp_max_, (int)hp_max_.size() - 1);
    }
  } else {
    hp_max_.push_back(x);
    SiftUpMax(hp_max_, (int)hp_max_.size() - 1);
  }
}

int MaxHeap::GetMax() { return hp_max_[0]; }

void MaxHeap::ExtractMax() {
  std::swap(hp_max_[0], hp_max_[hp_max_.size() - 1]);
  hp_max_.pop_back();
  SiftDownMax(hp_max_, 0);
}

int main() {
  int number;
  int couter;
  int64_t elem, x, y;
  std::cin >> number;
  std::cin >> couter;
  std::cin >> elem >> x >> y;
  MaxHeap heap;
  int modul = pow(2, 30);
  for (int i = 0; i < number; ++i) {
    elem = (x * elem + y) % modul;
    heap.Insert(elem, couter);
  }
  std::vector<int64_t> arr;
  int size_of = heap.Size();
  for (int i = 0; i < size_of; ++i) {
    arr.push_back(heap.GetMax());
    heap.ExtractMax();
  }
  for (int i = size_of - 1; i >= 0; --i) {
    std::cout << arr[i] << " ";
  }
}
