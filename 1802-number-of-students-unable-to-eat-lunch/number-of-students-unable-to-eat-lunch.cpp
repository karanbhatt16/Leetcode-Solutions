class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zero=0;
        int one=0;
        for(int i=0;i<students.size();i++){
            if(students[i]==0){
                zero++;
            }
        }
        one=students.size()-zero;
        for(int i=0;i<sandwiches.size();i++){
            if(sandwiches[i]==0){
                if(zero==0){
                    return sandwiches.size()-i;
                }
                zero--;
            }else{
                if(one==0){
                    return sandwiches.size()-i;
                }
                one--;
            }
        }
        return 0;
    }
};