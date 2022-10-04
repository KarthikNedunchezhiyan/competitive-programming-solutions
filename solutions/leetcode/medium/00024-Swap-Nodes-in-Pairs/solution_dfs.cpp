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
private:
    ListNode *f(ListNode *head, int level) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *node = f(head->next, level + 1);
        if (level % 2) {
            head->next = node->next;
            node->next = head;
            return node;
        }
        
        head->next = node;
        return head;
    }

public:
    ListNode *swapPairs(ListNode *head) {
        return f(head, 1);
    }
};
