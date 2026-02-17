class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) 
    {
        
        for (size_t hour{}; hour < 12; hour++)
        {
            for (size_t minute{}; minute < 60; minute++)
            {
                std::bitset<32> binary_rep1(hour);
                std::bitset<32> binary_rep2(minute);

                if (binary_rep1.count() + binary_rep2.count() == turnedOn)
                {
                    std::string time = std::to_string(hour) + ":";

                    //If less then 10
                    if (minute < 10)
                    {
                        time += "0";
                    }

                    time += std::to_string(minute);

                    ans.push_back(time);


                }
            }
        }

        return ans;
    }

private:
    std::vector<string> ans;
};