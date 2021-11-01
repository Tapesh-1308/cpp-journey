#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

/* Diffrence b/w map and unordered_map is:
1. Inbuilt implementation. {use of hash table}
2. Time Complexity. {IN unordered maps time complexity is O(1)}
3. Valid key datatypes. {hash table is not defined in some of the data types. so we can't use the. like pair<>} */

void display(map<string, int> &map){

    // map<string, int>::iterator itr;

    // This loop time complexity is O(n). 
    for (auto itr = map.begin(); itr != map.end(); itr++) {
        cout << (*itr).first << " " << (*itr).second << "\n";
    }
}

void display(unordered_map<int, string> &uMap){

    for (auto itr = uMap.begin(); itr != uMap.end(); itr++) {
        cout << (*itr).first << " " << (*itr).second << "\n";
    }
}

int main()
{
    // map<string, int> marksMap;
    // marksMap["Tapesh"] = 99; //O(log(n))
    // marksMap["Sakshi"] = 97;
    // marksMap["MenuCard"] = 93;
    // marksMap["Arsh"] = 98;

    // marksMap.insert({{"abcd", 90}, {"xyz", 95}});  //O(log(n))

    // auto it = marksMap.find("abcd"); // O(log(n))
    // if(it == marksMap.end())
    //     cout<<"No value\n";
    // else
    //     cout<<it->first<<" "<<it->second;

    // marksMap.erase("abcd"); // O(log(n))
    // if(it != marksMap.end())
    //     marksMap.erase(it); 

    // marksMap.clear();
    // display(marksMap);
    // return 0;

    /* Question:- Given N strings, print unique strings in lexographical order with their frequency
    N<=10^5
    |S| <= 100 */

    // map<string, int> m;
    // int n;
    // cin>>n;
    // for (int i = 0; i < n; i++) {
    //     string s;
    //     cin>>s;
    //     cout<<"\n\n"<<m[s]<<endl<<endl;
    //     m[s]++;
    // }
    // for (auto pr : m) {
    //     cout<<pr.first<<" "<<pr.second<<endl;
    // }  

    // unordered_map<int, string> uM;
    // uM[1] = "Tapesh";
    // uM[2] = "ihowg";
    // uM[3] = "tthht";
    // uM[4] = "hstht";
    // uM[5] = "thttr";
    // display(uM);
    
    /* Given N strings and Q queries. In each query you are given a string print frequency of that string.
    */

    unordered_map<string, int> m;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) {
        string s;
        cin>>s;
        m[s]++;
    } 
    int q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        cout<<m[s]<<endl;
    }
// 8
// abc
// def
// abc
// ghj
// jkl
// ghj
// ghj
// abc
// 2
// abc
// ghj

    
}
