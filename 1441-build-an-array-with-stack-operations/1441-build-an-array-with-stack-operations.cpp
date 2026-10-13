class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) 
    {
        int local = 1;
        std::stack<int> stack;
        vector<string> res;
        int index = 0;

        while (local <= n)
        {

            //Base Case
            if (target.size() == index)
            {
                break;
            }
            
            //Push stack
            stack.push(local);
            
            //Add to vec
            res.push_back("Push");

            //Int num stack
            int num = stack.top();
            
            //If not target then pop
            if (num != target[index])
            {
                stack.pop();
                res.push_back("Pop");
            }
            else
            {
                index += 1;
            }

            local += 1;
        }

        return res;
    }

private:

};