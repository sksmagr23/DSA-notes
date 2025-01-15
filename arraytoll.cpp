#include <bits/stdc++.h>
using namespace std;

// ARRAY TO LINKED-LIST
class Node {
  public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};


class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        Node* head = new Node(arr[0]);
        Node* mover = head;
        for (int i=1; i<arr.size(); i++){
            mover->next = new Node(arr[i]);
            mover = mover->next;
        }
        return head;
    }
};
