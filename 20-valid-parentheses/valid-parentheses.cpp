class Solution {
public:
    bool isValid(string s) {
        vector<char> brackets;
        int size=s.length();
        for(int i=0;i<size;i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                brackets.push_back(s[i]);
            }else if(s[i]==')'){
                if(brackets.size() == 0 || brackets.back()!='(') return false;
                brackets.pop_back();
            }else if(s[i]==']'){
                if(brackets.size() == 0 || brackets.back()!='[') return false;
                brackets.pop_back();
            }else if(s[i]=='}'){
                if(brackets.size() == 0 || brackets.back()!='{') return false;
                brackets.pop_back();
            }
        }
        if(brackets.size()!=0) return false;
        return true;
    }
};