class Solution {
public:
    bool areNumbersAscending(string s) {
        int last = INT_MIN;
        std::string token = "";
        bool isNum = true;
        for (char c : s) {
            if (c == ' ') {
                if (isNum) {
                    int num = std::stoi(token);
                    if (num <= last) {
                        return false;
                    }
                    last = num;
                }
                isNum = true;
                token = "";
            } else {
                if (c < '0' || c > '9') {
                    isNum = false;
                }
                token += c;
            }
        }
        if (isNum) {
            int num = std::stoi(token);
            if (num <= last) {
                return false;
            }
        }
        return true;
    }
};