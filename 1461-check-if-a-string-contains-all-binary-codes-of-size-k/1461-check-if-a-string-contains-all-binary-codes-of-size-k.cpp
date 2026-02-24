class Solution {
public:
    bool hasAllCodes(string s, int k) 
    {
        int n = (int)s.size();

        //Base case
        if (n < k)
        {
            return false;
        }

        //Fast way to compute (2 ^ n)
        int need = 1 << k;

        unordered_set<std::string> res;
        int left = 0;
        std::string window;

        for (int right = 0; right < n; right++)
        {
            window.push_back(s[right]);

            if (window.size() > k) 
            {
                window.erase(window.begin());  //O(k)
            }

            if (window.size() == k) {
                res.insert(window);

                //Check if we got it...
                if (res.size() == need)
                {
                    return true;
                }
            }
        }

        return false;
    }
};