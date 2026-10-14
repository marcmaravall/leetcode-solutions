class Solution {
public:
    int maxRepeating(string sequence, string word) {
        const int n = sequence.size(), k = word.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            int j = 0, index = i;
            bool b = word[j%k] == sequence[i];
            while (word[j%k] == sequence[i]) {
                j++, i++;
            }
            i = index;
            res = std::max(res, j/k);
        }
        return res;
    }
};