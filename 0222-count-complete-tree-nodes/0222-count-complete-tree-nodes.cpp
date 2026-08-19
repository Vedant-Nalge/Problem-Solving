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
    int l(TreeNode* node) {
        int l=0;
            while(node){
                l++;
                node =(node->left);

            }
            return l;
        
    }

     int r(TreeNode* node) {
        int h=0;
            while(node){
                h++;
                node =(node->right);

            }
            return h;
        
    }

    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        
        int lh = l(root);
        int rh = r(root);
        if(lh==rh) return (pow(2,lh)-1);
        else;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};