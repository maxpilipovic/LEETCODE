class Solution {
public:
    vector<int> partitionLabels(string s) 
    {

        //Map to keep track of everything we are holding.
        unordered_map<char, int> map;

        for (int i{}; i < s.size(); i++)
        {
            //Overrites the last spot.
            map[s[i]] = i;
        }

        int start = 0;
        int maxEnd = 0;

        for (int i{}; i < s.size(); i++)
        {
            maxEnd = max(maxEnd, map[s[i]]);

            if (i == maxEnd)
            {
                res.push_back(i - start + 1);
                start = i + 1;
            }
        }

        return res;
    }

private:
    vector<int> res;
};