class Solution {
public:
    int countCollisions(string directions) {
        const int n = directions.size();
        int left = 0, right = n-1;
        while (left < n && directions[left] == 'L')
            left++;
        while (right >= 0 && directions[right] == 'R')
            right--;
        int res = 0;
        for (int i = left; i <= right; i++) {
            if (directions[i] != 'S')
                res++;
        }
        return res;
    }
};