class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        const int m = l.size();
        std::vector<bool> res(m);
        for (int i = 0; i < m; i++) {
            std::vector<int> subarray(nums.begin()+l[i], nums.begin()+r[i]+1);
            std::sort(subarray.begin(), subarray.end());
            bool c = true;
            const int s = subarray.size();
            for (int j = 0; j < s-1; j++) {
                if (subarray[j+1]-subarray[j] != subarray[1]-subarray[0]) {
                    c = false;
                    break;
                }
            }
            res[i] = c;
        }

        return res;
    }
};