class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1){
            return x;
        }
        int i;
        for(i=2;i<x;i++){
            if(int(x/i)<int(i)){
                break;
            }
        }
        return i-1;
    }
};