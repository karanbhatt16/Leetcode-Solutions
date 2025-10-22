class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1) return n;
        vector<int> v(3);
        v[0]=0;
        v[1]=1;
        for(int i=2;i<=n;i++){
            v[2]=v[0]+v[1];
            v[0]=v[1];
            v[1]=v[2];
        }
        return v[2];
    }
};