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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        std::queue <TreeNode*> oneLevel;
        oneLevel.push(root);
        int depth = 0;

        while(!oneLevel.empty()){
            int levelSize = oneLevel.size();

            for (int i = 0; i < levelSize; i++){
                TreeNode *curr = oneLevel.front();
                oneLevel.pop();

                if (curr->left != nullptr){
                    oneLevel.push(curr->left);
                } 
                if (curr->right != nullptr){
                    oneLevel.push(curr->right);
                }
            }
            depth++;
        }
        return depth;
    }
};
