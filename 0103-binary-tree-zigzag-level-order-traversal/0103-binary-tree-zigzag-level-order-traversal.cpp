/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return {};
        queue<TreeNode*> q;
        q.push(root);

        bool lr = true;

        while (!q.empty()) {
           
            int n = q.size();
             vector<int> lvl(n);
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                int ind;

                if (lr)
                    ind = i;
                else
                    ind = n - i - 1;

                lvl[ind] = node->val;

                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }

            ans.push_back(lvl);
            lr = !lr;
        }
        return ans;
    }
};