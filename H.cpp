#include <cmath>
#include <iomanip>
#include <iostream>

void Prefix(double* last_elem, double* first_elem, double previous_step) {
  if (last_elem != first_elem) {
    *last_elem = log(*last_elem) + previous_step;
    previous_step = *last_elem;
    Prefix(--last_elem, first_elem, previous_step);
  } else {
    *last_elem = log(*last_elem) + previous_step;
  }
}

int main() {
  int number;
  std::cin >> number;
  double* array = new double[number];
  for (int i = 0; i < number; ++i) {
    std::cin >> array[i];
  }
  double* last_element_link = &array[number - 1];
  double* first_element_link = &array[0];
  Prefix(last_element_link, first_element_link, 0.0);
  int request;
  int left_edge;
  int right_edge;
  std::cin >> request;
  for (int i = 0; i < request; ++i) {
    std::cin >> left_edge;
    std::cin >> right_edge;
    double segment = right_edge - left_edge + 1;
    if (right_edge != number - 1) {
      std::cout << std::setprecision(8)
                << exp((array[left_edge] - array[right_edge + 1]) / segment)
                << '\n';
    } else {
      std::cout << std::setprecision(8) << exp(array[left_edge] / segment)
                << '\n';
    }
  }
  delete[] array;
}
