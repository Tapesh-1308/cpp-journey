#include<bits/stdc++.h>
using namespace std;


class TrieNode {
    public:
    char ch;
    TrieNode* childern[26];
    bool isTerminal;
    
    TrieNode(char data) {
        data = ch;
		for(int i=0; i<26; i++) 
            childern[i] = NULL;
		isTerminal = false;
    }
};
class Trie {
    TrieNode* root;
public:

    /** Initialize your data structure here. */
    Trie() {
		root = new TrieNode('\0');
    }
    
    /** Inserts a word into the trie. */
    void insertUtil(TrieNode* root, string word) {
        //Base Case
        if(word.length()==0) {
            root->isTerminal = true;
            return;
        }

        //Assuming that, word will not be in caps
        int index = word[0] - 'a';

        TrieNode* child;
        if(root->childern[index]) { //If already present
            child = root->childern[index];
        }

        else { // If not present
            child = new TrieNode('\0');
            root->childern[index] = child;
        }

        //Recusrsive call
        insertUtil(child, word.substr(1));
    }
    void insert(string word) {
		insertUtil(root, word);
    }

    /** Returns if the word is in the trie. */
    bool searchUtil(TrieNode* root, string word) {
        //Base Case
        if(word.length()==0) {
            return root->isTerminal;
        }

        //Assuming that, word will not be in caps
        int index = word[0] - 'a';

        TrieNode* child;
        if(root->childern[index]) { //If already present
            child = root->childern[index];
        }

        else { // If not present
            return false;
        }

        //Recusrsive call
        return searchUtil(child, word.substr(1));
    }
    bool search(string word) {
		return searchUtil(root, word);
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWithUtil(TrieNode* root, string word) {
        //Base Case
        if(word.length()==0) {
            return true;
        }

        //Assuming that, word will not be in caps
        int index = word[0] - 'a';

        TrieNode* child;
        if(root->childern[index]) { //If already present
            child = root->childern[index];
        }

        else { // If not present
            return false;
        }

        //Recusrsive call
        return startsWithUtil(child, word.substr(1));
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
		return startsWithUtil(root, prefix);
    }
};


int main(){
    Trie *mytrie = new Trie();
    vector<string> words = {"tapesh", "sakshi"};
    for(auto &w : words) mytrie->insert(w);

    mytrie->search("tapesh") ? cout<<"Found\n" : cout<<"Not Found\n";
    
    mytrie->startsWith("sak") ? cout<<"Found\n" : cout<<"Not Found\n";
    
    // mytrie->deleteNode("tapesh");

    // mytrie->search("tapesh") ? cout<<"Found\n" : cout<<"Not Found\n";
    
    return 0;
}