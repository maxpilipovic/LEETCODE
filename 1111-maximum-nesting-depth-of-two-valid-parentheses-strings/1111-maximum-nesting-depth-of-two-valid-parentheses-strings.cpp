class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) 
    {
        
        int depth = 0;
        
        for (int i{}; i < seq.size(); i++)
        {
            if (seq[i] == '(')
            {
                depth += 1;
                res.push_back(depth % 2);
            }
            else
            {
                res.push_back(depth % 2);
                depth -= 1;
            }
            
        }   

        return res; 
    }

private:
    vector<int> res;
};