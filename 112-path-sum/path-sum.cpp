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

    void find(TreeNode* &root, int sum , int &n, int &flag){
        if(root==NULL) return;

        sum+=root->val;
        if(root->left==NULL && root->right==NULL){
            if(sum==n){
                flag=1;
                return;
            }
        }
   
        find(root->left, sum,n,flag);
        find(root->right, sum,n,flag);
        
        
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if( root==NULL) return 0;

        int flag=0;
        find(root,0, targetSum,flag);
        return flag==1;
    }
};