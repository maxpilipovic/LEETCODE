class Solution {
public:
    string removeStars(string s) {
            std::deque<char> stack;

    for (int i = 0; i < s.size(); i++)
    {   
        if (s[i] == '*')
        {
            stack.pop_front();
            continue;
        }
        stack.push_front(s[i]);
    }

    std::string result;

    while (!stack.empty())
    {
        result += stack.back();
        stack.pop_back();
    }
    return result;
    }
};