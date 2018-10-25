 #include <iostream>
 #include <cmath>

 using namespace std;

void printBinary(int n);

 int main()
 {
    printBinary(1);
    printBinary(2);
    printBinary(4);
    printBinary(8);
    printBinary(16);
    printBinary(32);
    return 0;
 }

void printBinary(int n)
{
    for(int i = 7; i >= 0; i--)
    {
        if(n >= pow(2, i))
        {
            n = n - pow(2,i);
            cout << '1';
        }
        else
        {
            cout << '0';
        }
    }
    cout << endl;
}
