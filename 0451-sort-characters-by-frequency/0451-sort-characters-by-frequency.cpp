class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char, int> mpp;

        for (auto c : s) {
            mpp[c]++;
        }
        // mpp has char ,frq
        priority_queue<pair<int,char>> pq;
        for (auto it : mpp) {
            char ch = it.first;
            int frq = it.second;
            pq.push({frq, ch});
        }
        string ans = "";
        while (!pq.empty()) {
            char ch = pq.top().second;
            int frq = pq.top().first;
            pq.pop();
            while (frq > 0) {
                ans += ch;
                frq--;
            }
        }
        return ans;
    }
};