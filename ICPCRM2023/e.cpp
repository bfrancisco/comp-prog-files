#include<bits/stdc++.h>
using namespace std;

int P, N;
vector<tuple<int, int, int>> inp;
vector<vector<vector<pair<int, int>>>> stations;

int main(){
    cin >> P >> N;
    stations.assign(2, vector<vector<pair<int, int>>>(P));

    for (int i = 0; i < N; i++){
        int ti, fi;
        char di;
        cin >> ti >> fi >> di;
        inp.push_back(tuple<int,int,int>(ti,fi,(di=='L' ? 0 : 1)));
    }

    // cout << get<0>(inp[0]) << " " << get<1>(inp[0]) << endl;

    for (int t = 1; t <= 100100; t++){
        // subtract time for each station, if any
        for (int i = 0; i < 2; i++){
            for (int p = 0; p < P; p++){
                for (int j = 0; j < 2; j++){
                    if (stations[i][p].size() >= j+1){
                        stations[i][p][j].second -= 1;
                    }
                }
            }
        }

        // remove already done cars
        for (int i = 0; i < 2; i++){
            for (int p = 0; p < P; p++){
                for (int j = 0; j < 2; j++){
                    if (stations[i][p].size() >= j+1){
                        if (stations[i][p][j].second == 0){
                            stations[i][p].erase(stations[i][p].begin() + j);
                        }
                    }
                }
            }
        }
    }

    return 0;
}