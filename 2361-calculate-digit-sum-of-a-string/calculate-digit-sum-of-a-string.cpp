class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            std::string str = "";
            int num = 0;
            bool b = false;
            for (int i = 0; i < s.size(); i++) {
                num += s[i]-'0';
                if ((i+1) % k == 0) {
                    str += std::to_string(num);
                    num = 0;
                    b = false;
                } else {
                    b = true;
                }
            }
            if (b) {
                str += std::to_string(num);
            }
            s = std::move(str);
        }
        return s;
    }
};