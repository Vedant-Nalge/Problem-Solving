class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int window = n-k;
        int totsum =0;
        for(int x : cardPoints){
            totsum+=x;
        }

        if(window ==0) return totsum;

        int windsum =0;
        for(int i =0;i<window;i++){
            windsum+=cardPoints[i];
        }

        int mini = windsum;

        for(int i = window ;i<n;i++){
            windsum += cardPoints[i] - cardPoints[i - window];
            mini = min(mini,windsum);
        }


        return totsum - mini;
        
    }
};