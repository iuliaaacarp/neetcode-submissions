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
        unordered_map<Node*, Node*> hashMap;
        hashMap[NULL] = NULL;

        Node *curr = head;
        while (curr != NULL) {
            Node *copyNode = new Node(curr->val);
            hashMap[curr] = copyNode;
            curr = curr->next;
        }

        curr = head;
        while (curr != NULL){
            Node *copy = hashMap[curr];
            copy->next = hashMap[curr->next];
            copy->random = hashMap[curr->random];
            curr = curr->next;
        }

        return hashMap[head];
    }
};
