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
 * Problem Name: Land Equality
 * Difficulty: 5.5 (Hard)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    int R, C;
    cin >> R >> C;

    int num_0 = 0, num_1 = 0, num_2 = 0;
    vi grid(R * C);

    rep(i, 0, R * C) {
        cin >> grid[i];
        if(grid[i] == 0) num_0++;
        else if(grid[i] == 1) num_1++;
        else if(grid[i] == 2) num_2++;
    }

    if(num_0 >= 2) cout << 0 << endl;
    else if(num_0 == 1) {
        if(R != 1 && C != 1) {
            if(num_1) cout << 1 << endl;
            else cout << 2 << endl;
        } else { // single row/col, one zero
            auto zero_pos = find(all(grid), 0);
            if(zero_pos == grid.begin()) cout << grid[R * C - 1] << endl;
            else if(zero_pos == grid.end() - 1) cout << grid[0] << endl;
            else cout << min(grid[0], grid[R * C - 1]) << endl;
        }
    } else { // just 1s and 2s
        if(num_2 % 2 == 0) cout << 0 << endl;
        else {
            ll better = 1LL << ((num_2 + 1) / 2); // score of better part
            ll worse = 1LL << (num_2 / 2); // score of worse part
            cout << (better - worse) << endl;
        }
    }

    return 0;
}
