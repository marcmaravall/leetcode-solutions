class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int left = 0;
        int right = n-1;
        bool found = false;

        while (left <= right) {
            int mid = (left+right)/2;
            if (nums[mid] == target) {
                left = right = mid;
                found = true;
                break;
            }
            else if (nums[mid] < target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }

        if (!found)
            return {-1, -1};

        while (left != 0 && nums[left-1] == target)
            left--;
        while (right != n-1 && nums[right+1] == target)
            right++;

        return {left, right};
    }
};