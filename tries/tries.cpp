#include<bits/stdc++.h>
using namespace std;

class Trie{
    public:
    class node{
        public:
        bool end;
        node* next[26];
        node(){
            end = false;
            for(int i=0; i<26; i++) next[i] = NULL;
        }
    };

    node* trie;
    Trie() { trie = new node(); }

    void insert(string word){
        int i=0;
        node* it=trie;
        while(i<word.size()){
            if(it->next[word[i] - 'a'] == NULL) 
                it->next[word[i]-'a'] = new node();
            it = it->next[word[i]-'a'];
            i++;
        }
        it->end = true;
    }
    bool search(string word){
        int i=0;
        node* it = trie;
        while(i<word.size()){
            if(it->next[word[i]-'a']==NULL) return false;
            it = it->next[word[i]-'a'];
            i++;
        }
        return it->end;
    }
    void deleteNode(string word){
        if(search(word)) {
            node* it = trie;
            for(int i=0; word[i]!='\0'; ++i) {
                it->next[word[i]-'a']->end -=1; //To Delete all occurance, just make it equal to 0
                it = it->next[word[i]-'a'];
            }
        }
    }
};

int main(){
    Trie *mytrie = new Trie();
    vector<string> words = {"tapesh", "sakshi"};
    for(auto &w : words) mytrie->insert(w);

    mytrie->search("tapesh") ? cout<<"Found\n" : cout<<"Not Found\n";
    
    mytrie->deleteNode("tapesh");

    mytrie->search("tapesh") ? cout<<"Found\n" : cout<<"Not Found\n";
    
    return 0;
}