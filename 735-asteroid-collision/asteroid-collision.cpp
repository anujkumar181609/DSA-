class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        int n=asteroids.size();

        for(int i=0;i<n;i++){
            if(asteroids[i]>0) ans.push_back(asteroids[i]);
            
            else{
                int flag=0;
                while(!ans.empty() && ans.back()>0){
                    if(abs(asteroids[i]) < ans.back()) {
                        flag=1;
                        break;
                    }
                    else if(abs(asteroids[i])> ans.back()) ans.pop_back();
                    else {
                        ans.pop_back();
                        flag=1;
                        break;
                    }
                }
                if(flag==0) ans.push_back(asteroids[i]);
            }
        }
        return ans;
    }
};