class Solution {
public:
    string longestPalindrome(string s) {
        string temp=s;
        reverse(temp.begin(), temp.end());

        int n=temp.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==temp[j-1]) dp[i][j]= 1+dp[i-1][j-1];
                else dp[i][j]= 0;
            }
        }

        int max_length=0, best_start=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int len=dp[i][j];

                if( len >0 && i-len== n-j) {
                    if(len > max_length){
                        max_length= len;
                        best_start= i-len;
                    }
                }
            }
        }
        if(max_length==0) return "";
        return s.substr(best_start, max_length);
    }
};