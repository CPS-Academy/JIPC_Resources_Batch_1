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
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return head;
       
        ListNode* fast = head;
        ListNode* slow = head;
        bool first = true;

        while ( fast != slow || first ) {
            if(fast->next == nullptr || fast->next->next == nullptr) return false;
            slow = slow->next;
            fast = fast->next->next;
            first = false;
        }

        return true;
    }
};
