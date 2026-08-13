class Solution {
public:
    void backtrack(std::string& s, int i, std::vector<std::string>& vec) {
        if (i >= s.size()) {
            vec.push_back(s);
            return;
        }
        char curr = s[i];
        if (curr >= '0' && curr <= '9') {
            backtrack(s, i+1, vec);
            return;
        }

        s[i] = std::tolower(curr);
        backtrack(s, i+1, vec);
        s[i] = std::toupper(curr);
        backtrack(s, i+1, vec);
        s[i] = curr;
    }

    vector<string> letterCasePermutation(string s) {
        std::vector<std::string> res;
        backtrack(s, 0, res);
        return res;
    }
};