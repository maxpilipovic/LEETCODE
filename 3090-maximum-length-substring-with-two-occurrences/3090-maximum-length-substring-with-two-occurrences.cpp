class Solution {
public:
    int maximumLengthSubstring(string s) 
    {
        int left = 0;
        unordered_map<char, int> map;

        for (int right{}; right < s.size(); right++)
        {
            map[s[right]] += 1;

            while (map[s[right]] > 2)
            {
                //Decrement far left...
                map[s[left]] -= 1;

                //Remove it if its zero
                if (map[s[left]] == 0)
                {
                    map.erase(s[left]);
                }

                //Increment left.
                left += 1;

            }

            //Check the max.
            res = max(res, right - left + 1);

        }   

        return res;
    }

private:
    int res = 0;
};