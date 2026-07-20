class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        const int n = skills.size();
        int winner = 0;
        int wins = 0;
        for (int i = 1; i < n; i++) {
            if (skills[winner] > skills[i]) {
                wins++;
            } else {
                winner = i;
                wins = 1;
            }
            
            if (wins == k)
                return winner;
        }

        return winner;
    }
};