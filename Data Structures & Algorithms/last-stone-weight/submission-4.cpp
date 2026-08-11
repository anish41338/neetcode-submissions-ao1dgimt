class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>q;
        for(auto it:stones)q.push(it);
        while(q.size()!=1){
            int t1=q.top();
            q.pop();
            int t2=q.top();
            q.pop();
            if(t1==t2){
                if(q.size()==0){return 0;}
                else continue;
            }
            else if(t1<t2){q.push(t2-t1);}
            else{q.push(t1-t2);}
        }
        return q.top();
    }
};
