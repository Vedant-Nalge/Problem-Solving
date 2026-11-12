class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq; // min heap {capital,profit}
        for (int i = 0; i < profits.size(); i++) {
            pq.push({capital[i], profits[i]});
        }
        priority_queue<int> q; // max heap for profits

        while (k > 0) {
            // in each step ,i will put all the things that are <=w in max heap
            // and then choose the max profit and add it to w , like this i will
            // do until all k are exhausted
            while (!pq.empty() && w >= pq.top().first) {
                q.push(pq.top().second);
                pq.pop(); // need to remove it too
            }
            if (q.size() == 0)
                break;
            w += q.top();
            q.pop(); // need to remove the used one
            k--;
        }
        return w;
    }
};