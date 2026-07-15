class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int m = *std::max_element(candies.begin(), candies.end());
        const int n = candies.size();
        std::vector<bool> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = (candies[i]+extraCandies) >= m;
        }
        return res;
    }
};