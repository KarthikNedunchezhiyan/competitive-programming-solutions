/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;
        
        ListNode *fast = head, *slow = head;
        do {
            slow = slow->next;
            if (fast->next && fast->next->next) fast = fast->next->next;
            else fast = nullptr;
        } while (fast && slow && fast != slow);

        if (fast && slow && fast == slow) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return fast;
        }

        return nullptr;
    }
};
