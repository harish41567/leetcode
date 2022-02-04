class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map(128,0);
        int counter=0, begin=0, end=0, d=0; 
        
        while(end<s.size()){
            if(map[s[end]] > 0) 
                counter++; 
            
            map[s[end]]++;
            end++;
            
            while(counter>0) {
                if(map[s[begin]] > 1) 
                    counter--;
                
                map[s[begin]]--;
                
                begin++;
            }
            d=max(d, end-begin); //while valid, update d
        }
        return d;
    }
};