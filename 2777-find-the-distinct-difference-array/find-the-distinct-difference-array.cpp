class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        std::unordered_map<int,int> mp, rmp;
        for (auto x : nums) {
            rmp[x]++;
        }
        const int n = nums.size();
        std::vector<int> res(n);
        int i = 0;
        for (auto x : nums) {
            mp[x]++;
            rmp[x]--;
            if(rmp[x] == 0) { 
                rmp.erase(x);
            }
            res[i++] = mp.size()-rmp.size();
        }
        return res;
    }
};