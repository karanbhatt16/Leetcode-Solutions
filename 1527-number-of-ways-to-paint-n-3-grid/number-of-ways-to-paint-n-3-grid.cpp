class Solution {
public:
    int numOfWays(int n) {
        const long long MOD=1000000007;
        long long a=6,b=6;
        for (int i=2;i<=n;i++) {
            long long temp=a;
            a = ((temp*3)%MOD+(b*2)%MOD)%MOD;
            b = ((temp*2)%MOD+(b*2)%MOD)%MOD;
        }
        return (a+b)%MOD;
    }
};
