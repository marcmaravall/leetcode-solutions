class Solution {
public:
    string generateTag(string caption) {
        std::string res = "#";
        const int n = caption.size();
        bool first = false, lastSpace = false;
        for (int i = 0; i < n && res.size() < 100; i++) {
            if (caption[i] == ' ') {
                lastSpace = true;
                continue;
            }
            if (!first) {
                res += std::tolower(caption[i]);
                first = true;
            } else if (lastSpace) {
                res += std::toupper(caption[i]);
            } else {
                res += std::tolower(caption[i]);
            }
            lastSpace = false;
        }
        return res;
    }
};