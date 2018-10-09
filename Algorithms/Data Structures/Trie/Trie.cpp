#include <bits/stdc++.h>
using namespace std;
const int max_char = 26; //maximum number of leafs (lowercase english alphabets only here).
struct trie{
    trie *child[max_char];
    bool leaf;
    // every trie node has a frequency array of every english letters.
    trie(){
        memset(child, 0, sizeof child);
        leaf = 0;
    }
    //inserting new word in trie.
    void insert(char *str){
    	//end of word.
        if (*str == '\0'){
            leaf = 1;
        }else{
        	//ASCII code of current character.
            int cur = *str - 'a';
  			//No word exist with current characters, creating new branch.
            if (!child[cur])
                child[cur] = new trie();
            child[cur]->insert(str + 1);
        }
    }
    //deleting a word in trie.
    void deleteword(char *str){
    	//end of word.
        if (*str == '\0'){
            leaf = 0;
            return;
        }
        else{
        	//ASCII code of current character.
            int cur = *str - 'a';
            //checking next character in word.
            child[cur]->wordquery(str + 1);
            delete child[cur];
        }
    }
    //returns 1 if word exists in trie, 0 otherwise.
    bool wordquery(char *str){
    	//returns wether it exists or not by checking if current node is a leaf node (end of existing word).
        if (*str == '\0')
            return leaf;
        else{
        	//ASCII code of current character.
            int cur = *str - 'a';
            if (!child[cur])
                return false;
            //checking next character in word.
            return child[cur]->wordquery(str + 1);
        }
    }
};
int main(){
	//testing.
    trie root;
    root.insert("abc");
    root.insert("and");
    root.insert("abcdef");
    cout << root.wordquery("abc") << '\n';
    cout << root.wordquery("abcd") << '\n';
    root.deleteword("abc");
    cout << root.wordquery("abc");
    /*
		output should be:
		1
		0
		0
    /*
    return  0;
}