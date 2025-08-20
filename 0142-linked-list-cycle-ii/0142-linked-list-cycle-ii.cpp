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
    ListNode *detectCycle(ListNode *head) {
        
        //Faster & Slow pointers. Cycle detection
        //Not sure here //BASE CASE
        if (!head)
        {
            return nullptr;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) //.next.next?
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast)
            {
                //IDK
                ListNode* entry = head;

                while (entry != slow)
                {
                    entry = entry->next;
                    slow = slow->next;
                }

                return entry;
            }

        }
        return nullptr;
    }
};