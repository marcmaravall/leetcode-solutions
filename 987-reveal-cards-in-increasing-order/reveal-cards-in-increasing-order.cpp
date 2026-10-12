class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        std::sort(deck.rbegin(), deck.rend());
        std::deque<int> d;
        d.push_back(deck[0]);
        const int n = deck.size();
        for (int i = 1; i < n; i++) {
            d.push_front(d.back());
            d.pop_back();
            d.push_front(deck[i]);
        }
        std::vector<int> res(d.begin(), d.end());
        return res;
    }
};