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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        //Create the set data structure [1, 2, 3]
        unordered_set<int> hashy(nums.begin(), nums.end());

        //Create a copy pointer to beginning of linked list
        ListNode dummy(0);
        dummy.next = head;

        ListNode* curr = head;
        ListNode* prev = &dummy;

        //This loops through our linkedlist
        while (curr)
        {

            if (hashy.count(curr->val))
            {
                prev->next = curr->next;
                curr = curr->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy.next;

    }

private:

};