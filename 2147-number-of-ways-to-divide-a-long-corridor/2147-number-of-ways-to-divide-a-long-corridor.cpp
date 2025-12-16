class Solution {
public:
    int numberOfWays(string corridor) {
        
        int countSeats = 0;
        int countPlants = 0;

        for (char c : corridor)
        {
            if (c == 'S')
            {
                countSeats++;
            }
            else
            {
                countPlants++;
            }
        }

        //If count is odd or count < 2 return 0!!!
        if (countSeats % 2 == 1 || countSeats < 2)
        {
            return 0;
        }

        int seatsInCurrentGroup = 0;
        long long plantsBetweenGroups = 0;

        for (char c : corridor)
        {
            if (c == 'S') 
            {
                seatsInCurrentGroup += 1;

                if (seatsInCurrentGroup == 3)
                {
                    res = (res * (plantsBetweenGroups + 1)) % MOD;
                    plantsBetweenGroups = 0;
                    seatsInCurrentGroup = 1;
                }
            }
            else
            {
                if (seatsInCurrentGroup == 2)
                {
                    plantsBetweenGroups += 1;
                }
            }
        }
        
        return (int)res;
    }

private:
    long long res = 1;
    const long long MOD = 1'000'000'007LL;
};