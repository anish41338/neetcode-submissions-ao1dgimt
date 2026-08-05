class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int>mpp;
        for(auto i=0;i<order.size();i++){
            mpp[order[i]]=i;
        }
        for(int i=0;i<words.size()-1;i++){
            string w1=words[i];
            string w2=words[i+1];
            for(int j=0;j<w1.size();j++){
                if(j==w2.size())return false;
                if(w1[j]!=w2[j]){
                    if(mpp[w1[j]]>mpp[w2[j]])return false;
                    break;
                }
            }
        }
        return true;
        
    }
};