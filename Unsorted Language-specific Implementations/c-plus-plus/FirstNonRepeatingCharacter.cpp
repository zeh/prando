#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cout << "Enter String: " << endl;
	cin >> s;
	int i, sz, map[255];
	sz = s.size();
	memset(map, 0, sizeof map);
	for (i = 0; i < sz; i++) {
		map[s[i]]++;
	}
	for (i = 0; i < sz; i++) {
		if (map[s[i]] == 1) {
			cout << "The first non-repeating character is : " << s[i] << endl;
			break;
		}
	}
	if (i == sz)
		cout << "No non-repeating character found :(" << endl;
	return 0;
}

