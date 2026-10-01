class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) {
            return false;
        }

        string last = "";

        while (s.size() != 0) {
            for (int i = 0; i < s.size(); i++) {
                if (!nextIsValid(s[i], s[i+1])) {
                    return false;
                }

                if (nextIsCloseType(s[i], s[i+1])) {
                    s.erase(s.begin()+i, s.begin()+i+2);
                    i-=2;
                    if (s.size() == 0)
                        return true;
                }
            }
            if (s == last)
                return false;
            last = s;
        }

        return true;
    }

    inline bool isCloseType(char c) {
        return (c == '}' || c == ']' || c == ')');
    }

    inline bool isOpenType(char c) {
        return (c == '(' || c == '{' || c == '[');
    }

    bool nextIsValid(char c, char next) {
        if (isOpenType(c) && isCloseType(next)) {
            return nextIsCloseType(c, next);
        }
        return true;
    }
    
    inline bool nextIsCloseType(char open, char next) {
        if (open == '{') return next == '}';
        if (open == '[') return next == ']';
        if (open == '(') return next == ')';

        return false;   // 
    }
};