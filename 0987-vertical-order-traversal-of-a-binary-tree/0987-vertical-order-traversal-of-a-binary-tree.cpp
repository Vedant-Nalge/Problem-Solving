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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;  // v,l,n
        queue<pair<TreeNode*, pair<int, int>>> q; // n,v,l

        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto n = q.front().first;
            auto v = q.front().second.first;
            auto l = q.front().second.second;
            q.pop();

            nodes[v][l].insert(n->val);

            if (n->left)
                q.push({n->left, {v - 1, l + 1}});
            if (n->right)
                q.push({n->right, {v + 1, l + 1}});
        }

        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};