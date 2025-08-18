class Solution {
public:
    int maximum69Number (int num) {
        
        std::string strNum = std::to_string(num);

        for (int i = 0; i < strNum.size(); i++)
        {

            if (strNum[i] == '6')
            {
                strNum[i] = '9';
                break;
            }
        }

        return std::stoi(strNum);
    }
};