class Solution {
public:
    string smallestSubsequence(string s) 
    {
        unordered_map<char, int> map;
        unordered_set<char> set;
        int n = s.size();

        for (int i{}; i < n; i++)
        {
            char c = s[i];

            map[c] = i;
        }    

        std::stack<char> stack;

        for (int i{}; i < n; i++)
        {
            char c = s[i];

            //If in stack already.
            if (set.count(c))
            {
                continue;
            }

            //Pop while top of stack is greater then c and there is another in the future.
            while (!stack.empty() && stack.top() > c && map[stack.top()] > i)
            {
                set.erase(stack.top());
                stack.pop();
            }

            set.insert(c);
            stack.push(c);
        }

        //Pop stack
        while (!stack.empty())
        {
            char c = stack.top();
            stack.pop();

            res += c;
        }

        //Reverse
        reverse(res.begin(), res.end());

        return res;
    }

private:
    std::string res = "";
};