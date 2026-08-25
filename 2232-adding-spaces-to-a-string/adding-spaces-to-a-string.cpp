class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        const int n = s.size();
        std::string res(n + spaces.size(), '\0');
        int count = 0;
        for (int space : spaces)
            res[space+count++] = ' ';
        int it = 0;
        for (int i = 0; i < n; i++) {
            while (it < res.size() && res[it] == ' ')
                it++;
            res[it++] = s[i];
        }
        return res;
    }
};