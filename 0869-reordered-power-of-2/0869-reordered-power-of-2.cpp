class Solution {
public:
    bool reorderedPowerOf2(int n) {
            std::string alphaString = std::to_string(n);
    std::sort(alphaString.begin(), alphaString.end());

    do {

        if (alphaString[0] == '0')
        {
            continue;
        }

        int num = std::stoi(alphaString);

        if (isPowerof2(num))
        {
            return true;
        }
        
    } while (std::next_permutation(alphaString.begin(), alphaString.end()));
    return false;
}

bool isPowerof2(int num)
{
    return num > 0 && (num & (num - 1)) == 0;
}

};