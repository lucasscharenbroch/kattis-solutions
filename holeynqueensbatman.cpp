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
 * Problem Name: Holey N-Queens (Batman)
 * Difficulty: 2.4 (Easy)
 * Categories: 
 * Algorithms: Backtracking
 */

int EMPTY = 0, HOLE = 1, QUEEN = 2;

bool safe_cell(vector<vi>& grid, int r, int c) {
    // above
    rep(i, 0, r) if(grid[i][c] == QUEEN) return false;

    // above diagonals
    rep(i, 0, r) {
        int row_diff = r - i;
        if(c - row_diff >= 0 && grid[i][c - row_diff] == QUEEN) return false;
        if(c + row_diff < sz(grid) && grid[i][c + row_diff] == QUEEN) return false;
    }

    return true;
}

void find_solutions(vector<vi>& grid, int& count, int row = 0) {
    if(row == sz(grid)) {
        count++;
        return;
    }

    // try all valid placements of queens in row
    rep(j, 0, sz(grid)) {
        if(grid[row][j] == EMPTY && safe_cell(grid, row, j)) {
            grid[row][j] = QUEEN;
            find_solutions(grid, count, row + 1);
            grid[row][j] = EMPTY;
        }
    }
}

int main() {
    init_cin();

    while(true) {
        int N, M;
        cin >> N >> M;
        if(N == 0 && M == 0) break;

        vector<vi> grid(N, vi(N, EMPTY));

        rep(i, 0, M) {
            int r, c;
            cin >> r >> c;
            grid[r][c] = HOLE;
        }

        int count = 0;

        find_solutions(grid, count);

        cout << count << endl;
    }

    return 0;
}
