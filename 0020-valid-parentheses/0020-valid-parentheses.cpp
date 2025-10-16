class Solution {
public:
    bool isValid(string s) {
        
        std::stack<char> stack;

        for (char c : s)
        {
            //Closing bracket
            if (map.count(c)) //If it exists
            {
                if (stack.empty() || stack.top() != map[c])
                {
                    return false;
                }
                stack.pop();
            }
            else
            {
                stack.push(c);
            }
        }
        
        //Check if empty. Has to be equal
        if (stack.empty())
        {
            return true;
        }

        return false;
    }

private:
    unordered_map<char, char> map = {{')', '('}, {'}', '{'}, {']', '['}};
};