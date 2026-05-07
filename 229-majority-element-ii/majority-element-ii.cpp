class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        std::unordered_map<int, int> freq;
        std::vector<int> res;
        for (int x : nums) {
            freq[x]++;
            if (freq[x] > n/3) {
                res.push_back(x);
                freq[x] = INT_MIN;
            }
        }
        return res;
    }
};