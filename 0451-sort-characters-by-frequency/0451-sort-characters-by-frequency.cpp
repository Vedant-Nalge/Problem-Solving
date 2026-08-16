class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> mpp;
        priority_queue<pair<int, char>> pq;

        for (char ch : s) {
            mpp[ch]++;
        }

        for (auto it : mpp) {
            pq.push({it.second, it.first});
        }
        string ans = "";
        while (!pq.empty()) {
            int frq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();

            for (int i = 0; i < frq; i++) {
                ans += ch;
            }
        }

        return ans;
    }
};