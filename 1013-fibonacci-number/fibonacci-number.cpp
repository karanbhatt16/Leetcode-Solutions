class Solution {
public:
    int fibonacci(int n, vector<int>& v){
        if(n<=1) return n;
        int left,right;
        if(v[n-1] != -1) left=v[n-1];
        else left=fibonacci(n-1,v);
        if(v[n-2] != -1) right=v[n-2];
        else right=fibonacci(n-2,v);
        v[n]=left+right;
        return left+right;
    }
    int fib(int n) {
        vector<int> v(n+1,-1);
        return fibonacci(n,v);
    }
};