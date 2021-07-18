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
    bool isPalindrome(ListNode* head) {
    ListNode *curr=head,*prev=NULL,*temp=head,*next;
    int count=0;
    
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    
    for(int i=0;i<count/2;i++)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    
    if(count%2!=0)
        curr=curr->next;
    
    while(curr!=NULL && prev!=NULL)
    {
        if(curr->val!=prev->val)
            return 0;
        
        curr=curr->next;
        prev=prev->next;
    }
    return 1;
        
    }
};