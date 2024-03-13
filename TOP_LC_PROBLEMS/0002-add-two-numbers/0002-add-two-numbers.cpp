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
        int carry = 0;
        ListNode* head = new ListNode();
        ListNode* l3 = head;

        while(l1 != NULL || l2 != NULL || carry) {
            int l1Val = 0, l2Val = 0;
            if(l1 != NULL) {
                l1Val = l1 -> val;
                l1 = l1 -> next;
            }
            if(l2 != NULL) {
                l2Val = l2 -> val;
                l2 = l2 -> next;
            }

            int sum = l1Val + l2Val + carry;
            carry = sum / 10;

            ListNode* temp = new ListNode(sum % 10);
            l3 -> next = temp;
            l3 = l3 -> next;
        }

 
        return head -> next;
    }
};