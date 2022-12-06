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
    ListNode *oddEvenList(ListNode *head) {
        if (!head) return head;

        ListNode *cursor1 = head;
        ListNode *cursor2 = head->next;

        while (cursor2 && cursor2->next) {
            ListNode *odd = cursor2->next;
            cursor2->next = odd->next;
            odd->next = cursor1->next;
            cursor1->next = odd;

            cursor1 = cursor1->next;
            cursor2 = cursor2->next;
        }

        return head;
    }
};
