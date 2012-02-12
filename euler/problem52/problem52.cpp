#include <iostream>
#include "my_helper_functions.h"

using namespace projecteuler;

int main() {
  
  for (int x = 1; true; x++) {
    if ( same_digits(to_string(x), to_string(2*x)) &&
	 same_digits(to_string(x), to_string(3*x)) &&
	 same_digits(to_string(x), to_string(4*x)) &&
	 same_digits(to_string(x), to_string(5*x)) &&
	 same_digits(to_string(x), to_string(6*x)) ) {

      std::cout << "Answer: " << x << std::endl;
      return 0;
    }
  }

  return 0;
}
