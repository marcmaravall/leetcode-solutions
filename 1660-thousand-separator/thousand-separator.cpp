class Solution {
public:
    string thousandSeparator(int n) {
    std::string s = std::to_string(n);
    std::string res = "";
    for (int i = 0; i < s.size(); ++i) {
        if (i > 0 && (s.size() - i) % 3 == 0)
            res += ".";
        res += s[i];
    }
    return res;
}
};