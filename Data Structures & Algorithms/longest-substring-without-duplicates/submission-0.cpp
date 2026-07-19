class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        vector<int> hash(256,0);
        int l=0;
        int r=0;
        int maxlen=0;
        while(r<n){
            if(hash[s[r]]==0){
                hash[s[r]]=1;
                maxlen=max(maxlen,r-l+1);
                r++;
            }
            else{
                while(hash[s[r]]==1){
                    hash[s[l]]=0;
                    l++;
                }
            }
        }
        return maxlen;
    }
};
