class Solution {
public:
    bool repeatedSubstringPattern(string s) 
    {
        int n = s.size();

        for (int blockLen = 1; blockLen <= n / 2; blockLen++)
        {
            if (canTile(n, blockLen) && isRepeatOf(s, blockLen))
            {
                return true;
            }
        }

        return false;
    }

    //Check if the tile can be evenly divided (reoccuring substr)
    bool canTile(int n, int blockLen)
    {
        return n % blockLen == 0;
    }

    bool isRepeatOf(const string& s, int blockLen)
    {
        std::string block = s.substr(0, blockLen);

        for (int i{}; i < s.size(); i += blockLen)
        {
            std::string x = s.substr(i, blockLen);

            if (x != block)
            {
                return false;
            }
        }

        return true;
    }

private:
};