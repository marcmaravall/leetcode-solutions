class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int lefts = 0;
        int rights = 0;
        int _ = 0;

        for (char c : moves) {
            if(c == 'L') 
                lefts++;
            else if(c == 'R') 
                rights++;
            else 
                _++;
        }
        return abs(lefts - rights) + _;
    }
};