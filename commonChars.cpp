#include<iostream>
#include<string>

using namespace std;

int commonChars(string line1, string line2, char * charArray);
void sort(char * charArray, int size);
void printArray(char * charArray, int size);

void printArray(char * charArray, int size) {
	for (int i = 0; i < size; i++) {
		cout << charArray[i];
	}
}
int commonChars(string line1, string line2, char * charArray) {
	string returnString = "";
	bool flag = true;
	int counter = 0;
	for (int i = 0; i < line1.length(); i++) {
		for (int j = 0; j < line2.length(); j++) {
			if (line1.at(i) == line2.at(j)) {
				for (int k = 0; k < counter; k++) {
					if (charArray[k] == line1.at(i))
						flag = false;
				}
				if (flag) {
					charArray[counter] = line1.at(i);
					counter++;
				}
				flag = true;
			}
		}
	}
	return counter;
}
void sort(char * charArray, int size) {

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (charArray[i] > charArray[j]) {
				char temp = charArray[i];
				charArray[i] = charArray[j];
				charArray[j] = temp;
			}
		}
	}
}
int main() {
	string text1, text2;
	string stringToSort = "";
	int largerSize = text1.length();

	if (text2.length() > largerSize)
		largerSize = text2.length();

	char * characters = new char[largerSize];

	cin >> text1;
	cin >> text2;

	int size = 0;
	size = commonChars(text1, text2, characters);
	sort(characters, size);
	printArray(characters, size);

	cout << endl;
	system("pause");
	return 0;
}