class Solution {
public:
    int maximumGain(string s, int x, int y) {
            if (x < y)
    {
        std::swap(x, y);

        for (char& c : s)
        {
            if (c == 'a')
            {
                c = 'b';
            }
            else if (c == 'b')
            {
                c = 'a';
            }
        }
    }

    int score = 0;
    std::string result = removePattern(s, 'a', 'b', x, score);
    removePattern(result, 'b', 'a', y, score);


    return score;
}

std::string removePattern(const std::string& s, char first, char second, int points, int& score)
{
    std::deque<char> stack;

    for (char c : s)
    {

        if (!stack.empty() and stack.front() == first and c == second)
        {
            stack.pop_front();
            score += points;
        }
        else 
        {
            stack.push_front(c);
        }
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