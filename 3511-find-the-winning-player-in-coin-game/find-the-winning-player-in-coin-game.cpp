class Solution {
public:
    string winningPlayer(int x, int y) {
        bool alice = std::min(x, y/4)%2;
        return alice ? "Alice" : "Bob";
    }
};