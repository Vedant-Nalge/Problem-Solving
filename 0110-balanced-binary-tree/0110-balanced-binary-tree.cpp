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
    int height(TreeNode* node){
        if(node==NULL) return 0;
        
        int l = height(node->left);
        int r = height(node->right);

        if(l==-1) return -1;
        if (r==-1) return -1;

        if(abs(l-r)>1) return -1;

        return 1 + max(l,r);

    }
    bool isBalanced(TreeNode* root) {
        if (height(root)!=-1) return true;
        else  return false;
        
    }
};