class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans=INT_MIN,sum=0, mum=INT_MAX, s=0;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans=max(ans,sum);

            s+=nums[i];
            mum=min(mum,s);

            if(s>0) s=0;
            if(sum<0) sum=0;
        }
        return max(abs(mum),ans);
    }
};