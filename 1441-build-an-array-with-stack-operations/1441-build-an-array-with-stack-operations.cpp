class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) 
    {
        int size = target.size();
        vector<string> res;
        stack<int> stack;

        int num = 1;
        int index = 0;

        while (num <= n)
        {

            //Base case
            if (index >= size)
            {
                break;
            }
            
            //Push to stack.
            stack.push(num);
            res.push_back("Push");

            //Check if this number is NOT at the top of the stack.
            if (target[index] != stack.top())
            {
                stack.pop();
                res.push_back("Pop");
            }
            else
            {
                //If it is
                index += 1;
            }

            //Increase num
            num += 1;
            
        }

        return res;
    }

private:
    
};