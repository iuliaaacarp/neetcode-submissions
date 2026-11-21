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
    void reorderList(ListNode* head) {
        int nodeCounter = 0;
        ListNode *curr = head;

        while (curr){
            nodeCounter++;
            curr = curr->next;
        }

        ListNode *nextUp = head;
        for (int i = 0; i < (nodeCounter - 1)/2; i++){
            ListNode *current = nextUp;
            while (current->next->next != NULL){
                current = current->next;
            }
            ListNode *tail = current->next;
            current->next = NULL;
            ListNode *temp = nextUp->next;
            nextUp->next = tail;
            tail->next = temp;
            nextUp = temp;
        }
    }
};
