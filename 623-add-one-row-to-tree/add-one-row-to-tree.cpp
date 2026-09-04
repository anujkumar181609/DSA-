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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root==NULL) return root;

        queue<TreeNode*>q;
        q.push(root);
        --depth;
        
        if(depth==0){
            TreeNode* temp= new TreeNode(val);
            temp->left= root;
            return temp;
        }

        while(!q.empty()){
            --depth;
            int n=q.size();

            while(n--){
                TreeNode* temp= q.front();
                q.pop();

                if(depth==0){
                    TreeNode* lef= temp->left;
                    TreeNode* rig= temp->right;
                    temp->left= new TreeNode(val);
                    temp->left->left=lef;

                    temp->right= new TreeNode(val);
                    temp->right->right= rig;

                    //return root;
                }

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return root;
    }
};