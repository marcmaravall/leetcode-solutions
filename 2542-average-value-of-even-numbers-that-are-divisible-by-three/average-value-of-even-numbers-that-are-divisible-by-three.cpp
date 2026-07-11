class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0;
        int size = 0;
        for (int num : nums) {
            if (num % 2 == 0 && num % 3 == 0) {
                sum += num;
                size++;
            }
        }
        if (size == 0)
            return 0;
        return sum/size;
    }
};