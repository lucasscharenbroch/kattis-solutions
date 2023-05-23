#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void init_cin() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
}

/*
 * Problem Name: Medals
 * Difficulty: 6.1 (Hard)
 * Categories: 
 * Algorithms: 
 */

int score(vi& weight, vi& medals) {
    int res = 0;
    rep(i, 0, 3) res += weight[i] * medals[i];
    return res;
}

bool can_win(vi& weight, vector<vi>& medals, int canada_idx) {
    int can_score = score(weight, medals[canada_idx]);

    rep(i, 0, sz(medals)) {
        if(i == canada_idx) continue;
        if(score(weight, medals[i]) > can_score) return false;
    }

    return true;
}

int main() {
    init_cin();

    while(true) {
        int C;
        cin >> C;
        if(!C) break;

        int can_idx = -1;
        vector<vi> medals(C, vi(3));

        rep(i, 0, C) {
            string country;
            cin >> country >> medals[i][0] >> medals[i][1] >> medals[i][2];
            if(country == "Canada") can_idx = i;
        }

        vi weights = {1, 100, 10000};
        if(can_idx == -1) goto lose;

        rep(i, 0, 3) rep(j, 0, 3) rep(k, 0, 3) {
            vi w = {weights[i], weights[j], weights[k]};
            if(can_win(w, medals, can_idx)) goto win;
        }

        lose:
        cout << "Canada cannot win." << endl;
        continue;
        win:
        cout << "Canada wins!" << endl;
    }

    return 0;
}
