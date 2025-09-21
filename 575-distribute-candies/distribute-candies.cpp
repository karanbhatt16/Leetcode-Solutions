class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        sort(candyType.begin(),candyType.end());
        int curr=candyType[0],count=1;
        for(int i=1;i<candyType.size();i++){
            if(candyType[i]!=curr){
                count++;
                curr=candyType[i];
            }
        }
        if(candyType.size()/2<count) return candyType.size()/2;
        return count;
    }
};