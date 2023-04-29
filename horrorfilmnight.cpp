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
 * Problem Name: Horror Film Night
 * Difficulty: 3.5 (Medium)
 * Categories: Greedy
 * Algorithms: 
 */

int main() {
    init_cin();

    vector<vector<bool>> films(1000000, vector<bool>(2));

    rep(j, 0, 2) {
        int k; cin >> k;
        rep(l, 0, k) {
            int i; cin >> i;
            films[i][j] = 1;
        }
    }

    int result = 0;

    pii last = pii(1, 1); // who liked the last flim

    rep(i, 0, sz(films)) {
        if(films[i][0] == 0 && films[i][1] == 0) continue;
        if(films[i][0] == 0 && last.first == 0) continue;
        if(films[i][1] == 0 && last.second == 0) continue;
        last = pii(films[i][0], films[i][1]);
        result ++;
    }

    cout << result << endl;

    return 0;
}
