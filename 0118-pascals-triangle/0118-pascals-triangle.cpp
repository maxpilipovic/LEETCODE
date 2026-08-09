class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> res;
        res.push_back({1});

        createTriangle(2, numRows, res);

        return res;
    }

    void createTriangle(int i, int numsRows, vector<vector<int>>& res)
    {
        
        vector<int> local;

        //Base Case
        if (i > numsRows)
        {
            return;
        }

        auto& element = res.back();

        //Grab first and last elements
        int first = 0;
        int last = 1;

        //Build local
        while (last < element.size())
        {
            int x = element[first] + element[last];
            local.push_back(x);
            
            first += 1;
            last += 1;
        }

        //Add the one at front and back
        local.insert(local.begin(), 1);
        local.push_back(1);

        //Add to res
        res.push_back(local);

        //Recursive case
        createTriangle(i + 1, numsRows, res);
    }

private:

};