class Solution {
public:
    bool isPalindrome(string s) {
        int l=0;
        for(int i=0;i<s.length();i++){
            if(!(s[i]>='a'&&s[i]<='z')&&!(s[i]>='A'&&s[i]<='Z')&&!(s[i]>='0'&&s[i]<='9')){
                s.erase(i,1);
                i--;
            }
        }
        int r=s.length()-1;
        while(l<=r){
            if(tolower(s[l])==tolower(s[r])){
                l++;
                r--;
            }
            else return false;
        }
        return true;
    }
};
