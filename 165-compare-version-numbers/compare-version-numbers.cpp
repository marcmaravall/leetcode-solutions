class Solution {
public:
    int compareVersion(string version1, string version2) {
        std::vector<std::string> v1, v2;
        std::string str = "";
        for (char c : version1) {
            if (c == '.') {
                v1.push_back(str);
                str.clear();
            } else {
                str += c;
            }
        }
        if (str != "") {
            v1.push_back(str);
        }
        str = "";
        for (char c : version2) {
            if (c == '.') {
                v2.push_back(str);
                str.clear();
            } else {
                str += c;
            }
        }
        if (str != "") {
            v2.push_back(str);
        }
        const int n = std::max(v1.size(), v2.size());
        for (int i = 0; i < n; i++) {
            int x1 = i < v1.size() ? std::stoi(v1[i]) : 0;
            int x2 = i < v2.size() ? std::stoi(v2[i]) : 0;
            if (x1 < x2) {
                return -1;
            } else if (x1 > x2) {
                return 1;
            }
        }
        return 0;
    }
};