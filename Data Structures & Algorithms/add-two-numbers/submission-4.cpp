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
        ListNode dummy(0);
        ListNode *node = &dummy;

        int carry = 0;
        while (l1 != NULL && l2 != NULL){
            int value = l1->val + l2->val + carry;
            int digit = value % 10;
            carry = value / 10;
            node->next = new ListNode(digit);
            l1 = l1->next;
            l2 = l2->next;
            node = node->next;
        }

        while (l1 != NULL) {
            int value = l1->val + carry;
            int digit = value % 10;
            carry = value / 10;
            node->next = new ListNode(digit);
            l1 = l1->next;
            node = node->next;
        }

        while (l2 != NULL) {
            int value = l2->val + carry;
            int digit = value % 10;
            carry = value / 10;
            node->next = new ListNode(digit);
            l2 = l2->next;
            node = node->next;
        }

        if (carry){
            node->next = new ListNode(1);
        }

        return dummy.next;
    }
};
