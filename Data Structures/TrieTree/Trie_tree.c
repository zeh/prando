#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// Trie structure definition
typedef struct trie
{
    struct trie *arr[26];
    bool isEndofWord;
} trie;
// allocates memory and creates a new node
trie *createNode()
{
    trie *nn = (trie *)malloc(sizeof(trie));
    for (int i = 0; i < 26; i++)
        nn->arr[i] = NULL;
    nn->isEndofWord = false;
    return nn;
}
// insert string inside the trie
void insert(trie *root, char str[])
{
    for (int i = 0; i < strlen(str); i++)
    {
        int j = str[i] - 'a';
        if (root->arr[j])
        {
            root = root->arr[j];
        }
        else
        {
            root->arr[j] = createNode();
            root = root->arr[j];
        }
    }
    root->isEndofWord = true;
}
// search the given string inside the trie data structure
bool search(trie *root, char str[], int index)
{
    if (index == strlen(str))
    {
        if (!root->isEndofWord)
            return false;
        return true;
    }
    int j = str[index] - 'a';
    if (!root->arr[j])
        return false;
    return search(root->arr[j], str, index + 1);
}

/*Checks whether the given string is a prefix of any other string if it is then just 
make isendofword to false and exits else deletes the string*/
bool delete (trie *root, char str[], int index)
{
    if (index == strlen(str))
    {
        if (!root->isEndofWord)
            return false;
        root->isEndofWord = false;
        for (int i = 0; i < 26; i++)
            return false;
        return true;
    }
    int j = str[index] - 'a';
    if (!root->arr[j])
        return false;
    bool var = delete (root, str, index + 1);
    if (var)
    {
        root->arr[j] = NULL;
        if (root->isEndofWord)
            return false;
        else
        {
            int i;
            for (i = 0; i < 26; i++)
                if (root->arr[i])
                    return false;
            return true;
        }
    }
}

int main()
{
    trie *root = createNode();
    insert(root, "hello");
    insert(root, "world");
    int a = search(root, "hello", 0);
    int b = search(root, "word", 0);
    printf("%d %d ", a, b);
    return 0;
}