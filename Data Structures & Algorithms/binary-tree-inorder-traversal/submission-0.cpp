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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> results;
        helper(root, results);
        return results;
        
    }

    void helper(TreeNode* root, std::vector<int>& results){
        if (root == nullptr){
            return;
        }
        helper(root->left, results);
        results.push_back(root->val);
        helper(root->right, results);


    }
};