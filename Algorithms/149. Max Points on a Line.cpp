class Solution {
public:
    int gcd(int a,int b){
        if(b == 0)  return a;
        return gcd(b,a%b);
    }
    int maxPoints(vector<vector<int>>& points) {
        map<pair<int,int>,int> pointCount;
        for(int i = 0;i < points.size();){
            auto it = pointCount.find(make_pair(points[i][0],points[i][1]));
            if(it == pointCount.end()){
                pointCount[make_pair(points[i][0],points[i][1])] = 1;
                i++;
            }
            else{
                (*it).second++;
                points.erase(points.begin() + i);
            }
        }
        if(points.size() == 0)  return 0;
        if(points.size() == 1)  return pointCount[make_pair(points[0][0],points[0][1])];
        int maxPoint = 0;
        for(int i = 0;i < points.size();i++){
            map<pair<int,int>,int> slopeMap;
            for(int j = i+1;j < points.size();j++){
                int y = points[j][1] - points[i][1];
                int x = points[j][0] - points[i][0];
                if(x == 0){
                    y = 1;
                }
                if(y == 0){
                    x = 0;
                }
                if(x!=0 && y!=0){
                    int common = gcd(x,y);
                    y /= common;
                    x /= common;
                }
                if((x < 0 && y < 0) || x < 0 ){
                    x*=-1;
                    y*=-1;
                }
                auto it = slopeMap.find(make_pair(y,x));
                if(it == slopeMap.end())
                    slopeMap[make_pair(y,x)] = pointCount[make_pair(points[i][0],points[i][1])] + pointCount[make_pair(points[j][0],points[j][1])];
                else
                    (*it).second+= pointCount[make_pair(points[j][0],points[j][1])];
                int currCount = slopeMap[make_pair(y,x)];
                if(currCount > maxPoint)
                    maxPoint = currCount;
            }
        }
        return maxPoint;
    }
};