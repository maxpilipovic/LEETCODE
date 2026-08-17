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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        //std::atoi(x.c_str()); 
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;

            int sum = x + y + carry;
            //Carry?
            carry = sum / 10;

            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            if (l1)
            {
                l1 = l1->next;
            }

            if (l2)
            {
                l2 = l2->next;
            }            

        }

        //Maybe add while here...
        ListNode* result = dummy->next;
        return result;
    }

    ListNode* newListNode(ListNode* dummy, std::string z)
    {
        int n = z.size();
        ListNode* curr = dummy;

        for (int i = 0; i < n; i++)
        {
            std::cout << z[i] - '0' << std::endl;
            curr->val = z[i] - '0';

            if (i != n - 1)
            {
                curr->next = new ListNode(0);
                curr = curr->next;
            }
        }

        return dummy;
    }
};