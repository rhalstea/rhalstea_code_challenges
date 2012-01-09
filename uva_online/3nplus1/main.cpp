#include <iostream>

void set_max(unsigned &big, unsigned &small) {
  if (big < small) {
    int tmp = big;
    big = small;
    small = tmp;
  }
}

int main() {

  unsigned a, b, tmp, count;
  unsigned max = 0;
  while (std::cin >> a >> b) {
    std::cout << a << " " << b << " ";
    set_max(b,a);
    
    max = 0;
    for (int i = a; i <= b; ++i) {
      tmp = i;
      count = 1;

      while (tmp != 1) {
	count++;
	if (tmp % 2 == 0)
	  tmp = tmp / 2;
	else
	  tmp = 3 * tmp + 1;
      }

      if (count > max)
	max = count;
    }

    std::cout << max << std::endl;
  }

  return 0;
}
