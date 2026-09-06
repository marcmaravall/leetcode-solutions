class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        std::vector<int> res(num_people);
        for (int i = 1; candies > 0; i++) {
            int index = (i-1)%num_people;
            if (candies-i >= 0)
                res[index] += i;
            else res[index] += candies;
            candies -= i;
        }
        return res;
    }
};