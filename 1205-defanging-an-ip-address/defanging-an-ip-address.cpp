class Solution {
public:
    string defangIPaddr(string address) {
        std::string res {};
        for (char c : address) {
            if (c == '.') {
                res += "[.]";
            } else res += c;
        }
        return res;
    }
};