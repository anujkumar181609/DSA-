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
        unordered_map<int,int>m;
        queue<pair<TreeNode* , int>>qu;
        qu.push({root,INT_MIN});

        while(!qu.empty()){
            TreeNode* temp= qu.front().first;
            int par= qu.front().second;
            qu.pop();

            m[temp->val]=par;

            if(temp->left) qu.push({temp->left, temp->val});
            if(temp->right) qu.push({temp->right, temp->val});
        }

        unordered_map<int,int>n;
        int val=p->val;

        while(val!=INT_MIN){
            n[val]=1;
            int s= m[val];
            val=s;
        }

        val=q->val;
        while(val!=INT_MIN){
            if(n.count(val)) return new TreeNode(val);

            n[val]=1;
            int s=m[val];
            val=s;
        }
        return NULL;
    }
};