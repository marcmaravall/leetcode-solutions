class Solution {
public:
    int toDays(const std::string& date) {
        std::array<int, 12> cal = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        std::array<int, 12> prefix {};
        for (int i = 1; i < 12; i++) {
            prefix[i] = prefix[i-1]+cal[i-1];
        }
        int mm = (date[0]-'0')*10+(date[1]-'0');
        int dd = (date[3]-'0')*10+(date[4]-'0');
        return prefix[mm-1]+dd;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aAlice = toDays(arriveAlice);
        int lAlice = toDays(leaveAlice);
        int aBob = toDays(arriveBob);
        int lBob = toDays(leaveBob);
        std::cout << aAlice << " " << lAlice << " " << aBob << " " << lBob << "\n";
        return std::max(std::min(lAlice, lBob)-std::max(aAlice, aBob)+1, 0);
    }
};