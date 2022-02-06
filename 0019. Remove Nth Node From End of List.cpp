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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head, *fast = head;

        while (n > 0)
        {
            fast = fast->next;
            n--;
        }

        if (fast == NULL)
        {
            ListNode *node = head;
            head = head->next;
            delete node;
            return head;
        }

        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *node = slow->next;
        slow->next = node->next;
        delete node;

        return head;
    }
};