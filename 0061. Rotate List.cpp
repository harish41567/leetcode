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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *curr = head;
        int count = 0;
        while (curr->next != NULL)
        {
            count++;
            curr = curr->next;
        }
        count++;
        curr->next = head;
        k = k % count;

        for (int i = 1; i < (count - k); i++)
            head = head->next;

        ListNode *res = head->next;
        head->next = NULL;

        return res;
    }
};