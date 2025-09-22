class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int count=0;
        for(left;left<=right;left++){
            char start=words[left][0];
            char end=words[left][words[left].length()-1];
            if((start=='a' || start=='e' || start=='i' || start=='o' || start=='u') && (end=='a' || end=='e' || end=='i' || end=='o' || end=='u')){
                count++;
            }
        }
        return count;
    }
};