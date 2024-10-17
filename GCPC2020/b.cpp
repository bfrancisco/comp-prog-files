#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, X, Y;
    cin >> N >> X >> Y;

    vector<pair<int, int>> books(N); // {y, x}
    int i;
    for (i = 0; i < N; i++){
        cin >> books[i].second >> books[i].first;
    }
    sort(books.begin(), books.end());

    int thresh = Y/2;
    int h;
    int ans = -1;
    int botsm, topsm;
    for (h = 0; h < thresh; h++){
        vector<int> bot;
        botsm = 0;
        topsm = 0;
        for (i = 0; i < N; i++){
            if (books[i].first <= h){
                bot.push_back(books[i].second);
            }
            else{
                topsm += books[i].second;
            }
        }

        sort(bot.begin(), bot.end(), greater<int>());
        
        for (int i = 0; i < bot.size(); i++){
            if (botsm <= topsm) botsm += bot[i];
            else topsm += bot[i];
        }

        if (topsm <= X && botsm <= X){
            ans = h;
            break;
        }
    }
    
    if (ans != -1){
        cout << (ans==0 ? -1 : ans);
        return 0;
    }

    for (h = thresh+1; h < Y; h++){
        vector<int> top;
        botsm = 0;
        topsm = 0;
        for (i = 0; i < N; i++){
            if (books[i].first <= h){
                botsm += books[i].second;
            }
            else{
                top.push_back(books[i].second);
            }
        }

        sort(top.begin(), top.end(), greater<int>());

        for (i = 0; i < top.size(); i++){
            if (topsm + top[i] <= X) topsm += top[i];
            else botsm += top[i];
        }

        for (int i = 0; i < top.size(); i++){
            if (botsm <= topsm) botsm += top[i];
            else topsm += top[i];
        }

        if (botsm <= X && topsm <= X){
            ans = h;
            break;
        }
    }

    if (ans == -1) cout << "impossible";
    else if (ans == 0) cout << -1;
    else cout << ans;

    return 0;
}