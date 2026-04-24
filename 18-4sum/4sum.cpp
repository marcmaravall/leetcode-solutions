class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        
        std::vector<std::vector<int>> res = {};

        for (int i = 0; i < n-3; i++) {
            for (int j = i+1; j < n-2; j++) {
                if (i != 0 && nums[i] == nums[i-1] || j != i+1 && nums[j] == nums[j-1]) {
                    continue;
                }

                int left = j+1;
                int right = n-1;

                while (left < right) {
                    int64_t current = (int64_t)nums[i] + (int64_t)nums[j] + (int64_t)nums[left] + (int64_t)nums[right];
                    if (current == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        // std::cout << "push: " << nums[i] << " " << nums[j] << "\n";
                        while (left < right && nums[left] == nums[left+1])
                            left++;
                        while (left < right && nums[right] == nums[right-1])
                            right--;
                        
                        left++;
                        right--;
                    } else if (current < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }

        return res;
    }
};