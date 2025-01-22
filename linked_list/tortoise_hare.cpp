#include <bits/stdc++.h>
using namespace std;
// tottoise and hare algo to find middle of a linked list
class Node {
public:
    int data;  
    Node* next;     

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node *findMiddle(Node *head) {
    // Initialize the slow & fast pointer to the head.
    Node *slow = head; 
    Node *fast = head; 

    // Traverse the linked list using the Tortoise and Hare algorithm.
    while (fast != NULL && fast->next != NULL) {
        // Move slow one step.
        slow = slow->next; 
        // Move fast two steps.
        fast = fast->next->next; 
    }
    
    // Return the slow pointer which is now at the middle node.
    return slow; 
}


int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Find the middle node
    Node* middleNode = findMiddle(head);
    cout << "The middle node value is: " << middleNode->data << endl;
    return 0;
}
                                
                            