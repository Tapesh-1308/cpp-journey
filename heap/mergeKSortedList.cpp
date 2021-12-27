#include<bits/stdc++.h>
using namespace std;

//leetcode-23

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int value)
    {
        val = value;
        next = NULL;
    }
};

//Divide and conqour algorithm Time Complexity(Nlogk)
/*
class Solution {
    ListNode* merge(vector<ListNode*>& lists, int left, int right) {
        if(left==right) return lists[left];
        int k = right-left+1;
        ListNode *head, *h1, *h2, *ptr;
        head = h1 = h2 = NULL;
        h1 = merge(lists, left, left+k/2-1);
        h2 = merge(lists, left+k/2, right);
        //Merge h1 and h2
        if(!h1 and !h2) return head;
        else if(!h1) return h2;
        else if(!h2) return h1;

        if(!h1 or (h1 and h1->val>h2->val))
        {    head = h2;    h2=h2->next; } 
        else
        {   head = h1;    h1=h1->next; }
        ptr=head;
        while(h1 or h2){
            if(!h1)
            {   ptr->next = h2;    h2 = h2->next;    ptr = ptr->next;   }

            else if(!h2)
            {   ptr->next = h1;    h1 = h1->next;    ptr = ptr->next;   }

            else if(h1->val<h2->val)
            {   ptr->next = h1;    h1 = h1->next;    ptr = ptr->next;   } 

            else
            {   ptr->next = h2;    h2 = h2->next;    ptr = ptr->next;   }
        }
        return head;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0) return NULL;
        else if(k==1) return lists[0];
        ListNode *head, *h1, *h2, *ptr;
        head = h1 = h2 = NULL;
        h1 = merge(lists, 0, k/2);
        if(k/2+1<=k-1)
            h2 = merge(lists, k/2+1, k-1);

        //Merge h1 and h2
        if(!h1 and !h2) return head;
        else if(!h1) return h2;
        else if(!h2) return h1;

        if(!h1 or (h1 and h1->val>h2->val))
        {    head = h2;    h2=h2->next; } 
        else
        {   head = h1;    h1=h1->next; }
        ptr=head;
        while(h1 or h2){
            if(!h1)
            {   ptr->next = h2;    h2 = h2->next;    ptr = ptr->next;   }

            else if(!h2)
            {   ptr->next = h1;    h1 = h1->next;    ptr = ptr->next;   }

            else if(h1->val<h2->val)
            {   ptr->next = h1;    h1 = h1->next;    ptr = ptr->next;   } 

            else
            {   ptr->next = h2;    h2 = h2->next;    ptr = ptr->next;   }
        }
        return head;
    }
}; */

//Heap algorithm Time Complexity(Nlogk)
class Solution{
    struct node{
        ListNode* curr;
        int idx;
        node(ListNode *a, int b) {
            curr = a;
            idx = b;
        }
    };

    struct compare{
        bool operator()(node a, node b){
            return a.curr->val>b.curr->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0) return NULL;
        ListNode *head, *tail;
        head = tail = NULL;
        priority_queue<node, vector<node>,compare> heap;
        vector<ListNode*> ptr(k);
        for(int i=0; i<k; i++){
            ptr[i] = lists[i];
            if(ptr[i]){
                heap.push(node(ptr[i], i));
            }
        }
        if(heap.empty()) return NULL;
        head = tail = heap.top().curr;
        int idx = heap.top().idx;
        heap.pop();
        ptr[idx]=ptr[idx]->next;
        if(ptr[idx])
            heap.push(node(ptr[idx], idx));
        while(!heap.empty()){
            ListNode *temp= heap.top().curr;
            idx=heap.top().idx;
            heap.pop();

            tail->next = temp;
            tail=tail->next;
            ptr[idx]=ptr[idx]->next;
            if(ptr[idx]) heap.push(node(ptr[idx], idx));
        }
        return head;
    }
};
void insertAtTail(ListNode *&head, int val)
{
    ListNode *n = new ListNode(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void display(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main() {
    ListNode* l1 = NULL;
    insertAtTail(l1, 10);
    insertAtTail(l1, 40);
    insertAtTail(l1, 50);
    display(l1);

    ListNode* l2 = NULL;
    insertAtTail(l2, 10);
    insertAtTail(l2, 30);
    insertAtTail(l2, 40);
    display(l2);

    ListNode* l3 = NULL;
    insertAtTail(l3, 20);
    insertAtTail(l3, 70);
    display(l3);

    vector<ListNode*> lists = {l1, l2, l3};
    Solution obj;
    ListNode* l4 = obj.mergeKLists(lists);
    display(l4);
    return 0;
}