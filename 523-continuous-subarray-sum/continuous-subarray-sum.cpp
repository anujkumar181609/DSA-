class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int n=nums.size(), p=0;

        m[0]=-1;

        for(int i=0;i<n;i++){
            p+=nums[i];

            int rem= p%k;
            if(rem<0) rem+=k;

            if(m.count(rem)){
                if(i-m[rem]>1) return 1;
            }
            else m[rem]=i;
        }
        return 0;
    }
};