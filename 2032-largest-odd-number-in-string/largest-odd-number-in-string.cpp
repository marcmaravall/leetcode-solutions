class Solution {
public:
    string largestOddNumber(string num) {
        const int n = num.size();
        for (int i = n-1; i >= 0; i--) {
            if (num[i] == '1' || num[i] == '3' || num[i] == '5' || num[i] == '7' || num[i] == '9') {
                std::string res = "";
                for (int j = 0; j <= i; j++) {
                    res += num[j];
                }
                return res;
            }
        }

        return "";
    }
};