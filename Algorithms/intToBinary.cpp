#include <iostream>

using namespace std;

int stringToInt(string s) {
    int p = 1;
    int n = 0;
    for(int i = s.size()-1; i >= 0; i --) {
        n += (s[i] - '0') * p;
        p *= 10;
    }
    return n;
}

string intToBinary(int n) {
    string bin = "";
    while(n > 0) {
        bin = (char)((n % 2)+'0') + bin;
        n /= 2;
    }
    return bin;
}

int main(int argc, char** argv) {
    /*cout<<argv[1]<<endl;
    cout<<argc<<endl;
    cout<<stringToInt(argv[1])<<endl;*/
    cout<<intToBinary(stringToInt(argv[1]))<<endl;
    return 0;
}
