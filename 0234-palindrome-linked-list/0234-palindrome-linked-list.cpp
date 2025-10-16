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
    bool isPalindrome(ListNode* head) {
        
        //1. We gotta find the half way point.
        //2. Reverse half the list.
        //3. Check palindrome


        //ListNode* curr = head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;

        //Even
        while (fast && fast->next)
        {
            //Moves our fast ptr..
            fast = fast->next->next;

            //Reverse linkedlist
            nxt = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nxt;
        }

        //Odd??
        if (fast)
        {
            slow = slow->next;
        }

        //Palindrome...
        while (prev && slow)
        {
            if (prev->val != slow->val)
            {
                return false;
            }

            prev = prev->next;
            slow = slow->next;
        }

        return true;
    }
};