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
    ListNode* getMid (ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while ( fast->next != nullptr && fast->next->next != nullptr ) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* deleteMiddle(ListNode* head) {
        ListNode* parent = new ListNode(-1);
        parent->next = head;
        ListNode* mid = getMid(parent);
        mid->next = mid->next->next;
        return parent->next;
    }
};
