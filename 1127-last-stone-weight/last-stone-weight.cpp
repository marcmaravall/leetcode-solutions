class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int, std::vector<int>> pqueue(stones.begin(), stones.end());
        while (pqueue.size() > 1) {
            int x = pqueue.top();
            pqueue.pop();
            int y = pqueue.top();
            pqueue.pop();
            pqueue.push(x-y);
        }
        return pqueue.top();
    }
};