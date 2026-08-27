class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        int carry = 0;

        // Both lists have elements
        while (l1 != NULL && l2 != NULL)
        {
            int ans = l1->val + l2->val + carry;

            curr->next = new ListNode(ans % 10);
            curr = curr->next;

            carry = ans / 10;

            l1 = l1->next;
            l2 = l2->next;
        }

        // Only l1 has elements
        while (l1 != NULL)
        {
            int ans = l1->val + carry;

            curr->next = new ListNode(ans % 10);
            curr = curr->next;

            carry = ans / 10;

            l1 = l1->next;
        }

        // Only l2 has elements
        while (l2 != NULL)
        {
            int ans = l2->val + carry;

            curr->next = new ListNode(ans % 10);
            curr = curr->next;

            carry = ans / 10;

            l2 = l2->next;
        }

        // Remaining carry
        if (carry)
        {
            curr->next = new ListNode(carry);
        }

        return dummy->next;
    }
};