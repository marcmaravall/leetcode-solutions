class Solution {
public:
    int maximumLength(string s) {
        std::vector<std::vector<int>> ssub(26, { 0 });
        const int n = s.size();
        for (int i = 0; i < n; i++) {
            int current = 1;
            while (i < n-1 && s[i] == s[i+1]) {
                current++;
                i++;
            }
            ssub[s[i]-'a'].push_back(current);
        } 

        int res = 0;

        for (int c = 0; c < 26; c++) {
            auto &v = ssub[c];

            std::sort(v.rbegin(), v.rend());

            while (v.size() < 3)
                v.push_back(0);

            int a = v[0];
            int b = v[1];
            int cc = v[2];

            res = max(res, max({
                a - 2,
                min(a - 1, b),
                cc
            }));
        }

        return res <= 0 ? -1 : res;
    }
};