#include <bits/stdc++.h>
using namespace std;

//Time Complexity - O(n)

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void zigzag(Node *root) {
    if(!root) return;
    stack<Node *> currLevel;
    stack<Node *> nextLevel;

    bool leftToRight = true;
    currLevel.push(root);

    while (!currLevel.empty()) {
        Node *temp = currLevel.top();
        currLevel.pop();

        if (temp) {
            cout << temp->data << " ";

            // Left -> Right
            if (leftToRight) {
                if (temp->left)
                    nextLevel.push(temp->left);
                if (temp->right)
                    nextLevel.push(temp->right);
            }

            // Right -> Left
            else {
                if (temp->right)
                    nextLevel.push(temp->right);
                if (temp->left)
                    nextLevel.push(temp->left);
            }
        }
        if(currLevel.empty()){
            leftToRight = !leftToRight;
            swap(currLevel, nextLevel);
        }
    }
}

int main() {
    Node *root = new Node(12);
    root->left = new Node(9);
    root->right = new Node(15);
    root->left->left = new Node(5);
    root->left->right = new Node(10);

    zigzag(root);
}