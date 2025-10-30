class Solution {
public:
    int minNumberOperations(vector<int>& target) {

        //Base Case
        if (target.empty())
        {
            return 0;
        }

        //Inital vector
        //vector<int> initial(values.size(), 0);
        int prev = 0;
        int curr = target[0];

        for (int i = 1; i < target.size(); i++)
        {

            if (target[i] > target[prev])
            {
                curr += target[i] - target[prev];
            }
            prev = i;

        }

        return curr;

    }

private:
    std::stack<int> values;
};