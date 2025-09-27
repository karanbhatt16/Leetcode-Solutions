class Solution {
public:
    int numberOfChild(int n, int k) {
        k=k%((n-1)*2);
        if(k>(n-1)){
            k=k%(n-1);
            return n-k-1;
        }
        return k;
    }
};