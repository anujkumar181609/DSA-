class Solution {
public:

    void find(vector<int>&arr,int index, int &k, int n, vector<int>&mum, vector<vector<int>>&ans){
        if(n==0){
            if(mum.size()==k) ans.push_back(mum);
            return;
        }
        if(index==arr.size() || n<0) return;

        find(arr,index+1, k, n, mum,ans);

        mum.push_back(arr[index]);
        find(arr,index+1, k, n-arr[index],mum,ans);

        mum.pop_back();
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>arr;

        for(int i=1;i<=9;i++) arr.push_back(i);

        vector<vector<int>>ans;
        vector<int>mum;

        find(arr,0,k,n,mum,ans);
        return ans;
    }
};