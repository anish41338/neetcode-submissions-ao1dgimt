class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,float>>car;
        for(int i=0;i<position.size();i++){
            float time=(float)(target-position[i])/speed[i];
            car.push_back({position[i],time});
        }
        sort(car.rbegin(),car.rend());
        float prev=0;
        int fleet=0;
        for(auto cars:car){
            float curtime=cars.second;
            if(curtime>prev){
                fleet++;
            prev=curtime;}

        }
        return fleet;
    }
};
