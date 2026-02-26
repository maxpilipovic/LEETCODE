class Solution {
public:
    int numSteps(string s) 
    {
        //Traverse from right to left.
        for (size_t i = s.size() - 1; i > 0; i--)
        {
            int bit = (s[i] - '0') + carry;

            if (bit % 2 == 0)
            {
                //Divide by 2
                steps += 1;
            }
            else
            {
                carry = 1;
                steps += 2;

            }
        }

        return steps + carry;
    }

private:
    int steps = 0;
    int carry = 0;
};