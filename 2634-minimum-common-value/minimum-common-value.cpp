class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        const int n1 = nums1.size();
        const int n2 = nums2.size();
        
        int i = 0, j = 0;

        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) 
                i++;
            else if (nums2[j] < nums1[i]) 
                j++;
            
            if (i < n1 && j < n2 && nums1[i] == nums2[j])
                return nums1[i];
        }

        return -1;
    }
};