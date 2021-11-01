#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

void display(set<string> &s) {
    for (string value : s) {
        cout << value << endl;
    }
    // for (auto it = s.begin(); it != s.end(); it++) {
    //     cout << *it << endl;
    // }
}
void display(unordered_set<string> &s) {
    for (string value : s) {
        cout << value << endl;
    }
}

void display(multiset<string> &s) {
    for (string value : s) {
        cout << value << endl;
    }
}

int main()
{
    /* //Set
    set<string> s;
    s.insert("abc"); // log(n)
    s.insert("def");
    s.insert("ghi");
    s.insert("def");

    auto it = s.find("ghi"); // log(n)
    if(it != s.end()){
        // cout<< *it <<endl;
        s.erase(it);
    }
    s.erase("abc");

    display(s); */

    /* // Question - print unqiue strings in lexiographical order
    set<string> s;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) {   
        string st;
        cin>>st;
        s.insert(st);
    }
    for (auto i : s) {
        cout<<i<<endl;
    } */

    /* //Unordered Set - uses hash table, so we can't use some datatypes like pair
    unordered_set<string> s;
    s.insert("abc"); // O(1)
    s.insert("def");
    s.insert("ghi");
    s.insert("def");

    auto it = s.find("ghi"); // O(1)
    if(it != s.end()){
        // cout<< *it <<endl;
        s.erase(it);
    }
    s.erase("abc");

    display(s); */

    /* // Question - in each query you are given a string print yes if string is present or not

    unordered_set<string> us;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) {   
        string st;
        cin>>st;
        us.insert(st);
    }
    int q;
    cin>>q;
    while(q--){
        string str;
        cin>>str;
        if(us.find(str) == us.end())
            cout<<"no\n";
        else cout<<"Yes\n";
    } */
    
    /* // Multset
    multiset<string> s;
    s.insert("abc"); // log(n)
    s.insert("def");
    s.insert("ghi");
    s.insert("def");

    // 1st index of duplicate element will be encountered
    // auto it = s.find("def"); // log(n)
    // if(it != s.end()){
    //     // cout<< *it <<endl;
    //     s.erase(it);
    // }

    // But in this way all duplicate element will erase.
    s.erase("def");
  
    display(s); */

    return 0;
}