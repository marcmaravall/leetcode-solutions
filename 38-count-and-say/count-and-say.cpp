class Solution {
public:
    std::string rle(const std::string& str) {
        std::string res = "";
        for (int i = 0; i < str.size(); i++) {
            int count = 1;
            char c = str[i];
            while (i < str.size()-1 && str[i] == str[i+1]) {
                count++;
                i++;
            }
            res += std::to_string(count) + c;
        }

        return res;
    }

    string countAndSay(int n) {
        if (n == 1)
            return "1";
        return rle(countAndSay(n-1));
    }
};