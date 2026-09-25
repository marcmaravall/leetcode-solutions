class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        std::unordered_map<std::string_view, std::string_view> map;
        for (auto& k : knowledge)
            map[k[0]] = k[1];
        const int n = s.size();
        std::string res = "";
        for (int i = 0; i < n; i++) {
            if (s[i] != '(') {
                res += s[i];
                continue;
            }
            i++;
            std::string key = "";
            for (i; s[i] != ')'; i++)
                key += s[i];
            const std::string_view val = map[key];
            res += val.empty() ? "?" : val;
        }
        return res;
    }
};