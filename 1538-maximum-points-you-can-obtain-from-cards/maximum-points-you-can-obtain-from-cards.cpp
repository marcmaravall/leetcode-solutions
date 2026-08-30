class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        const int n = cardPoints.size();
        const int s = n-k;
        int sum = std::accumulate(cardPoints.begin(), cardPoints.begin()+s, 0);
        int minSum = sum;
        for (int i = s; i < n; i++) {
            sum -= cardPoints[i-s];
            sum += cardPoints[i];
            minSum = std::min(minSum, sum);
        }
        int total = std::accumulate(cardPoints.begin(), cardPoints.end(), 0);
        return total-minSum;
    }
};