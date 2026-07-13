class Solution {
public:
    vector<int> sequentialDigits(int low, int high) 
    {
        const std::string digits = "123456789";

        for (int length = 2; length <= 9; length++)
        {
            for (int start{}; start + length <= digits.size(); start++)
            {
                std::string current = digits.substr(start, length);

                //To int
                int num = stoi(current);

                if (num >= low && num <= high)
                {
                    res.push_back(num);
                }
            }
        }

        sort(res.begin(), res.end());

        return res;
    }

private:
    vector<int> res;
};