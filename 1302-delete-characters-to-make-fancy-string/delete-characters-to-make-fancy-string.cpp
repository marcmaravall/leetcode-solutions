class Solution {
public:
    string makeFancyString(string s) {
        const int n = s.size();
        if (n < 3)
            return s;
        char b = s[0], a = s[1];
        std::string res = "";
        res += b; res += a;
        for (int i = 2; i < n; i++) {
            if (s[i] == a && a == b)
                continue;
            res += s[i];
            b = a;
            a = s[i];
        }
        return res;
    }
};