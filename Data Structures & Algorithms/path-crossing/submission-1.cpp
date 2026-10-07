class Solution {
public:
    bool isPathCrossing(string path) {
        // path is n s e w
        //start at 0,0, walk on path specificed
        int x = 0, y = 0;
        set<pair<int,int>> sets;
        sets.insert({x,y});

        for (char c : path){
            if (c=='N'){
                y+=1;
            } else if (c=='S') {
                y-=1;
            }else if (c=='E') {
                x+=1;
            }else {
                x-=1;
            }
            if (sets.find({x,y}) != sets.end()){
                return true;
            }
            sets.insert({x,y});
        }
        return false;
    }
};