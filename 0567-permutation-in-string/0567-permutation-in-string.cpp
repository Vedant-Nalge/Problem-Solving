class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<int> count1(26, 0);
        vector<int> count2(26, 0);
        
        if (m > n) return false;

        for(int i = 0 ; i< m ; i++){
            count1[s1[i]-'a']++;
            count2[s2[i] - 'a']++;
        }

        for(int i = 0 ; i <= n-m ;i++){
            if(count1 == count2 ) return true;

            if(i+ m <n){
                count2[s2[i+m] - 'a']++;
                count2[s2[i]-'a']--;
            }
            
        }
        return false;
    }
};