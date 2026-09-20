class Solution {
public:
    void backtracking(int n, std::string& str, std::vector<std::string>& vec) {
        if (str.size() == n) {
            vec.push_back(str);
            return;
        }
        char last;
        if (str.size() == 0)
            last = '1';
        else last = str.back();

        str += "1";
        backtracking(n, str, vec);
        if (last == '1') {
            str[str.size()-1] = '0';
            backtracking(n, str, vec);
        }
        str.pop_back();
    }

    vector<string> validStrings(int n) {
        std::vector<std::string> res;
        std::string str = "";
        backtracking(n, str, res);
        return res;
    }
};