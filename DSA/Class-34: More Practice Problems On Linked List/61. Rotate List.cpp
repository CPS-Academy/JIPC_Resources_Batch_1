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
    ListNode* rotateRight(ListNode* head, int k) {
        if(n==0 || n==1) return head;
        ListNode* temp = head;
        ListNode* tail;
        int n = 0;

        while ( temp != nullptr ) {
            tail = temp;
            temp = temp->next;
            n++;
        }

        k %= n;
        if(k == 0) return head;

        ListNode* newHead = new ListNode(-1);;
        newHead->next = head;
        for ( int i = 0; i < n-k; i++ ) {
            newHead = newHead->next;
        }
       
        tail->next = head;

        ListNode* ans = newHead->next;
        newHead->next = nullptr;
        return ans;
    }
};
