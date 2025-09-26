class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> hashy(wordDict.begin(), wordDict.end());
        return backtrack(0, s, wordDict, hashy);


    }

    bool backtrack(int start, string& s, vector<string>& wordDict, unordered_set<string>& hashy)
    {
        if (start == s.size())
        {
            return true;
        }

        if (dp.count(start)) 
        {
            return dp[start];
        }

        for (int end = start + 1; end <= s.size(); ++end) 
        {
            //Generate substring
            string sub = s.substr(start, end - start);
            if (hashy.count(sub) && backtrack(end, s, wordDict, hashy)) 
            {
                dp[start] = true;
                return true;
            }
        }
        dp[start] = false;

        return false;
    }

private:
    unordered_map<int, bool> dp;

};