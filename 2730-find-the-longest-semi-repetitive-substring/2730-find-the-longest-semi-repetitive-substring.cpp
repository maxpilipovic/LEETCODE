class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        // TODO: Implement solution
int count = 0;
int left = 0;
int right = 0;
int maxLen = 0;

for (; right < s.size(); ++right)
{
    if (right > 0 && s[right] == s[right - 1])
    {
        count++;
    }

    //Left Pointer
    while (count > 1) 
    {
        if (left < s.size() - 1 && s[left] == s[left + 1])
        {
            count--;
        }
        left++;
    }
    maxLen = std::max(maxLen, right - left + 1);

}

return maxLen;
    }
};