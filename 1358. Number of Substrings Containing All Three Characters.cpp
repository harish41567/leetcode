class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        
        vector<int> c={0,0,0};
        int i=0,j=0,res=0;
        
        for(int j=0;j<n;j++){
            c[s[j]-'a']++;
            
            while(c[0] && c[1] && c[2]){
                
                c[s[i]-'a']--;
                i++;
            }
            
            res+=i;
        }
        return res;
    }
};