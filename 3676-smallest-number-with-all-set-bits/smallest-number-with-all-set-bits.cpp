class Solution {
public:
    int smallestNumber(int n) {
        int num=0;
        int p=1;
        while(n!=0){
            n=n>>1;
            num=num+p;
            p=p*2;
        }
        return num;
    }
};