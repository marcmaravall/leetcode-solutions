class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int freq[2];
        for (int& n : nums) {
            freq[n%2]++;
        }
        std::vector<int> res(freq[0], 0);
        std::vector<int> ones(freq[1], 1);
        res.insert(res.end(), ones.begin(), ones.end());

        return res;
    }
};