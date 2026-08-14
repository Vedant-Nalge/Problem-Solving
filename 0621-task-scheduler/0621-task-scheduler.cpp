class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // 1. Count frequency of each task
        vector<int> freq(26, 0);

        for (char c : tasks) {
            freq[c - 'A']++;
        }

        // 2. Max heap stores frequencies
        priority_queue<int> pq;

        for (int f : freq) {
            if (f > 0)
                pq.push(f);
        }

        int time = 0;

        
        while (!pq.empty()) {

          
            vector<int> temp;

            int cnt = 0;

            
            while (cnt <= n && !pq.empty()) {

                
                int f = pq.top();
                pq.pop();

               
                f--;

              
                if (f > 0)
                    temp.push_back(f);

                time++;
                cnt++;
            }

            
            for (int f : temp) {
                pq.push(f);
            }

            if (!pq.empty()) {
                time += (n + 1 - cnt);
            }
        }

        return time;
    }
};