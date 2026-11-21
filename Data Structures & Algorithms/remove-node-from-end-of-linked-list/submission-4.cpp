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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int countNodes = 0;
        ListNode *curr = head;

        while (curr){
            countNodes++;
            curr = curr->next;
        }

        int toRemove = countNodes - n + 1;
        int index = 1;

        if (countNodes == 1) {
            head = nullptr;
            return head;
        }

        if (toRemove == 1) {
            head = head->next;
        }

        ListNode *prev = head;
        curr = prev->next;

        while (index != toRemove && curr != nullptr){
            index++;
            if (index == toRemove){
                prev->next = curr->next;
                curr = nullptr;
            } else {
                prev = prev->next;
                curr = curr->next;
            }
        }

        return head;
    }
};