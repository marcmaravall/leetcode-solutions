class Solution {
public:
    bool isCircularSentence(string sentence) {
        char first = sentence[0];
        const int n = sentence.size();
        for (int i = 0; i < n; i++) {
            if ((sentence[i] == ' ' && sentence[i-1] != sentence[i+1]) ||
                (i == n-1 && sentence[i] != first))
                return false;
        }
        return true;
    }
};