#include <iostream>
#include <string>

using namespace std;

// Pass the string who's lexigraphic rank we want to find as a parameter
// to the constructor
class LexicographicRank {
		string str;
		int rank;
		int factorial(int n);
	public:
		LexicographicRank(string str) {
			this->str = str;
			rank = 1;
		}
		int getRank();
};

// utilty function to compute the factorial of a number
int LexicographicRank::factorial(int n) {
	int fac = 1;
	for(int i=n; i>1; i--)
		fac *= i;
	return fac;
}

// computes rank
int LexicographicRank::getRank() {
	for ( int i=0; i<str.length() ; i++ ) {
		int mulFactor = factorial(str.length()-(i+1));
		for( int j=i+1; j<str.length() ; j++ ) {
			if(str[i]>str[j]) rank += mulFactor;

		}
	}
	return rank;
}
int main() {
	string str;
	cout<<"Enter string: ";

	getline(cin,str);
	LexicographicRank *lr = new LexicographicRank(str);

	cout<<"Rank: "<<lr->getRank()<<endl;
}
