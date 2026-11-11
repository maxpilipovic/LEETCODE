class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        auto costWith = [&](long long k)
        {
            long long left1 = max(0LL, (long long)need1 - k);
            long long left2 = max(0LL, (long long)need2 - k);

            return k * costBoth + left1 * cost1 + left2 * cost2;
        };

        long long low = min(need1, need2);  
        long long high = max(need1, need2);  

        return min({costWith(0), costWith(low), costWith(high)});
    }

private:

};