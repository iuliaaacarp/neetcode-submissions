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

#include <cmath>

class Solution {
public:
    int maxDepth(TreeNode *root){
        if (root == nullptr){
            return 0;
        }
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr){
            return true;
        }

        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);

        bool balancedLeft = isBalanced(root->left);
        bool balancedRight = isBalanced(root->right);

        return (abs(maxLeft - maxRight) <= 1) && balancedLeft && balancedRight;
    }
};
