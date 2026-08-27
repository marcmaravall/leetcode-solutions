class Solution {
public:
    int similarPairs(vector<string>& words) {
        int res = 0;
        const int n = words.size();
        for (int i = 0; i < n; ++i) {
            int mask1 = 0;
            for (char c : words[i])
                mask1 |= 1 << (c - 'a');
            for (int j = i + 1; j < words.size(); ++j) {
                int mask2 = 0;
                for (char c : words[j])
                    mask2 |= 1 << (c-'a');
                if (mask1 == mask2)
                    res++;
            }
        }

        return res;
    }
};
