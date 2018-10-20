#include <iostream>
using namespace std;

// LPS stands for Longest Palindromic Subsequence
int lps(string s, int left, int right) {
	if (left == right)
		return 1;
		
	if (s[left] == s[right] && left + 1 == right)
		return 2;
		
	if (s[left] == s[right])
		return 2 + lps(s, left + 1, right - 1);
	
	return max(lps(s, left + 1, right), lps(s, left, right - 1));
}

int main() {
	string s;
	cout << "Enter String: " << endl;
	cin >> s;
	cout << "Max length of Longest Palindromic Subsequence is: " << lps(s, 0, s.size()-1) << endl;
	return 0;
}

