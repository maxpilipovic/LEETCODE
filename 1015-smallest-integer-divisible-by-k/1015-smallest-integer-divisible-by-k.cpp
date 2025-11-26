class Solution {
public:
    int smallestRepunitDivByK(int k) 
    {
        
        int num = 0;
        int length = 0;


        while (true)
        {
            length += 1;
            num = (num * 10 + 1) % k;
            
            if (num == 0)
            {
                return length;
            }

            if (seen.count(num))
            {
                return -1;
            }
            
            //Add to hashy
            seen.insert(num);
        }

    }

private:
    unordered_set<int> seen;

};