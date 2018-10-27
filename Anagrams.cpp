#include <bits/stdc++.h>
using namespace std;

int main() {
	string first, second;
	cout << "Enter String 1: " << endl;
	cin >> first;
	cout << "Enter String 2: " << endl;
	cin >> second;
	sort(first.begin(), first.end());
	sort(second.begin(), second.end());
	if (first == second)
		cout << "Anagrams :)" << endl;
	else
		cout << "Not Anagrams! :(" << endl;
	return 0;
}