class Solution {
public:

    void find(vector<int>&candidates, int index, int target, vector<int>&mum, vector<vector<int>>&ans){
        if(target==0) {
            ans.push_back(mum);
            return;
        }

        if(target<0 || index==candidates.size()) return;

        for(int i=index;i<candidates.size();i++){
            if(candidates[i] > target) break;

            if(i> index && candidates[i]== candidates[i-1]) continue;

            mum.push_back(candidates[i]);
            find(candidates, i+1, target-candidates[i], mum,ans);
            mum.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>>ans;
        vector<int>mum;

        find(candidates, 0, target,mum,ans);
        
        return ans;
    }
};