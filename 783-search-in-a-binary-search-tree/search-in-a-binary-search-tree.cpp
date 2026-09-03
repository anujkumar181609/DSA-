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

    TreeNode* inorder(TreeNode* &root, int &val){
        if(root==NULL) return NULL;

        if(root->val > val) return inorder(root->left,val);
        else if(root->val < val) return inorder(root->right,val);
        else return root;

    }
    TreeNode* searchBST(TreeNode* root, int val) {
        
        return inorder(root, val);
      
    }
};