class Solution {
public:

    bool find(string &temp, string &pref){
        for(int j=1;j<temp.size();j++){
            if(j>=pref.size()) return 1;
            if(temp[j]!= pref[j] ) return 0;
        }
        return 1;
    }

    int prefixCount(vector<string>& words, string pref) {
        int count=0;

        for(int i=0;i<words.size();i++){
            string temp=words[i];
            if(temp[0]==pref[0] && temp.size()>= pref.size()){
                if(find(temp,pref)) count++;
            }
        }
        return count;
    }
};