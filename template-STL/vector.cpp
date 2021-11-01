#include <iostream>
#include <vector>
using namespace std;

void display(vector<char> &v)
{
    cout<<"Displaying vector: "<<endl;

    //v.size() //O(1);
    //1st method
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    //     // cout << v.at(i) << " ";
    // }
    // cout << endl;

    //2nd method
    // vector<int>::iterator it;
    // for (it=v.begin(); it!= v.end(); it++)
    // {
    //     cout<<*it<<" ";
    // }
    // cout<<endl;
    // (*it.first) <=> (it->first)

    //2nd b method
    for (auto it=v.begin(); it!= v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    // (*it.first) <=> (it->first)
    
    //3rd method 
    // for (auto element : v)
    // {
    //     cout<<element<<" ";
    // }
    // cout<<endl;

    //4th method
    for(char value : v){
        cout<<value<<endl;
    }
}

void display2(vector<pair<int, int>> &v){
    cout<<v.size()<<endl;
    for (int i = 0; i < v.size(); i++) {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    
}

int main()
{
    // Ways to create vector
    // vector<int> v1; // 0 length integer vector 
    vector<char> v2(4); // 4-element character vector 
    v2.push_back('5'); // O(1)

    // vector<char> v3(v2); // 4-element character vector from v2

    // vector<int> v4(6, 3); // 6-element vector of 3s
    // vector<int> v5(7, 23); // 7-element vector of 23s

    display(v2);
    // display(v4);
    // display(v5);

    // swap(v4, v5);
    
    // display(v4);
    // display(v5);



    // int element, size;
    // cout << "Enter the size of your vector : ";
    // cin >> size;
    // for (int i = 0; i < size; i++)
    // {
    //     cout << "Enter number : ";
    //     cin >> element;
    //     v1.push_back(element); // Add element in the last
    // }

    // v1.pop_back(); // Remove last element

    // vector<int>::iterator it = v1.begin();

    // v.insert(it+1, 34); // Insert an element (i+1) <- for insert element on 2nd position
    // v.insert(it + 1, 5, 34); // It will add 5 copies of 34 at 2nd position

    // display(v1);

    // vector<pair<int, int>> vecPair = {{1, 2}, {3, 4}, {5, 6}};
    
    // display2(vecPair);
    

    return 0;
}