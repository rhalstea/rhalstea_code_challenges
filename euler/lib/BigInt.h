#ifndef __EULER_BIGINT_H__
#define __EULER_BIGINT_H__

#include <vector>
#include <string>

namespace projecteuler {

  class BigInt {
  public:
    BigInt();
    BigInt(int val);
    //BigInt(long val);
    //BigInt(long long val);
    BigInt(std::string val);
    ~BigInt();

    std::string get_value();
    unsigned int number_digits();
    unsigned int size();
    // iostream friend
    // get_digit(int pos)
    // operator[]
    // iterator functions

    bool operator>(BigInt b);
    bool operator<(BigInt b);
    bool operator==(BigInt b);
    bool operator!=(BigInt b);
    bool operator>=(BigInt b);
    bool operator<=(BigInt b);


    BigInt operator+(BigInt b);
    BigInt operator-(BigInt b);
    BigInt operator*(BigInt b);

    void operator++();
    void operator++(int);
    void operator--();
    void operator--(int);
    void operator+=(BigInt b);
    void operator-=(BigInt b);
    void operator*=(BigInt b);

  private:
    std::vector<int> value_;
    bool negative_;

    void set_string(std::string val);
    void complement(std::vector<int> &val);

    int compare(std::vector<int> &left, std::vector<int> &right);
    int split(BigInt &in, BigInt &out0, BigInt &out1);
    bool all_zero(std::vector<int> &val);

    void extend(BigInt &val, int increase);
    void preappend(BigInt &val, int num);
    void match_size_of_digits(BigInt &a, BigInt &b);
    void clean_leading_digits(BigInt &a);

    void add_vector(std::vector<int> &a, std::vector<int> &b);
    int add_digits(int a, int b, int &remainder);

    // multiply only works with positive values
    BigInt karatsuba(BigInt a, BigInt b);
  };

}

#endif
