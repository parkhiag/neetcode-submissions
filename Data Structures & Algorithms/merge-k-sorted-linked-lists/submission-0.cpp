/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // we will use a min heap to solve this question. 
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // push all the heads into the pq. 
        for (auto head: lists) {
            if (head) pq.push(head);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            temp->next=node;
            temp=temp->next;

            if (node->next) {
                pq.push(node->next);
            }
        }

        return dummy->next;

    }
};
