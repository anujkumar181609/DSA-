class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count=0, start=0,end=0, n=nums.size(), size=0;

        while(end<n){
            if(nums[end]==0) count++;

            while(start<=end && count>k){
                if(nums[start]==0) count--;
                start++;
            }
            size=max(size, end-start+1);
            end++;
        }
        return size;
    }
};