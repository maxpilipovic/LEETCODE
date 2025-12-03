class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) 
    {
        const long long mod = 1000000007;

        for (int i = 0; i < points.size(); i++)
        {
            hashy[points[i][1]]++;
        }    

        printHashMap(hashy);

        for (auto& value : hashy)
        {
            auto key = value.first;
            auto freq = value.second;

            //Length of 1 does nothing... *
            if (freq <= 1)
            {
                continue;
            }

            long long edge = freq * (freq - 1) / 2; //Combiantorics all different combinations
            res = (res + edge * totalSum) % mod; //
            totalSum = (totalSum + edge) % mod;
        }

        return res;
    }

    void printHashMap(const unordered_map<int, long long>& mp) 
    {
    for (const auto& [key, val] : mp) {
        cout << key << " : [ " << val << "]\n";
    }
}

private:
    long long res = 0;
    long long totalSum = 0;
    unordered_map<int, long long> hashy;
};