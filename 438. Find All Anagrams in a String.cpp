class Solution {
public:
    bool areSame(vector<int> cp, vector<int> cs){
        for(int i=0;i<26;i++)
        {
            if(cp[i]!=cs[i])
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> v,cp(26),cs(26);
        
        if(s.length()<p.length())
           return v;
        
        for(int i=0;i<p.length();i++)
        {
            cp[p[i]-'a']++;
            cs[s[i]-'a']++;
        }
        
        if(areSame(cp,cs))
                v.push_back(0);
    
        for(int i=p.length();i<s.length();i++)
        {
            cs[s[i]-'a']++;
            cs[s[i-p.length()]-'a']--;
            
            if(areSame(cp,cs))
                v.push_back(i-p.length()+1);
        }
        
        return v;
    }
};