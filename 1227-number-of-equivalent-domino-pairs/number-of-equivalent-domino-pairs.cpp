class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        for (auto& domino : dominoes) {
            if (domino[0] > domino[1])
                std::swap(domino[0], domino[1]);
        }
        const int n = dominoes.size();
        std::array<int, 100> freq;
        for (int i = 0; i < n; i++) {
            int key = dominoes[i][0]*10+dominoes[i][1];
            freq[key]++;
        }
        int res = 0;
        for (int x : freq) {
            res += x*(x-1)/2;
        }
        return res;
    }
};