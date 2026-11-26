#include <unordered_map>

class Node {
public:
    int key;
    int val;
    Node *prev;
    Node *next;

    Node (int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    int capacity;
    unordered_map <int, Node*> cache;
    Node *left;
    Node *right;

    void remove(Node *node){
        Node *temp1 = node->prev;
        Node *temp2 = node->next;
        temp1->next = temp2;
        temp2->prev = temp1;
    }

    void insert(Node *node){
        Node *prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }

    LRUCache(int capacity) : capacity(capacity) {
        cache.clear();
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()){
            Node *node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()){
            remove(cache[key]);
        }
        Node *newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        if (cache.size() > capacity){
            Node *toRemove = left->next;
            remove(toRemove);
            cache.erase(toRemove->key);
            delete toRemove;
        }
    }
};
