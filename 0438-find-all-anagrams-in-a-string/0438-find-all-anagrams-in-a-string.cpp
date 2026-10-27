class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();

        if(m>n) return {};

        vector<int> ans;

        vector<int> pfreq(26,0);
        vector<int> winfreq(26,0);

        for(int i = 0 ; i< m ; i++){
            pfreq[p[i]-'a']++;
            winfreq[s[i]-'a']++;
        }
        if(winfreq==pfreq) ans.push_back(0);
        for(int i = m ; i<n ; i++){
            winfreq[s[i]-'a']++;
            winfreq[s[i-m]-'a']--;

            if(pfreq==winfreq) ans.push_back(i-m+1);
        }
        return ans;
    }
};