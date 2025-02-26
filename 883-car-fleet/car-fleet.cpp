class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,float>> vp;
        for(int i=0;i<position.size();i++){
            vp.push_back({position[i],(target-position[i])/(1.0*speed[i])});
        }
        sort(vp.begin(),vp.end(),greater<pair<int,int>>());
        int car_fleet_count=1;
        float fleet_speed = vp[0].second;
        for(int i=1;i<position.size();i++){
            //compare speeds
            if(vp[i].second > fleet_speed){
                car_fleet_count++;
                fleet_speed = vp[i].second;
            }
        }
        return car_fleet_count;
    }
};