#include<bits/stdc++.h> 
using namespace std; 
  
string generateKey(string str, string key) 
{ 
    int x = str.size(); 
  
    for (int i = 0; ; i++) 
    { 
        if (x == i) 
            i = 0; 
        if (key.size() == str.size()) 
            break; 
        key.push_back(key[i]); 
    } 
    return key; 
} 
  
string cipherText(string str, string key) 
{ 
    string cipher_text; 
  
    for (int i = 0; i < str.size(); i++) 
    { 
        int x = (str[i] + key[i]) %26; 
  
        x += 'A'; 
  
        cipher_text.push_back(x); 
    } 
    return cipher_text; 
} 
  

string originalText(string cipher_text, string key) 
{ 
    string orig_text; 
  
    for (int i = 0 ; i < cipher_text.size(); i++) 
    { 
        int x = (cipher_text[i] - key[i] + 26) %26; 
  
        x += 'A'; 
        orig_text.push_back(x); 
    } 
    return orig_text; 
} 
  
// Driver program 
int main() 
{ 
    string str = "GEEKSFORGEEKS"; 
    string keyword = "AYUSH"; 
  
    string key = generateKey(str, keyword); 
    string cipher_text = cipherText(str, key); 
  
    cout << "Ciphertext : "
         << cipher_text << "\n"; 
  
    cout << "Original/Decrypted Text : "
         << originalText
(cipher_text, key); 
    return 0; 
} 

