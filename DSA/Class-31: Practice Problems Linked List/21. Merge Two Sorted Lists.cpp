class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* parent = new ListNode(-1);
        ListNode* prev = parent;

        while ( l1 != nullptr && l2 != nullptr ) {
            if ( l1->val <= l2->val ) {
                prev->next = l1;
                l1 = l1->next;
            }
            else {
                prev->next = l2;
                l2 = l2->next;
            }

            prev = prev->next;
        }

        if(l1 != nullptr) {
            prev->next = l1;
        }
        else if (l2 != nullptr) {
            prev->next = l2;
        }

        return parent->next;
    }
};
