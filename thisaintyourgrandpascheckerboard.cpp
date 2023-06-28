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
 * Problem Name: This Ain't Your Grandpa's Checkerboard
 * Difficulty: 1.8 (Easy)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    int N;
    cin >> N;

    vector<string> grid(N);

    rep(i, 0, N) cin >> grid[i];

    // check each row
    rep(i, 0, N) {
        int white = (grid[i][N - 1] == 'W') + (grid[i][N - 2] == 'W');
        rep(j, 0, N - 2) {
            white += grid[i][j] == 'W';
            if(grid[i][j] == grid[i][j + 1] && grid[i][j] == grid[i][j + 2]) goto incorrect;
        }
        if(white != N / 2) goto incorrect;
    }

    // check each column
    rep(j, 0, N) {
        int white = (grid[N - 1][j] == 'W') + (grid[N - 2][j] == 'W');
        rep(i, 0, N - 2) {
            white += grid[i][j] == 'W';
            if(grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i + 2][j]) goto incorrect;
        }
        if(white != N/ 2) goto incorrect;
    }

    cout << 1 << endl;
    return 0;
    incorrect: cout << 0 << endl;
    return 0;
}
