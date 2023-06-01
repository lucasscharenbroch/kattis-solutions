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
 * Problem Name: e-Coins
 * Difficulty: 5.1 (Medium)
 * Categories: Search
 * Algorithms: BFS
 */

int main() {
    init_cin();

    double epsilon = 1e-6;

    int T;
    cin >> T;

    while(T--) {
        int M, S;
        cin >> M >> S;

        vector<pii> coins(M);
        rep(i, 0, M) cin >> coins[i].first >> coins[i].second;
        vector<vi> vis(S + 1, vi(S + 1));

        queue<pii> q;
        q.push(pii(0, 0));
        vis[0][0] = true;
        int breadth = 0;

        while(!q.empty()) {
            breadth++;
            int n = sz(q);

            while(n--) {
                auto [x, y] = q.front(); q.pop();
                for(auto [dx, dy] : coins) {
                    int nx = x + dx, ny = y + dy;
                    if(abs(sqrt(nx * nx + ny * ny) - S) < epsilon) {
                        cout << breadth << endl;
                        goto next_testcase;
                    } else if(sqrt(nx * nx + ny * ny) > S || vis[nx][ny]) continue;
                    vis[nx][ny] = true;
                    q.push(pii(nx, ny));
                }
            }
        }

        cout << "not possible" << endl;
        next_testcase:;
    }

    return 0;
}
