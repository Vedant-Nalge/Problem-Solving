class Solution {
public:
    int minOperations(string s) {

        int ans =INT_MAX;
        int n =s.size();
        for(int k =0;k<n;k++){
           int  cost =k;
           for(int i =0;i<n/2;i++){
            int left = (k+i)%n;
            int right = (k+n-1-i)%n;

            int a = s[left] -'a';
            int b = s[right] - 'a';

            int d1 = (a-b+26)%26;
            int d2 =(b-a+26)%26;

            cost+=min(d1,d2);
           }

           ans = min(ans,cost);

        }
        return ans;
        
    }
};