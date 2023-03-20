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
 * Problem Name: Emptying The Baltic
 * Difficulty: 5.6 (Hard)
 * Categories: Graph
 * Algorithms: BFS
 */

vector<pii> offsets = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

int main() {
    init_cin();

    int R, C;
    cin >> R >> C;

    vector<vi> a(R, vi(C));

    rep(i, 0, R) rep(j, 0, C) cin >> a[i][j];

    int I, J;
    cin >> I >> J;
    I--, J--;

    // bfs from (I, J), greedily choosing nodes from the queue with minimal altitude
    priority_queue<pii> q;
    vector<bool> vis(R * C);
    q.push({-a[I][J], I * C + J});
    vis[I * C + J] = true;

    ll drainage = 0;

    while(!q.empty()) {
        pii top = q.top(); q.pop();
        int curr = top.second, max_out = top.first;
        int i = curr / C, j = curr % C;
        drainage += max_out;

        for(auto& [ro, co] : offsets) {
            int r = i + ro, c = j + co;
            if(r >= R || r < 0 || c >= C || c < 0 || vis[r * C + c]) continue;
            if(-a[r][c] <= 0) continue; // non-negative altitude
            q.push(pii(min(max_out, -a[r][c]), r * C + c));
            vis[r * C + c] = true;
        }
    }

    cout << drainage << endl;

    return 0;
}
