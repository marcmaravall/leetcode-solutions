class Solution {
public:
    int addMinimum(string word) {
        int res = 0;
        const int n = word.size();
        for (int i = 0; i < n; i++) {
            char c = word[i];
            if (i < n-2 && c == 'a' && word[i+1] == 'b' && word[i+2] == 'c') {
                i+=2;
                continue;
            } 
            
            if (i < n-1 && c == 'a' && word[i+1] == 'b') {
                i++;
                res++;
                continue;
            } 
            if (i < n-1 && c == 'b' && word[i+1] == 'c') {
                i++;
                res++;
                continue;
            } 
            if (i < n-1 && c == 'a' && word[i+1] == 'c') {
                i++;
                res++;
                continue;
            } 
            
            if (c == 'a') {
                res += 2;
            } else if (c == 'b') {
                res += 2;
            } else if (c == 'c') {
                res += 2;
            }
        }
        return res;
    }
};