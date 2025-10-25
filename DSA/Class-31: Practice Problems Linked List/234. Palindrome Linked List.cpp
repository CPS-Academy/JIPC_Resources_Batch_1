class Solution {
public:

    ListNode* FastAndSlowPointer(ListNode* head) {
        ListNode* fastPointer = head;
        ListNode* slowPointer = head;

        while ( fastPointer->next != nullptr && fastPointer->next->next != nullptr ) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
        }

        return slowPointer;
    }

    ListNode* ReverseLinkedList(ListNode* head) {
        ListNode* prev = nullptr;
        while ( head != nullptr ) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }


    bool isPalindrome(ListNode* head) {
        ListNode* lastNodeOfFirstHalf = FastAndSlowPointer(head);
        ListNode* secondHalfReversed =  ReverseLinkedList(lastNodeOfFirstHalf->next);

        while ( secondHalfReversed != nullptr ) {
            if ( head->val != secondHalfReversed->val ) return false;
            head = head->next;
            secondHalfReversed = secondHalfReversed->next;
        }

        return true;
    }  
};

