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
 * Problem Name: Conquest Campaign
 * Difficulty: 2.2 (Easy)
 * Categories: Graph
 * Algorithms: BFS
 */

int main() {
    init_cin();

    int R, C, N;
    cin >> R >> C >> N;

    vector<bool> vis(R * C);
    queue<int> q;

    rep(i, 0, N) {
        int r, c;
        cin >> r >> c;
        r--, c--; // 1 indexing => 0 indexing
        if(!vis[r * C + c]) {
            vis[r * C + c] = true;
            q.push(r * C + c);
        }
    }

    int num_days = 0;

    while(!q.empty()) {
        num_days++;

        int n = q.size();

        while(n--) {
            int curr = q.front(); q.pop();
            for(pii offset : vector<pii>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
                int r = curr / C + offset.first;
                int c = curr % C + offset.second;

                if(r < 0 || r >= R || c < 0 || c >= C || vis[r * C + c]) continue;

                vis[r * C + c] = true;
                q.push(r * C + c);
            }
        }
    }

    cout << num_days << endl;

    return 0;
}
