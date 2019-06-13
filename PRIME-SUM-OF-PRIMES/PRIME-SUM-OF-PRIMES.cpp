#include <iostream>
#include <cmath>

using namespace std;

bool isPrime (int);
bool isDivisible (int, int);
int sumPF (int);

int main ()
{
  int i = 1;
  cout << "These are the numbers below 1000 such that the "
       << "sum of their prime factors "
       << "are also prime!\n";

  while(i < 1000)
  {
    if( isPrime( sumPF(i) ) )
    {
      cout << i << '\n';
    }
    i++;
  }

}

// Expecting input of 2 or larger
bool isPrime (int input)
{
  if ( input == 2 ) {
    return true;
  } else if ( isDivisible(input, 2) ) {
    return false;
  }

  int j = 3;

  while ( j <= sqrt(input) )
  {
    if ( isDivisible(input, j) )
    {
      return false;
    }
    j+=2;
  }
  return true;
}

bool isDivisible (int dividend, int divisor)
{
  if ( dividend % divisor == 0 ) {
    return true;
  } else {
    return false;
  }
}

// Expecting input of 3 or larger
int sumPF (int input)
{
  int k = 2;
  int sum = 0;

  while (k <= input)
  {
    if ( isDivisible(input, k) && isPrime(k) )
    {
      input /= k;
      sum += k;
      k = 2;
      continue;
    }
    k++;
  }
  return sum;
}
