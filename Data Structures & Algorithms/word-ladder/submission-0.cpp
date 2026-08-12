class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        if(!st.count(endWord))return 0;
        int res=1;
        map<string,set<string>>mpp;
        for(auto it:wordList){
            for(int j=0;j<it.size();j++){
                string pattern=it.substr(0,j)+"*"+it.substr(j+1);
                mpp[pattern].insert(it);
            }
        }
        set<string>vis;
        vis.insert(beginWord);
        queue<string>q;
        q.push(beginWord);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                string word=q.front();
                q.pop();
                if(word==endWord)return res;
                for(int j=0;j<word.size();j++){
                    string pattern=word.substr(0,j)+"*"+word.substr(j+1);
                    for(auto w:mpp[pattern]){
                        if(!vis.count(w)){
                            vis.insert(w);
                            q.push(w);
                        }
                    }

                }
            }
            res++;
        }
        return 0;
    }
};
