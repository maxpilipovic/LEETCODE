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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        std::unordered_set<int> visited;

        ListNode* prev = nullptr;
        ListNode* temp = head;

        while (temp != nullptr)
        {

            if (!visited.count(temp->val))
            {
                visited.insert(temp->val);

                //Move prev up to the node we kept
                prev = temp;
            }
            else
            {
                //Delete node
                deleteDuplicateNode(temp, prev);
            }

            temp = temp->next;
        }    

        return head;
    }

    void deleteDuplicateNode(ListNode* temp, ListNode* prev)
    {
        prev->next = temp->next;
    }

private:

};