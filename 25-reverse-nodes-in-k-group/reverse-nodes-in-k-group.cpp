/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int>ans;
        ListNode *curr=head;
        
        while(curr){
            ans.push_back(curr->val);
            curr=curr->next;
        }
        curr=head;
        
        int i=0;
        while(i+k<=ans.size()){
            reverse(ans.begin()+i, ans.begin()+i+k);
            i+=k;
        }
        //reverse(ans.begin()+i, ans.end());
        
        for(int i=0;i<ans.size();i++){
            curr->val= ans[i];
            curr= curr->next;
        }
        return head;
    }
};