#ifndef __LIB_MY_HELPER_FUNCTIONS_H__
#define __LIB_MY_HELPER_FUNCTIONS_H__

#include <sstream>
#include "euler_helper_functions.h"


namespace projecteuler {

  bool is_pandigital(std::string s) {
    int tmp[10] = {0};

    for (int i = 0; i < s.size(); ++i)
      tmp[ (int)s[i] - 48 ]++;

    for (int i = 0; i < 10; ++i)
      if (tmp[i] != 1)
	return false;

    return true;
  }

  bool is_n_digit_pandigital(std::string s) {
    int tmp[10] = {0};

    for (int i = 0; i < s.size(); ++i)
      tmp[ (int)s[i] - 48 ]++;

    bool flag = false;
    for (int i = 1; i < 10; ++i) {
      if (tmp[i] > 1)
	return false;
      else if (flag && tmp[i] != 0)
	return false;
      else if (tmp[i] == 0)
	flag = true;
    }

    return true;
  }

  template <class T>
    bool is_pandigital(T val) {

    std::stringstream ss;
    ss << val;
    return is_pandigital(ss.str());
  }

  template <class T>
    bool is_n_digit_pandigital(T val) {
    std::stringstream ss;
    ss << val;
    return is_n_digit_pandigital(ss.str());
  }


};

#endif
