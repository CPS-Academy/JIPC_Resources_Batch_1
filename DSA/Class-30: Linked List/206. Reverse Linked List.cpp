LinkedList:


struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

int main()
{
    optimize();
    ListNode* tmp;
    
    ListNode* l1 = new ListNode();
    l1->val = 10;

    ListNode* l3 = new ListNode(30);

    ListNode* l2 = new ListNode(20, l3);
    l1->next = l2;

    ListNode* head = l1;

    while ( head != nullptr ) {
        cout << head->val << " ";
        head = head->next;
    }


    return 0;
}




206. Reverse Linked List




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

    ListNode* reverseList(ListNode* head) {
        ListNode* next = nullptr;
        ListNode* prev = nullptr;

        while ( head != nullptr ) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
       
        return prev;
    }
};



