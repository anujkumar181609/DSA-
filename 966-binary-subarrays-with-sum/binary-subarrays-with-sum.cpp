class Solution {
public:

    int find(vector<int>&nums,int goal){
        int start=0,end=0, n=nums.size(), count =0, el=0;

        while(end<n){
            if(nums[end]==1) el++;
            
            while(start<=end && el>goal){
                if(nums[start]==1) el--;
                start++;
            }
            count += end-start+1;
            end++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return find(nums,goal)- find(nums,goal-1);
    }
};