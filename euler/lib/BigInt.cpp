#include "BigInt.h"

#include <iostream>
#include <sstream>
#include <cassert>

projecteuler::BigInt::BigInt() {
  value_.clear();
  value_.push_back(0);
  negative_ = false;
}

projecteuler::BigInt::BigInt(int val)  {
  std::stringstream ss;
  ss << val;
  set_string(ss.str());
}

projecteuler::BigInt::BigInt(std::string val) {
  set_string(val);
}

projecteuler::BigInt::~BigInt() {
  value_.clear();
}

std::string projecteuler::BigInt::get_value() {
  std::string ret = "";
  std::vector<int> digits = this->value_;
  if (negative_) {
    ret = "-";
    complement(digits);
  }

  std::vector<int>::reverse_iterator digit;
  for (digit = digits.rbegin(); digit != digits.rend(); digit++) {
    ret += (char)( (*digit) + 48 );
  }

  return ret;
}

unsigned int projecteuler::BigInt::number_digits() {
  return size();
}

unsigned int projecteuler::BigInt::size() {
  return value_.size();
}

bool projecteuler::BigInt::operator>(BigInt b) {
  BigInt a = *this;

  if (a.negative_ and !b.negative_)
    return false;
  else if (!a.negative_ and b.negative_)
    return true;

  match_size_of_digits(a, b);
  int ret = compare(a.value_, b.value_);

  if (ret == 0)
    return false;
  else if (ret > 0)
    return false;
  else
    return true;
}

bool projecteuler::BigInt::operator<(BigInt b) {
  return ( !(*this > b) and !(*this == b) );
}

bool projecteuler::BigInt::operator==(BigInt b) {
  BigInt a = *this;
  if (a.negative_ != b.negative_)
    return false;

  match_size_of_digits(a, b);
  return (compare(a.value_, b.value_) == 0);
}

bool projecteuler::BigInt::operator!=(BigInt b) {
  return !(*this == b);
}

bool projecteuler::BigInt::operator>=(BigInt b) {
  return ((*this > b) or (*this == b));
}

bool projecteuler::BigInt::operator<=(BigInt b) {
  return ((*this < b) or (*this == b));
}

projecteuler::BigInt projecteuler::BigInt::operator+(projecteuler::BigInt b) {
  BigInt a = *this;

  match_size_of_digits(a, b);
  extend(a, 1);
  extend(b, 1);

  add_vector(a.value_, b.value_);

  if (a.negative_ == b.negative_) {
    if (a.negative_)
      a.value_.pop_back();
  }
  else {
    if (a.value_.back() >= 5) // not sure if this should be > or >=
      a.negative_ = true;
    else
      a.negative_ = false;
    
    a.value_.pop_back();
  }

  clean_leading_digits(a);
  return a;
}

projecteuler::BigInt projecteuler::BigInt::operator-(projecteuler::BigInt b) {
  if (b == 0)
    return *this;

  complement(b.value_);
  b.negative_ = not b.negative_;

  return *this + b;
}

projecteuler::BigInt projecteuler::BigInt::operator*(projecteuler::BigInt b) {
  if (*this == 0 || b == 0)
    return 0;

  BigInt a = *this;
  bool negative = 0 xor a.negative_ xor b.negative_;

  if (a.negative_) {
    complement(a.value_);
    a.negative_ = false;
  }
  if (b.negative_) {
    complement(b.value_);
    b.negative_ = false;
  }

  match_size_of_digits(a, b);

  a = karatsuba(a, b);
  a.negative_ = (a != 0) and negative ;

  if (a.negative_)
    complement(a.value_);

  return a;
}

void projecteuler::BigInt::operator++() {
  *this = *this + 1;
}

void projecteuler::BigInt::operator++(int) {
  *this = *this + 1;
}

void projecteuler::BigInt::operator--() {
  *this = *this - 1;
}

void projecteuler::BigInt::operator--(int) {
  *this = *this - 1;
}

void projecteuler::BigInt::operator+=(projecteuler::BigInt b) {
  *this = *this + b;
}

void projecteuler::BigInt::operator-=(projecteuler::BigInt b) {
  *this = *this - b;
}

void projecteuler::BigInt::operator*=(projecteuler::BigInt b) {
  *this = *this * b;
}




