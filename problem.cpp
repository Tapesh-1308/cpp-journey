#include<bits/stdc++.h>
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  if(sequence.size()>array.size()) return false;
	int i=0, j=0;
	while(j<sequence.size() && i<array.size()){
		if(sequence[j]==array[i]){
			j++;
			i++;
		}
		else i++;
	}
	return j==sequence.size();
}

int main(){
    vector<int> arr = {5,1,22,25,6,-1,8,10};
    vector<int> sequence = {1,6,-1,10};
    if(isValidSubsequence(arr, sequence)) cout<<"True";
    else cout<<"False";
}