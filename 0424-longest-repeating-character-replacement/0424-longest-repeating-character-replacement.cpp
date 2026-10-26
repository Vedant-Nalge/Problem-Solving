class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0 ;
        int maxf = 0;
        vector<int> hash(26,0);
        int maxlen = 0;
        for(int r = 0; r<n ;r++){
            hash[s[r]-'A']++;
            maxf = max(maxf,hash[s[r]-'A']);

            if(r-l+1 - maxf > k){
                hash[s[l]-'A']--;
                l++;
            }
            else maxlen = max(maxlen,r-l+1);
        }
        return maxlen;
    }
};