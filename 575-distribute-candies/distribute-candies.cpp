class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        const int n = candyType.size();
        std::sort(candyType.begin(), candyType.end());
        int types = 0;
        for (int i = 0; i < n; i++) {
            while (i < n-1 && candyType[i] == candyType[i+1]) {
                i++;
            }
            types++;
        }
        return std::min(types, n/2);
    }
};