class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if (root == NULL)
            return 0;

        int ans = 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {

            int size = q.size();

            long long mini = q.front().second;

            long long f = 0;
            long long l = 0;

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front().first;

                long long curr = q.front().second - mini;

                q.pop();

                if (i == 0)
                    f = curr;

                if (i == size - 1)
                    l = curr;

                if (node->left)
                    q.push({node->left, 2 * curr + 1});

                if (node->right)
                    q.push({node->right, 2 * curr + 2});
            }

            ans = max(ans, (int)(l - f + 1));
        }

        return ans;
    }
};