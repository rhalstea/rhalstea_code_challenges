#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>

std::vector<int> get_digits(int val)
{
  std::vector<int> ret;
  std::stringstream tmp;
  std::string s;

  tmp << val;
  s = tmp.str();
  for (int i = 0; i < tmp.str().size(); ++i)
    ret.push_back( (int)(s[i] - 48) );

  return ret;
}

int fac(int val)
{
  int ret = 1;
  for (int i = 1; i <= val; ++i)
    ret *= i;

  return ret;
}

int sum_fact_of_digits(int val)
{
  std::vector<int> digits = get_digits(val);

  int sum = 0;
  for (int i = 0; i < digits.size(); ++i)
    sum += fac(digits[i]);

  return sum;
}

bool exists( std::vector<int> &vec, int key)
{
  // vector is unsorted, but won't be longer than 60 elements
  for(int i = 0; i < vec.size(); ++i)
    if (vec[i] == key)
      return true;
  return false;
}

int chain_length(int val)
{
  std::vector<int> chain;
  int curr_val = val;

  do
    {
      chain.push_back(curr_val);
      curr_val = sum_fact_of_digits(curr_val);
    }while( !exists(chain, curr_val) );

  return chain.size();
}

int main()
{
  int count = 0;

  for (int i = 0; i < 1000000; ++i)
    {
      int len = chain_length(i);
      if (len > 59)
	{
	  std::cout << i << ": " << len << std::endl;
	  ++count;
	}
    }

  std::cout << "Answer: " << count << std::endl;

  return 0;
}
