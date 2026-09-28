class Solution {
public:
    int maxDepth(string s) 
    {
        int best = 0;
        int depth = 0;

        for (char c : s)
        {
            if (c == '(')
            {
                depth += 1;
                best = max(best, depth);
            }
            else if (c == ')')
            {
                depth -= 1;
            }
        }

        return best;
    }
};