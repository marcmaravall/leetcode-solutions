class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        std::sort(score.begin(), score.end(), [&](std::vector<int>& a, std::vector<int>& b) {
            return a[k] > b[k];
        });
        
        return score;
    }
};