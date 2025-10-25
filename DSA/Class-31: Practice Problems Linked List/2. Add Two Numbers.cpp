class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* parent = new ListNode(-1);
        ListNode* prev = parent;
        int carry = 0;

        while ( l1 != nullptr || l2 != nullptr || carry != 0 ) {
            int d1 = (l1 != nullptr) ? l1->val : 0;
            int d2 = (l2 != nullptr) ? l2->val : 0;

            int sum = d1 + d2 + carry;
            prev->next = new ListNode(sum % 10);
            carry = sum / 10;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next  : nullptr;
            prev = prev->next;
        }

        return parent->next;
    }
};
