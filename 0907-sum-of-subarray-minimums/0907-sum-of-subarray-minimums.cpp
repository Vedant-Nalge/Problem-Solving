class Solution {
    long long MOD = 1e9 +7;
    vector<int> nse(vector<int> & arr){
        int n =arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = n-1;i>=0;i--){
            int curr = arr[i];

            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }

            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }

        return ans;
    }

     vector<int> psee(vector<int> & arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = 0;i<n;i++){
            int curr = arr[i];

            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }

            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }

        return ans;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> ns = nse(arr);
        vector<int> ps = psee(arr);


        long long ans=0;

        for(int i =0;i<n;i++){
            long long left = i - ps[i];
            long long  right = ns[i] - i;

            ans = (ans + (1LL * arr[i] * left % MOD) * right % MOD) % MOD;

        }
        return ans;



    }
};