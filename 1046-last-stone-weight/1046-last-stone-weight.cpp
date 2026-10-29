class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        std::priority_queue<int> max_heap;

        for (int i{}; i < stones.size(); i++)
        {
            max_heap.push(stones[i]);
        }

        while (!max_heap.empty() && max_heap.size() >= 2)
        {
            int a = max_heap.top();
            max_heap.pop();

            int b = max_heap.top();
            max_heap.pop();

            if (a != b)
            {
                int x = abs(a - b);
                max_heap.push(x);
            }
        }

        if (!max_heap.empty())
        {
            return max_heap.top();
        } 

        return 0;
    }
private:

};