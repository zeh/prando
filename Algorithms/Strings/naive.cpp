
// C++ program for Naive Pattern Searching algorithm 

Naive Pattern Searching:
// Slide the pattern over text one by one and check for a match.
//  If a match is found, then slides by 1 again to check for subsequent matches.
#include <iostream> 
#include <string.h> 
using namespace std;
void search(char* pat, char* txt) 
{ 
    int M = strlen(pat); 
    int N = strlen(txt); 
  
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) { 
        int j; 
  
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++) 
            if (txt[i + j] != pat[j]) 
                break; 
  
        if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1] 
            cout<< "Pattern found at index "<<i<<endl; 
    } 
} 
  
/* Driver program to test above function */
int main() 
{ 
    char txt[] = "AABAACAADAABAAABAA"; 
    char pat[] = "AABA"; 
    search(pat, txt); 
    return 0; 
}