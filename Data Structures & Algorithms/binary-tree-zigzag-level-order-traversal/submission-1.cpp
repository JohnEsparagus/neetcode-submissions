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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //easy bfs

        //we need to remember
        // Node  val and yh...
        if (!root) return {};
        queue<TreeNode*> qu;
        
        vector<vector<int>> out;
        qu.push(root);
        int level = 0;
        vector<int> sub;
        while (!qu.empty()){

            int size = qu.size();
            vector<int> sub(size);

            for (int i = 0; i < size; i++) {
                TreeNode* curr = qu.front(); qu.pop();
                if (curr->left != nullptr) {qu.push(curr->left);}
                if (curr->right != nullptr) {qu.push(curr->right);}
                int index = (level % 2 == 0) ? i : size - 1 - i;
                sub[index] = curr->val;
            }
            out.push_back(sub);
            level++;

        }
        return out;
    }
};