// Private Functions
// ----- ----- ----- ----- -----
void projecteuler::BigInt::set_string(std::string val) {
  value_.clear();
  negative_ = false;

  std::string::reverse_iterator c;
  int tmp;
  for (c = val.rbegin(); c != val.rend(); c++) {
    if ( *c == '-' ) {
      negative_ = true;
      complement(this->value_);
      return;
    } 

    tmp = (int)(*c) - 48;
    value_.push_back(tmp % 10);
  }
}

void projecteuler::BigInt::complement(std::vector<int> &val) {
  for (int i = 0; i < val.size(); ++i) {
    val[i] = 9 - val[i];
  }

  std::vector<int> one;
  one.push_back(1);
  while( one.size() != val.size())
    one.push_back(0);

  add_vector(val, one);
}

int projecteuler::BigInt::compare(std::vector<int> &left, 
				  std::vector<int> &right) {
  assert( left.size() == right.size() );
  std::vector<int>::reverse_iterator l, r;
  for (l = left.rbegin(), r = right.rbegin(); l != left.rend(); ++l, ++r) {
    if (*l > *r)
      return -1;
    else if (*l < *r)
      return 1;
  }
  
  return 0;
}

bool projecteuler::BigInt::all_zero(std::vector<int> &val) {
  for (int i = 0; i < val.size(); ++i)
    if (val[i] != 0)
      return false;

  return true;
}

void projecteuler::BigInt::preappend(projecteuler::BigInt &val, int num) {
  int digit = (val.negative_)? 9 : 0;
  std::vector<int> tmp = val.value_;
  val.value_.clear();

  for (int i = 0; i < num; ++i)
    val.value_.push_back(digit);
  for (int i = 0; i < tmp.size(); ++i)
    val.value_.push_back(tmp[i]);
}

int projecteuler::BigInt::split(projecteuler::BigInt &in,
				projecteuler::BigInt &out0,
				projecteuler::BigInt &out1) {
  int middle = in.value_.size() / 2;
  out0.value_.clear();
  out1.value_.clear();

  for (int i = 0; i < in.value_.size(); ++i) {
    if (i < middle)
      out0.value_.push_back(in.value_[i]);
    else
      out1.value_.push_back(in.value_[i]);
  }

  return middle;
}

void projecteuler::BigInt::extend(projecteuler::BigInt &val, int increase) {
  int digit = (val.negative_)? 9 : 0;

  for (int i = 0; i < increase; ++i)
    val.value_.push_back(digit);
}

void projecteuler::BigInt::match_size_of_digits(projecteuler::BigInt &a,
						projecteuler::BigInt &b) {
  if (a.value_.size() > b.value_.size())
    extend(b, a.value_.size() - b.value_.size());
  else if (a.value_.size() < b.value_.size())
    extend(a, b.value_.size() - a.value_.size());
}

void projecteuler::BigInt::clean_leading_digits(projecteuler::BigInt &a) {
  int look_for = (a.negative_)? 9 : 0;

  while (a.value_.size() > 1 && a.value_.back() == look_for)
    a.value_.pop_back();
}

void projecteuler::BigInt::add_vector(std::vector<int> &a,
				      std::vector<int> &b) {
  assert(a.size() == b.size());
  int remainder = 0;
  for (int i = 0; i < a.size(); ++i) {
    a[i] = add_digits(a[i], b[i], remainder);
  }

  if (remainder != 0)
    a.push_back(remainder);
}


int projecteuler::BigInt::add_digits(int a, int b, int &remainder) {
  int total = a + b + remainder;
  int ret = total % 10;
  remainder = total / 10;
  return ret;
}

projecteuler::BigInt projecteuler::BigInt::karatsuba(projecteuler::BigInt a,
						     projecteuler::BigInt b) {
  match_size_of_digits(a, b);

  if(a.value_.size() < 3) {
    BigInt ret = 0;
    for (BigInt i = 0; i < b; ++i)
      ret += a;

    return ret;
  }

  BigInt a0, a1, b0, b1;

  int middle = split(a, a0, a1);
  split(b, b0, b1);

  BigInt c0 = a0 * b0;
  BigInt c1 = (a0 + a1) * (b0 + b1);
  BigInt c2 = a1 * b1;

  c1 = c1 - c0 - c2;
  preappend(c2, middle * 2);
  preappend(c1, middle);

  return c2 + c1 + c0;
}
