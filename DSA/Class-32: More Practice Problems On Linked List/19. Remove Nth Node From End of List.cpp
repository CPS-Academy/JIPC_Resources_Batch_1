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
        ListNode* parent = new ListNode(-1);
        parent->next = head;
        ListNode* prev = parent;
        ListNode* slow = parent;
        ListNode* fast = parent;

        for ( int i = 1; i <= n+1; i++ ) {
            fast = fast->next;
        }

        while ( fast != nullptr ) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return parent->next;
    }
};
