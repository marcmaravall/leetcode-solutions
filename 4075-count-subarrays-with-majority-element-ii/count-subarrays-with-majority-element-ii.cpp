class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        long long res = 0;
        int pre = n+1;
        
        std::vector<int> count(2*n+2), acc(2*n+2);
        count[pre] = 1, acc[pre] = 1;

        for (int x : nums) {
            pre += (x == target ? 1 : -1);
            count[pre]++;
            acc[pre] = acc[pre - 1] + count[pre];
            res += acc[pre - 1];
        }

        return res;
    }
};