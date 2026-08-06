class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int num=n;
            int prod=1,rem;
            while(num){
                rem=num%10;
                num/=10;
                prod*=rem;
            }
            if(prod%t==0){
                return n;
            }
            n++;
        }
        return 0;
    }
};