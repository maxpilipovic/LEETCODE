class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        
        int n = fruits.size();
        int m = baskets.size();
        std::vector<bool> visited(m, false);
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (fruits[i] <= baskets[j] && !visited[j])
                {
                    visited[j] = true;
                    break;
                }

            }
        }

        for (const auto& boo : visited)
        {
            std::cout << boo << std::endl;
            if (!boo)
            {
                res++;
            }
        }

        return res;

    }
};