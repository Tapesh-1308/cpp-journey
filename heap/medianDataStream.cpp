#include<bits/stdc++.h>
using namespace std;

// Leetcode-295
class MedianFinder {
public:
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int lsize = maxHeap.size();
        int rsize = minHeap.size();
        if(lsize==0) maxHeap.push(num);

        else if(lsize==rsize){
            if(num<minHeap.top()) maxHeap.push(num);
            else{
                int temp = minHeap.top();
                minHeap.pop();
                minHeap.push(num);
                maxHeap.push(temp);
            }
        }

        else{
            if(minHeap.size()==0){
                if(num>maxHeap.top()) minHeap.push(num);
                else {
                    int temp = maxHeap.top();
                    maxHeap.pop();
                    maxHeap.push(num);
                    minHeap.push(temp);
                }
            }
            else if(num>=minHeap.top())
                minHeap.push(num);
            else {
                if(num<maxHeap.top()){
                    int temp = maxHeap.top();
                    maxHeap.pop();
                    maxHeap.push(num);
                    minHeap.push(temp);
                }
                else minHeap.push(num);
            }
        }
    }
    
     double findMedian() {
        int lsize = maxHeap.size();
        int rsize = minHeap.size();
        if(lsize > rsize)  
            return double(maxHeap.top());
        else   
            return (double(maxHeap.top())+double(minHeap.top()))/2;
    }
};


int main() {
    MedianFinder obj;
    obj.addNum(10);
    cout<<obj.findMedian()<<endl;
    obj.addNum(15);
    cout<<obj.findMedian()<<endl;
    obj.addNum(21);
    cout<<obj.findMedian()<<endl;
    obj.addNum(30);
    cout<<obj.findMedian()<<endl;
    obj.addNum(18);
    cout<<obj.findMedian()<<endl;
    obj.addNum(19);
    cout<<obj.findMedian()<<endl;
    

    return 0;
}