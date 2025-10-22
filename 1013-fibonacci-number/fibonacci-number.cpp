class Solution {
public:
    int fibonacci(int n, vector<int>& v){
        if(n<=1) return n;
        if(v[n]!=-1) return v[n];
        v[n]=fibonacci(n-1,v)+fibonacci(n-2,v);
        return v[n];
    }
    int fib(int n) {
        vector<int> v(n+1,-1);
        return fibonacci(n,v);
    }
};