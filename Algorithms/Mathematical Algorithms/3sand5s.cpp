#include <iostream>
using namespace std;
int main()
{
  int n, sum;

  cout << "Enter N: ";
  cin >> n;

  for(int i = 0; i < n; i++)
  {
    if((i%3 == 0) || (i%5 == 0))
    {
      sum += i;
    }
  }
  cout << "The sum is: " << sum << endl;

  return 0;
}
