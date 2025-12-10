class Solution {
public:
    int countPermutations(vector<int>& complexity) 
    {
        int n = complexity.size();

        std::vector<bool> cache(n, false);
        cache[0] = true;

        //Start first value ahead and count to be 1 because of first value automatically decrypted.
        dfs(0, cache, complexity, n, 1);

        return res;
    }

    void dfs(int last, std::vector<bool>& cache, std::vector<int>& complexity, int n, int countUsed)
    {
        //Out of bounds //NOT NEEDED (REDUNDENT) BUT FINE

        if (countUsed == n)
        {
            res += 1;
            return;
        }

        for (int nxt = 0; nxt < n; nxt++)
        {
            if (!cache[nxt] && isValid(nxt, cache, complexity))
            {
                cache[nxt] = true;
                //countUsed += 1;
                dfs(nxt, cache, complexity, n, countUsed + 1);
                //countUsed -= 1;
                cache[nxt] = false;
            }
        }

        return;
    }

    bool isValid(int nxt, std::vector<bool>& cache, std::vector<int>& complexity)
    {
         for (int j = 0; j < nxt; j++)
        {
            if (cache[j] && complexity[j] < complexity[nxt])
            {
                return true;
            }
        }
        return false;
    }


private:
    int res = 0;
};