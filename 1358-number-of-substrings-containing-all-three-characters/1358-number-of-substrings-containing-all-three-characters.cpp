class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int n = s.size();
        int left = 0;

        unordered_map<char, int> freq;

        for (int right = 0; right < n; right++)
        {
            freq[s[right]] += 1;

            while (freq['a'] > 0 && freq['b'] > 0 && freq['c'] > 0)
            {
                count += s.size() - right;

                freq[s[left]]--;
                left++;

            }
        }

        return count;
    }
private:
    int count = 0;
};