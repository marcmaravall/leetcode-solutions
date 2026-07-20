class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        const int n = skills.size();
        std::deque<int> queue;
        for (int i = 1; i < n; i++) 
            queue.push_back(i);
        int winner = 0;
        int winnerCount = 0;
        while (1) {
            int current = queue.front();
            queue.pop_front();
            if (skills[current] < skills[winner]) {
                winnerCount++;
                queue.push_back(current);
            } else {
                winnerCount = 1;
                queue.push_back(winner);
                winner = current;
            }
            if (winnerCount == k || winnerCount >= n-1)
                return winner;
        }
        return -1;
    }
};