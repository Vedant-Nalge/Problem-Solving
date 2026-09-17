class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long  sum = 0;
        priority_queue<int> pq;
        for (int x : gifts) {
            sum += x;
            pq.push(x);
        }

        while (k--) {
            int node = pq.top();
            pq.pop();
            int a = sqrt(node);
            pq.push(a);
            sum += a - node;
        }

        return sum;
    }
};