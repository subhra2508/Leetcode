class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        vector<string>vStore;
        string sNew = "";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                vStore.push_back(sNew);
                sNew = "";
            }
            else{
                sNew+=s[i];
            }
        }
        vStore.push_back(sNew);
        
        if(pattern.size() != vStore.size())return false;
        unordered_map<string,char>wc;
        unordered_map<char,string>cw;
         
        for(int i=0;i<pattern.length();i++){
             if(wc.count(vStore[i]) == 0){
                 if(cw.count(pattern[i]) == 0){
                     wc.insert({vStore[i],pattern[i]});
                     cw.insert({pattern[i],vStore[i]});
                 }
                 else{
                     return false;
                 }
             }
            else{
                if(cw.count(pattern[i])==0 || wc[vStore[i]] != pattern[i]){
                    return false;
                }
            }
        }
        return true;
    }
};