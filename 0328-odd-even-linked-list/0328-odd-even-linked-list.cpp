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
    ListNode* oddEvenList(ListNode* head) 
    {
        //Base Case
        if (!head || !head->next)
        {
            return head;
        }

        ListNode* oddTail  = head;        //position 1
        ListNode* evenHead = head->next;  //position 2
        ListNode* evenTail = evenHead;

        ListNode* curr = evenHead->next; 
        int count = 3;

        while (curr)
        {
            if (count % 2 == 1)
            {
                oddTail->next = curr;
                oddTail = curr;
            }
            else
            {
                evenTail->next = curr;
                evenTail = curr;
            }
            curr = curr->next;
            count += 1;
        }

        evenTail->next = nullptr;
        oddTail->next = evenHead;
        return head;
    }

private:

};