class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        
        return dfs(word1, word2, 0, 0);

    }

    int dfs(string& word1, string& word2, int i, int j)
    {

        //Base Case
        if (i >= word1.size())
        {
            return word2.size() - j;
        }

        if (j >= word2.size())
        {
            return word1.size() - i;
        }

        if (dp.count(std::pair(i, j)))
        {
            return dp[std::pair(i, j)];
        }

        int ans;

        //Main part of algorithm...
        if (word1[i] == word2[j])
        {
            return dfs(word1, word2, i + 1, j + 1);
        }
        else
        {
            int insert = 1 + dfs(word1, word2, i, j + 1);
            int del = 1 + dfs(word1, word2, i + 1, j);
            int replace = 1 + dfs(word1, word2, i + 1, j + 1);

            ans = std::min({insert, del, replace});    
            dp[std::pair(i, j)] = ans;
            return ans;
        }

    }

private:

    map<std::pair<int, int>, int> dp;
};