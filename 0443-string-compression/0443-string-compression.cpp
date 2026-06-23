class Solution {
public:
    int compress(vector<char>& chars) 
    {
       
       int left = 0;
       int right = chars.size();
       int write = 0;

       while (left < right)
       {
            char curr = chars[left];
            int count = 0;

            while (left < right && curr == chars[left])
            {
                left += 1;
                count += 1;
            }

            chars[write] = curr;
            write++;

            if (count > 1)
            {
                string s = to_string(count);

                for (char digit : s)
                {
                    chars[write] = digit;
                    write++;
                }
            }
       }

       return write;
    }

private:
    int res = 0;
};