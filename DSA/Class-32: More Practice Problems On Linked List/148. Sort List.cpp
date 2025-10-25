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
    ListNode* merge ( ListNode* l1, ListNode* l2 ) {
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

        if(l1 != nullptr) prev->next = l1;
        else if (l2 != nullptr) prev->next = l2;

        return parent->next;
    }

    ListNode* getMid ( ListNode* head ) {
        ListNode* fast = head;
        ListNode* slow = head;

        while ( fast->next != nullptr && fast->next->next != nullptr ) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* mergeSort ( ListNode* head ) {
        ListNode* mid = getMid(head);
        if ( mid->next == nullptr ) return head;

        ListNode* next = mid->next;
        mid->next = nullptr;

        ListNode* l1 = mergeSort ( head );
        ListNode* l2 = mergeSort ( next );

        ListNode* res = merge(l1, l2);
        return res;
    }

    ListNode* sortList(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* res = mergeSort(head);
        return res;
    }
};

