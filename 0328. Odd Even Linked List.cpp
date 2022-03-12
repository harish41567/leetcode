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
        if (!head)
            return NULL;

        ListNode *oddStart = NULL, *oddEnd = NULL, *evenStart = NULL, *evenEnd = NULL;
        ListNode* curr = head;
        int cnt = 1;
        while (curr != NULL)
        {
            if (cnt % 2 == 1)
            {
                if (oddStart == NULL)
                {
                    oddStart = curr;
                    oddEnd = curr;
                }
                else
                {
                    oddEnd->next = curr;
                    oddEnd = curr;
                }
            }
            else
            {
                if (evenStart == NULL)
                {
                    evenStart = curr;
                    evenEnd = curr;
                }
                else
                {
                    evenEnd->next = curr;
                    evenEnd = curr;
                }
            }
            cnt++;
            curr = curr->next;
        }

        if (!oddStart)
            return evenStart;
        if (!evenStart)
            return oddStart;

        oddEnd->next = evenStart;
        evenEnd->next = NULL;

        return oddStart;
    }
};
