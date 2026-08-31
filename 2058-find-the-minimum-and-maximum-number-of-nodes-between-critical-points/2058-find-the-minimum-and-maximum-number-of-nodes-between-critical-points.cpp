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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        ListNode* curr = head;
        ListNode* front = head->next;
        ListNode* prev = nullptr;
        int count = 0;
        vector<int> critical;

        while (front)
        {
            //If all 3 are not null. Check
            if (front && curr && prev)
            {
                //Local maxima
                if (prev->val < curr->val && front->val < curr->val)
                {
                    critical.push_back(count);
                }

                //Local minima
                if (prev->val > curr->val && front->val > curr->val)
                {
                    critical.push_back(count);
                }
            }

            prev = curr;
            curr = front;
            front = front->next;
            count++;
        }

        //Find distance
        if (critical.size() < 2)
        {
            return std::vector<int>{-1, -1};
        }

        int minVal = INT_MAX;

        for (int i = 1; i < critical.size(); i++)
        {
            minVal = std::min(minVal, critical[i] - critical[i - 1]);
        }

        int maxVal = critical.back() - critical.front();

        return {minVal, maxVal};
        {
            return std::vector<int>{minVal, maxVal};
        }
    }

private:

};