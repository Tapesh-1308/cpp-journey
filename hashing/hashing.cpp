#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;

int main() {
    map<int, int> m;
    m[1] = 2;
    m.insert({3, 4});
    for(auto it:m){
        cout<<it.first<<" "<<it.second<<endl;
    }   
    //For more knowledge about map, unorderd_map and multimap please refer this location in this git repo..
    //template-STL/map.cpp
    return 0;
}