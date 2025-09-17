class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        
        
        for (int num : nums)
        {
            int x = num;

            while (!res.empty())
            {
                int top = res.back();
                //if (top == 1)
                //{
                    //break;
                //}
                int gcd = std::gcd(x, top);
                if (gcd == 1)
                {
                    break;
                }

                //Calculate lcm
                int lcm = std::lcm(x, top);
                res.pop_back();
                //res.push_back(lcm);
                x = lcm; //**Had to updat what x was.
                
            }

            res.push_back(x);
        }

        return res;

    }

private:
    vector<int> res;
};