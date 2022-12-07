#include <cmath>
#include <iomanip>
#include <iostream>

void Reading(size_t number, double* first) {
  for (size_t i = 0; i < number; ++i) {
    std::cin >> *first;
    ++first;
  }
}

void Prefix(double* last_elem, double* first_elem, double previous_step) {
  if (last_elem != first_elem) {
    *last_elem = log(*last_elem) + previous_step;
    previous_step = *last_elem;
    Prefix(--last_elem, first_elem, previous_step);
  } else {
    *last_elem = log(*last_elem) + previous_step;
  }
}

void Couter(const double* link_to_first, const double* link_to_last) {
  size_t request;
  int left_edge;
  int right_edge;
  std::cin >> request;
  for (size_t i = 0; i < request; ++i) {
    std::cin >> left_edge;
    std::cin >> right_edge;
    double segment = right_edge - left_edge + 1;
    if (right_edge != link_to_last - link_to_first) {
      std::cout << std::setprecision(8)
                << exp((*(link_to_first + left_edge) -
                        *(link_to_first + right_edge + 1)) /
                       segment)
                << '\n';
    } else {
      std::cout << std::setprecision(8)
                << exp(*(link_to_first + left_edge) / segment) << '\n';
    }
  }
}

int main() {
  size_t number;
  std::cin >> number;
  double* array = new double[number];
  double* link_to_first = &array[0];
  Reading(number, link_to_first);
  double* last_element_link = &array[number - 1];
  double* first_element_link = &array[0];
  Prefix(last_element_link, first_element_link, 0.0);
  double* new_link_to_first = &array[0];
  double* new_link_to_last = &array[number - 1];
  Couter(new_link_to_first, new_link_to_last);
  delete[] array;
}
