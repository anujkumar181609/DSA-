class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n=nums.size(), dist=INT_MAX,max_sum=0;

        for(int i=0;i<n-2;i++){
            int start=i+1,end=n-1;

            while(start<end){
                int sum= nums[start]+nums[end]+nums[i];
                int len= abs(target-sum);

                if(target==sum) return sum;
                else if(len <dist){
                    dist=len;
                    max_sum=sum;
                }
                else if(len==dist) max_sum= max(max_sum,sum);

                if(sum<target) start++;
                else end--;
            }
        }
        return max_sum;
    }
};