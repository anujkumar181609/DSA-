class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string temp;
        int start=0,end=0,n=s.size(),count=0;
        vector<pair<int,string>>ans;

        while(end<n){
            if(s[end]=='1') count++;
            temp+=s[end];

            while(start<=end && count==k){
                int size= end-start+1;
                ans.push_back({size,temp});

                if(s[start]=='1') count--;
                temp.erase(0,1);
                start++;
            }
            end++;
        }
        if(ans.size()==0) return "";
        sort(ans.begin(),ans.end());
        return ans[0].second;
    }
};