class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        string prev = "";

        for (auto w : words)
        {
            //Sort
            string s = w;
            sort(s.begin(), s.end());

            if (s != prev)
            {
                res.push_back(w);
                prev = s;
            }
        }

        return res;
        
    }

private:
    vector<string> res;
};