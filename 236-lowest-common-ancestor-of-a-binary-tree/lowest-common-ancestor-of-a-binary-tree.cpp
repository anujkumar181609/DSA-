/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*>m;
        queue<pair<TreeNode* , TreeNode* >>qu;
        qu.push({root,NULL});

        while(!qu.empty()){
            TreeNode* temp= qu.front().first;
            TreeNode* par= qu.front().second;
            qu.pop();

            m[temp]=par;

            if(temp->left) qu.push({temp->left, temp});
            if(temp->right) qu.push({temp->right, temp});
        }

        unordered_map<TreeNode*,int>n;
        TreeNode* val=p;

        while(val!=NULL){
            n[val]=1;
            TreeNode* s= m[val];
            val=s;
        }

        val=q;
        while(val!=NULL){
            if(n.count(val)) return val;

            n[val]=1;
            TreeNode* s=m[val];
            val=s;
        }
        return NULL;
    }
};