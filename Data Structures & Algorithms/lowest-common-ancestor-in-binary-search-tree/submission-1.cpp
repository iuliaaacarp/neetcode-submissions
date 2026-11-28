/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val){
            TreeNode *aux = p;
            p = q;
            q = aux;
        }
        if (p->val <= root->val && q->val >= root->val){
            return root;
        }
        TreeNode *curr = root, *parent = root;
        bool ok = false;

        while (!ok) {
            if (p->val == parent->val || q->val == parent->val){
                ok = true;
                return parent;
            }
            if (p->val < parent->val && q->val > parent->val){
                ok = true;
                return parent;
            }
            if (p->val < parent->val && q->val < parent->val){
                parent = parent->left;
            } else if (p->val > parent->val && q->val > parent->val){
                parent = parent->right;
            } 
        }
    }
};
