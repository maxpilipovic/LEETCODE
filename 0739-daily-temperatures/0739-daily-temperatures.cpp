class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n = temperatures.size();
        vector<int> res(n, 0);

        stack<int> stack;

        for (int i{}; i < n; i++)
        {
            while (!stack.empty() && temperatures[i] > temperatures[stack.top()])
            {
                int num = stack.top();
                stack.pop();

                //Add to res with the total wait
                res[num] = i - num;


            }

            //If empty add value
            stack.push(i);
        }    

        return res;
    }

private:

};