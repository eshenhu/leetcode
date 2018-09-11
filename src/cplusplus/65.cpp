class Solution {
public:
    bool isNumber(string s) {
        int i =0, k =0, len = s.size();
        while(s[i]==' ') i++;
        if(s[i]=='+' || s[i] == '-') i++;
        while(isdigit(s[i])) i++, k++;
        if(s[i] == '.') i++;
        while(isdigit(s[i])) i++, k++;
        if(k ==0) return false;
        if(s[i] == 'e')
        {
            i++, k = 0;
            if(s[i]=='+' || s[i] == '-') i++;
            while(isdigit(s[i])) i++, k++;
            if(k == 0) return false;
        }
        while(s[i] == ' ') i++;
        return i == len;
    }
};

