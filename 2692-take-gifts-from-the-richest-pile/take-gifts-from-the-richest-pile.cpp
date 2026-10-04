class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        while (k--) {
            auto m = std::max_element(gifts.begin(), gifts.end());
            *m = std::floor(std::sqrt(*m));
        }
        long long res = 0;
        for (int x : gifts)
            res += x;
        return res;
    }
};