class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=INT_MIN,sum=0;
        int start=0,end=0;

        while(end<nums.size()){
            sum+=nums[end];

            if(start<=end && end-start+1==k){
                ans=max(ans,sum/k);

                sum-=nums[start];
                start++;
            }
            end++;
        }
        return ans;
    }
};