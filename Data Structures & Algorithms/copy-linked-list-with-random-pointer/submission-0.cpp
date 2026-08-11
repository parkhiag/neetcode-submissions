/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        // first add a copy infront.
        Node* curr = head;

        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // now set random pointers.
        curr = head;

        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        // now separate the list.
        curr = head;
        Node* copyhead = head->next;

        while (curr) {
            Node* copy = curr->next;
            Node* nextOriginal = copy->next;

            // Restore original list
            curr->next = nextOriginal;

            // Connect copied list
            if (nextOriginal) {
                copy->next = nextOriginal->next;
            }

            curr = nextOriginal;
        }

        return copyhead;
    }
};
