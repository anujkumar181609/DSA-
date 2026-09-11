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

    void inorder(TreeNode* &root, int &ans, int &d, int &k){
        if(root==NULL) return;
       
        inorder(root->left,ans,d,k);
        d++;
        if(d==k) ans=root->val;
        inorder(root->right,ans,d,k);
    }

    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL) return -1;

        int ans=-1,d=0;
      
        inorder(root,ans,d,k);

       

        return ans;
    }
};