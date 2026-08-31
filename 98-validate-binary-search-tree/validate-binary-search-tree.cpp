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

    bool find(TreeNode* &root, long long lower, long long upper){
        if(root==NULL) return 1;
        if(root->val <= lower || root->val>= upper) return 0;

        return find(root->left, lower, root->val) && find(root->right, root->val, upper);
    }

    bool isValidBST(TreeNode* root) {
        return find(root,LONG_MIN,LONG_MAX);
    }
};