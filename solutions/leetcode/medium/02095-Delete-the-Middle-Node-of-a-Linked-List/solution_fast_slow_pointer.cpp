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
    ListNode *deleteMiddle(ListNode *slow, ListNode *fast) {
        if (fast && fast->next)
            slow->next = deleteMiddle(slow->next, fast->next->next);
        else return slow->next;
        return slow;
    }

public:
    ListNode *deleteMiddle(ListNode *head) {
        return (!head->next) ? nullptr : deleteMiddle(head, head);
    }
};
