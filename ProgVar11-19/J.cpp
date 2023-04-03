#include <iostream>
#include <map>
#include <vector>
using namespace std;

int w, h, n, x1, y1, x2, y2, hori, vert, counter;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> w >> h >> n;

    map<vector<int>, vector<vector<int>>> g;

    vector<vector<int>> cX;
    vector<vector<int>> cY;

    map<vector<int>, int> v;

    hori = 0;
    vert = 0;

    for(int i=0; i<n; i++){
        cin >> x1 >> y1 >> x2 >> y2;

        g[{x1,y1}].push_back({x2,y2});
        g[{x2,y2}].push_back({x1,y1});

        v[{x1,y1}] = 0;
        v[{x2,y2}] = 0;

        if(x1 == 0){
            cX.push_back({x1,y1});
        }
        if(x2 == 0){
            cX.push_back({x2,y2});
        }
        if(y1 == 0){
            cY.push_back({x1,y1});
        }
        if(y2 == 0){
            cY.push_back({x1,y1});
        }

    }
    counter = 0;
    for(auto i : cX){
        if(v[{i[0], i[1]}] == 0){
            counter++;

            v[{i[0],i[1]}] == counter;

            
        }
    }

    if(hori == 1 && vert == 1){
        cout << "N" << endl;
    }else{
        cout << "Y" << endl;
    }
}
