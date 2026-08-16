class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int mod[3] = { 0, 0, 0 };
        for (int stone : stones)
            mod[stone%3]++;
        if (mod[0] % 2 == 0)
            return mod[1] != 0 && mod[2] != 0;
        return std::abs(mod[1]-mod[2]) > 2;
    }
};