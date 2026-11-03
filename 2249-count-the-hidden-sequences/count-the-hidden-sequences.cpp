class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        const int n = differences.size();
        long long min = INT_MAX, max = INT_MIN;
        long long last = 0;
        for (int i = 0; i < n; i++) {
            long long cur = differences[i]+last;
            min = std::min(min, last);
            max = std::max(max, last);
            last = cur;
        }
        min = std::min(min, last);
        max = std::max(max, last);
        long long diff = max-min;
        if (upper-lower < diff) {
            return 0;
        }
        return upper-lower-diff+1;
    }
};