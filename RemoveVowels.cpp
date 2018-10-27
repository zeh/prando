#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	string check, vowels, ans;
	int i, j;
	vowels = "aeiou";
	ans = "";
	cin >> check;
	transform(check.begin(), check.end(), check.begin(), ::tolower);
	for (i = 0; i < check.size(); i++) {
		for (j = 0; j < vowels.size(); j++) {
			if (check[i] == vowels[j])
				break;
		}
		if(j == vowels.size())
			ans += check[i];
	}
	cout << "String without vowels: " << ans << endl;
	return 0;
}