class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> v = {a,b,c};
        sort(begin(v),end(v));
        int x = v[0],y = v[1], z = v[2];
        if(x+1 == y and y+1 == z) return vector<int>({0,0});
        
        int _min = 2,_max;
        if(z-y == 2 or y -x == 2 or y-x == 1 or z-y == 1) _min = 1;
        _max = (y-x-1) + (z-y-1);
        
        return vector<int>({_min,_max});
    }
};


