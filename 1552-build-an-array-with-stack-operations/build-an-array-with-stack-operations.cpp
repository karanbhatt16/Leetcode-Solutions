class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> v;
        int j=0;
        for(int i=1;i<=n;i++){
            if(j==target.size()){
                break;
            }
            v.push_back("Push");
            if(target[j]!=i){
                v.push_back("Pop");
            }else{
                j++;
            }
        }
        return v;
    }
};