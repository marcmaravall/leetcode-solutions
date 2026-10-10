class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        std::array<int, 100> freq;
        for (auto& domino : dominoes) {
            if (domino[0] > domino[1])
                std::swap(domino[0], domino[1]);
            int key = domino[0]*10+domino[1];
            freq[key]++;
        }
        int res = 0;
        for (int x : freq) {
            res += x*(x-1)/2;
        }
        return res;
    }
};