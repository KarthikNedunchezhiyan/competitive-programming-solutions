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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *head = new ListNode(-1);
        ListNode *cursor = head;

        int nextIndex;

        while (true) {
            nextIndex = -1;
            for (int i = 0; i < lists.size(); ++i) {
                if (lists[i] != nullptr && (nextIndex == -1 || lists[i]->val < lists[nextIndex]->val)) {
                    nextIndex = i;
                }
            }

            if (nextIndex != -1) {
                cursor->next = lists[nextIndex];
                lists[nextIndex] = lists[nextIndex]->next;
                cursor = cursor->next;
            } else break;
        }

        return head->next;
    }
};
