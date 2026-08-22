class Solution {
public:
    bool checkDivisibility(int n) {
        long long p=1,s=0,m=n;

        while(n){
            int a=n%10;
            p*=a;
            s+=a;
            n/=10;
        }
        if(m%(p+s)==0) return 1;
        return 0;
    }
};