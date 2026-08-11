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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (l1 || l2) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1=l1->next;
            }
            if (l2) {
                sum+= l2->val;
                l2=l2->next;
            }
            
            ListNode* num = new ListNode(sum);
            curr->next=num;
            if (sum/10==1) {
                carry=1;
                num->val=sum%10;
            }
            else carry=0;
            curr=curr->next;
        }
        if (carry==1) {
            ListNode* node = new ListNode(1);
            curr->next=node;
        }
        return dummy->next;
    }
};
