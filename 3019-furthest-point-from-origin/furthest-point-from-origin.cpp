class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int freq[3] = { 0, 0, 0 };

        for (char c : moves) {
            if (c == 'L')
                freq[0]++;
            else if (c == 'R')
                freq[1]++;
            else 
                freq[2]++;
        }

        int _max = max(freq[0], freq[1]);
        int _min = min(freq[0], freq[1]);
        return _max - _min + freq[2];
    }
};