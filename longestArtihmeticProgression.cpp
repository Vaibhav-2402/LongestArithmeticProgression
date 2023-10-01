class Solution{   
public:

    int solve(int index, int diff, int arr[], unordered_map<int,int> dp[]) {
        if(index < 0)
            return 0;
            
        if(dp[index].count(diff))
            return dp[index][diff];
            
        int ans = 0;
            
        for(int i = index-1; i >= 0; i--) {
            if(arr[index] - arr[i] == diff) {
                ans = max(ans, 1 + solve(i, diff, arr, dp) );
            }
        }
        
        dp[index][diff] = ans;
        return dp[index][diff];
    }
    int lengthOfLongestAP(int A[], int n) {
        
        if(n <= 2)
            return n;
        
        int ans = 0;
        
        unordered_map<int, int> dp[n+1];
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                ans = max(ans, 2 + solve(i, A[j] - A[i], A, dp) );
            }
        }
        
        return ans;
    }
};

//also one possible solution
int lengthOfLongestAP(int A[], int n) {
       if(n <= 2)
        return n;
        
    unordered_map<int,int> dp[n+1];
    int ans = 0;
    
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            int diff = A[i] - A[j];
            int cnt = 1;
            
            if(dp[j].count(diff))
                cnt = dp[j][diff];
            
            dp[i][diff] = 1 + cnt;
            ans = max(ans, dp[i][diff]);
        }
    }
    return ans;
    }