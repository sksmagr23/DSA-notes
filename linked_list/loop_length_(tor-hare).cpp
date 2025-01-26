#include<bits/stdc++.h>
using namespace std;

int main() {
    return 0;
}

int countNodesinLoop(Node *head) {
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if (slow==fast){
                int count = 1;
                fast = fast->next;
                while (slow!=fast){
                    count++;
                    fast =fast->next;
                }
                return count;
            }
        }
        return 0;
    }