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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur = new ListNode(-1);
        cur->next = head;
        ListNode* prev = cur;
        ListNode* ans = cur;

        while ( cur != nullptr ) {
            if ( cur->val == val ) {
                prev->next = cur->next;
            }
            else prev = cur;

            cur = cur->next;
        }

        return ans->next;
    }
};
