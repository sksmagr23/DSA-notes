#include <bits/stdc++.h>
using namespace std;

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

// function to detect loop in linked list using hashmap
bool detectLoop(Node* head) {
    Node* temp = head;  
    // Create a map to keep track of encountered nodes
    unordered_map<Node*, int> mpp;  

    while (temp != nullptr) {
        // If the node is already in the map, there is a loop
        if (mpp.find(temp) != mpp.end()) {
            return true;
        }
        // Store the current node in the map
        mpp[temp] = 1;
        temp = temp->next;  
    }
    return false;
}

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    // Create a loop
    fifth->next = third; 

    if (detectLoop(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    // Clean up memory (free the allocated nodes)
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}