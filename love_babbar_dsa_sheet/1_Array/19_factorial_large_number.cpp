#include <bits/stdc++.h>
using namespace std;

//TC = O(N^2)      SC = O(N)

class Solution {
    int multiply(int x, int ans[], int size){
        int carry = 0;
        for(int i=0; i<size; i++){
            int product = ans[i] * x + carry;
            ans[i] = product%10;
            carry = product/10;
        }
        while(carry){
            ans[size] = carry%10;
            carry /= 10;
            size++;
        }
        return size;
    }
public:
    vector<int> factorial(int n){
        int ans[2568];
        
        ans[0] = 1;
        int size = 1;
        
        for(int x=2; x<=n; x++)
            size = multiply(x, ans, size);
        
        vector<int> fact(size);
        int j=0;
        for(int i=size-1; i>=0; i--) fact[j++] = ans[i];
        
        return fact;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  