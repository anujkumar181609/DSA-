class Solution {
public:

    int find(vector<int>&nums, int k){
        int start=0,end= 0, n=nums.size(), size=0;
        unordered_map<int,int>m;

        while(end<n){
            m[nums[end]]++;

            while(start<=end && m.size()>k){
                m[nums[start]]--;
                if(m[nums[start]]==0) m.erase(nums[start]);
                start++;
            }
            size+=end-start+1;
            end++;
        }
        return size;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return find(nums,k)- find(nums,k-1);
    }
};