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
 * Problem Name: Knight Jump
 * Difficulty: 2.4 (Easy)
 * Categories: 
 * Algorithms: BFS
 */

int main() {
    init_cin();

    int N;
    char board[1000][1000];
    cin >> N;
    N;

    // read board
    for(int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for(int j = 0; j < N; j++) {
            board[i][j] = row[j];
        }
    }

    // BFS
    queue<pii> q;
    unordered_map<int, bool> vis;
    q.push({0, 0});
    vis[0 * N + 0] = true;
    int moves = 0;
    if(board[0][0] == 'K') goto found;

    while(q.size()) {
        moves++;
        int n = q.size();

        while(n--) {
            pii current = q.front(); q.pop();
            int r = current.first;
            int c = current.second;

            for(pii offset : vector<pii> {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, 
                                          {1, 2}, {1, -2}, {-1, 2}, {-1, -2}}) {
                int r1 = r + offset.first;
                int c1 = c + offset.second;

                if(r1 < 0 || r1 >= N || c1 < 0 || c1 >= N) continue;
                if(board[r1][c1] == '#') continue;
                if(board[r1][c1] == 'K') goto found;
                if(vis[r1 * N + c1]) continue;
                vis[r1 * N + c1] = true;
                q.push({r1, c1});
            }
        }
    }

    cout << "-1" << endl;
    return 0;

    found: cout << moves << endl;
    return 0;
}
