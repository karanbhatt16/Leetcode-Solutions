class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0,num=n;
        int prod=1;
        int rem=0;
        while(n){
            rem=n%10;
            n/=10;
            sum+=rem;
            prod*=rem;
        }
        return num%(sum+prod)==0;
    }
};