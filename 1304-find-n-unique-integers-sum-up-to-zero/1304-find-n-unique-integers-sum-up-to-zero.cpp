class Solution {
public:
    vector<int> sumZero(int n) {
        
        
        vector<int> res;

        if (n == 0)
        {
            return res;
        }

        if (n == 1)
        {
            res.push_back(0);
            return res;
        }
        
        for (int i = 1; i < n; i++)
        {
            res.push_back(i);
            res.push_back(-i);

            if (res.size() == n - 1)
            {
                res.push_back(0);
            }

            if (res.size() == n)
            {
                break;
            }

        }

        printVector(res);

        return res;
    }

    void printVector(const std::vector<int>& vec) 
    {
        std::cout << "[";
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i];
            if (i < vec.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }

};