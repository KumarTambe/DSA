
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> stack;
        vector<pair<int,int>> cars;
        for(int i=0;i<position.size();i++){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.rbegin(),cars.rend());
        for(int i=0;i<cars.size();i++){
            double timeReq = (double)(target - cars[i].first)/cars[i].second;
            if(stack.empty() || timeReq > stack.top()){
                stack.push(timeReq);
            } else if(timeReq<=stack.top()){
                continue;
            }
        }
        return stack.size();
    }
};


