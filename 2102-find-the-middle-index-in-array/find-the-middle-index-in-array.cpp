class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size(),p=0,sum=0;

        for(int i=0;i<n;i++) sum+=nums[i];

        for(int i=0;i<n;i++){
            p+=nums[i];

            if(p==sum-p+nums[i]) return i;
        }
        return -1;
    }
};