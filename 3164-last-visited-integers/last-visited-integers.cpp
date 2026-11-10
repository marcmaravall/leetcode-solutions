
class Solution {
public:
    vector<int> lastVisitedIntegers(vector<int>& nums) {
        std::vector<int> seen, ans;
        int k = 0;
        for (int x : nums) {
            if (x > 0) {
                seen.push_back(x);
                k = 0;
            } else {
                k++;
                if (k <= seen.size()) {
                    ans.push_back(seen[seen.size()-k]);
                } else {
                    ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};
