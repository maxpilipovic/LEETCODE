class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) 
    {
        
        string prev = "";

        for (auto word : words)
        {
            string s = word;

            sort(s.begin(), s.end());

            if (s != prev)
            {
                res.push_back(word);
                prev = s;
            }
        }

        return res;
    }

private:
    vector<string> res;
};