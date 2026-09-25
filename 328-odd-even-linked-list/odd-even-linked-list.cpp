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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        ListNode* curr1=head, *curr2=head->next, *curr=head, *root=curr2;

        int n=0;
        while(curr){
            curr=curr->next;
            n++;
        }
        curr=curr2->next;
        head=curr1;

        for(int i=3;i<=n;i++){
            if(curr==NULL) break;
            if(i%2==1) {
                curr1->next= new ListNode(curr->val);
                curr1=curr1->next;
            }
            else{
                curr2->next= new ListNode(curr->val);
                curr2=curr2->next;
            }
            curr=curr->next;
        }
        curr2->next=NULL;
        curr1->next=root;
        return head;
    }
};