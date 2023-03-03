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
 * Problem Name: 2048
 * Difficulty: 3.0 (Medium)
 * Categories: 
 * Algorithms: 
 */

void compress(int grid[4][4], int r0, int c0, pii inc) {
    vi stack;
    int ir = inc.first, ic = inc.second;
    bool compressed_last = false;

    rep(i, 0, 4) {
        int current = grid[r0 + i * ir][c0 + i * ic];
        if(current == 0) continue;

        if(sz(stack) && current == stack[sz(stack) - 1] && !compressed_last) { // compress matches
            stack[sz(stack) - 1 ] *= 2;
            compressed_last = true;
        } else {
            stack.push_back(current); // otherwise add to stack
            compressed_last = false;
        }
    }

    while(sz(stack) < 4) stack.push_back(0); // fill remaining cells with 0

    // copy stack back to grid row/col
    rep(i, 0, 4) grid[r0 + i * ir][c0 + i * ic] = stack[i];
}

int main() {
    init_cin();

    int grid[4][4];
    int M; // move (direction)

    // read grid
    rep(i, 0, 4) rep(j, 0, 4) {
        cin >> grid[i][j];
    }

    cin >> M;

    if(M == 0) { // left
        rep(i, 0, 4) compress(grid, i, 0, pii{0, 1});
    } else if(M == 1) { // up
        rep(i, 0, 4) compress(grid, 0, i, pii{1, 0});
    } else if(M == 2) { // right
        rep(i, 0, 4) compress(grid, i, 3, pii{0, -1});
    } else { // down
        rep(i, 0, 4) compress(grid, 3, i, pii{-1, 0});
    }

    // print board
    rep(i, 0, 4) {
        rep(j, 0, 4) cout << grid[i][j] << (j == 3 ? "" : " ");
        cout << endl;
    }

    return 0;
}
