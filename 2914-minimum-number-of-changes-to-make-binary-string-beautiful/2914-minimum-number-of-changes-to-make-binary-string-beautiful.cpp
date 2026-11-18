class Solution {
public:
    int minChanges(string s) {
        
        //Always even so guareenteed to work
        for (int i{}; i < s.size(); i += 2)
        {
            int x = checkSameAndUpdate(s[i], s[i + 1]);
            
            //Add to global res.
            res += x;
        }

        return res;
    }

    int checkSameAndUpdate(char c, char x)
    {
        int local = 0;

        if (c != x)
        {
            local += 1;
        }

        return local;
    }

private:
    int res = 0;
};