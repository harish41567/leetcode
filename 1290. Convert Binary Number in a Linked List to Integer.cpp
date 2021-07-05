class Solution {
public:
    int getDecimalValue(ListNode* head) {
        
        ListNode* temp=head;
        int count=0,j=0;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        
        for(int i=count-1;i>=0;i--)
        {
            j+=(head->val)*pow(2,i);
            head=head->next;
        }
        return j;
            
    }
};