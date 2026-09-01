/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;

        unordered_map<int,vector<Node*>>m;
        queue<Node*>q;
        q.push(root);

        int level=-1;
        while(!q.empty()){
            int n=q.size();
            level++;

            while(n--){
                Node* temp=q.front();
                q.pop();

                m[level].push_back(temp);

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }

        for(int i=0;i<m.size();i++){
            int n= m[i].size();
            for(int j=1;j<n;j++) m[i][j-1]->next=m[i][j];
            m[i][n-1]=NULL;
        }
        return root;
    }
};