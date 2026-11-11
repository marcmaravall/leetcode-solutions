class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int freq[100001] = {};
        for (int x : nums) {
            freq[x+50000]++;
        }
        std::vector<int> res;
        for (int i = 0; i <= 100000; i++) {
            for (int j = 0; j < freq[i]; j++) {
                res.push_back(i-50000);
            }
        }
        return res;
    }
};