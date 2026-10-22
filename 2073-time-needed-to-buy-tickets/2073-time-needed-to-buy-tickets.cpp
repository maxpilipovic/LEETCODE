class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) 
    {
        std::queue<std::pair<int, int>> queue;

        for (int i{}; i < tickets.size(); i++)
        {
            if (i == k)
            {
               queue.push({tickets[i], -1}); 
            }
            else
            {
               queue.push({tickets[i], -2});  
            }
        }

        while (!queue.empty())
        {
            //Grab num
            auto [num, index] = queue.front();

            //Pop
            queue.pop();
            
            //Decrement
            num -= 1;

            //Base Case
            if (num == 0 && index == -1)
            {
                return count + 1;
            }

            if (num > 0)
            {
                //Add back
                queue.push({num, index});
            }

            //Add '1' count for a second
            count += 1;
        }

        return count;
    }

private:
    int count = 0;
};