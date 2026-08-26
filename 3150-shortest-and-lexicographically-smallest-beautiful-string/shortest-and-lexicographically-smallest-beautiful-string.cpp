class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        
        int start=0,end=0,len=INT_MAX,count=0;
        string ans="";

        while(end<s.size()){
            if(s[end]=='1') count++;

            while(start<=end && count==k){
                int size= end-start+1;
                string temp= s.substr(start,size);

                if(len > size){
                    len=size;
                    ans=temp;
                }
                else if(len==size){
                    if(ans=="" || temp < ans) ans=temp;
                }

                if(s[start]=='1') count--;
                start++;
            }
            end++;
        }
        
        
        return ans;
    }
};