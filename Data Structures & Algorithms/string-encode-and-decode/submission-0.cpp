class Solution {
public:

    string encode(vector<string>& strs) {
        string s="";
        for(auto x:strs){
            s+=to_string(x.size())+"#"+x;
        }
        return s;

    }

    vector<string> decode(string s) {
        vector<string>res;
        int i=0,n=s.size();
        while(i<n){
            int j=i;
            while(s[j]!='#')j++;
            int len=stoi(s.substr(i,j-i));
            string word=s.substr(j+1,len);
            res.push_back(word);
            i=j+1+len;

        }return res;

    }
};
