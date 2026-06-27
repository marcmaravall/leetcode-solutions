class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int res = 0;
        const int n = people.size();
        std::sort(people.begin(), people.end());

        int left = 0;
        int right = n-1;

        while (left <= right) {
            res++;
            int sum = people[left] + people[right];
            if (sum <= limit) {
                left++;
            }
            right--;
        }

        return res;
    }
};