class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int full = numBottles;
        int res = 0;
        int empty = 0;

        //while
        while (full > 0)
        {
            drink(res, empty, full, numBottles);
            exchange(empty, full, numExchange);
            std::cout << res << std::endl;
        }

        return res;
        
    }

    void exchange(int& empty, int& full, int& numExchange)
    {
        int traded = (empty / numExchange);
        empty = empty % numExchange;
        full = traded;
    }

    void drink(int& res, int& empty, int& full, int& numBottles) 
    {
        //Empty bottles
        res += full;
        empty += full;
        full = 0;
    }

};