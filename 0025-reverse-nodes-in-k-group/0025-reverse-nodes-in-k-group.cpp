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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        
        ListNode dummy(0, head);
        ListNode* groupPrev = &dummy;

        while (HasKNodes(groupPrev->next, k))
        {
            //Next value after dummy.
            ListNode* first = groupPrev->next;
            ListNode* prev = nullptr;
            ListNode* curr = first;

            //Reversing pointers
            for (int i{}; i < k; i++)
            {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            //Get ready for next group of k
            groupPrev->next = prev;
            first->next = curr;
            groupPrev = first;
        }

        return dummy.next;

    }

    bool HasKNodes(ListNode* end, int k)
    {
        int count = 0;

        //Get to the end of k.
        while (count < k && end != nullptr) 
        {
            end = end->next;
            count++;
        }

        return count == k;
    }
};