class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n=edges.size(),idx=-1;
        long long a=-1;
        vector<long long>ans(n,0);

        for(int i=0;i<n;i++){
            ans[edges[i]]+= (long long)i;
        }
        for(int i=0;i<n;i++) if(ans[i]>a) a=ans[i], idx=i;
        return idx;

    }
};