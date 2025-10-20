class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {

        for (std::string v : operations)
        {
            PerformOperation(v, operations);
        }

        return value;    
    }

    void PerformOperation(std::string v, vector<string>& operations)
    {

        if (v == "--X" || v == "X--")
        {
            value -= 1;
        }
        else
        {
            value += 1;
        }
        
    }


private:
    int value = 0;

};