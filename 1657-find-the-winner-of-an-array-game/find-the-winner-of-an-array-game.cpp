class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        const int n = arr.size();
        int winner = arr[0];
        int wins = 0;
        for (int i = 1; i < n && wins != k; i++) {
            if (arr[i] < winner) {
                wins++;
            } else {
                winner = arr[i];
                wins = 1;
            }
        }
        return winner;
    }
};