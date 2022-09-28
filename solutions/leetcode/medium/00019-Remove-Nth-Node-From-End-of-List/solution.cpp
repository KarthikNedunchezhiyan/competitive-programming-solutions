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
    int remove(ListNode *head, ListNode *prev, int n) {
        if (head == nullptr) return 1;

        int indexFromLast = remove(head->next, head, n);
        if (indexFromLast == n) prev->next = head->next;
        return indexFromLast + 1;
    }

public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        return remove(head, head, n) != n + 1 ? head : head->next;
    }
};
