class Solution {
public:
    int divide(int dividend, int divisor) {
        int cnt=0;
        int sign=true;
        int d=dividend;
        if(dividend>=0 && divisor<0) sign=false;
        if(dividend<0 && divisor>0) sign=false;
        if(dividend==INT_MIN){
            dividend=abs(dividend+1);
        }
        dividend=abs(dividend);
        if(divisor==INT_MIN) return d==INT_MIN?1:0;
        divisor=abs(divisor);
        while(dividend>=(divisor<<cnt) && (divisor<<cnt)<1073741824){
            cnt++;
        }
        int ans=0;
        while(cnt>=0){
            ans=ans<<1;
            if(dividend>=(divisor<<cnt)){
                dividend=dividend-(divisor<<cnt);
                ans=ans+1;
            }
            cnt--;
        }
        if(d==INT_MIN && dividend+1==divisor && !sign) return (-1)*ans-1;
        return sign?ans:(-1)*ans;
    }
};