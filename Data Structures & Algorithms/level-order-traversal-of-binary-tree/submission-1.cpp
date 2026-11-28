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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr){
            return result;
        }
        std::queue <TreeNode*> level;
        level.push(root);

        while (!level.empty()){
            vector<int> oneLevel;
            int levelSize = level.size();
            for (int i = 0; i < levelSize; i++){
                TreeNode *curr = level.front();
                oneLevel.push_back(curr->val);
                level.pop();
                
                if (curr->left != nullptr){
                    level.push(curr->left);
                } 
                if (curr->right != nullptr){ 
                    level.push(curr->right);
                }
            }

            result.push_back(oneLevel);
        }
        return result;
    }
};
