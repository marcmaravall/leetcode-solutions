class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0, b = 0;
        const int n = colors.size();
        for (int i = 1; i < n-1; i++) {
            char c1 = colors[i-1], c2 = colors[i], c3 = colors[i+1];
            if (c1 == 'A' && c2 == 'A' && c3 == 'A')
                a++;
            else if (c1 == 'B' && c2 == 'B' && c3 == 'B')
                b++;
        }
        return a > b;
    }
};