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
 * Problem Name: On Average They're Purple
 * Difficulty: 3.2 (Medium)
 * Categories: Graph
 * Algorithms: BFS
 */

int main() {
    init_cin();

    // answer = dist - 1

    int N, M;
    cin >> N >> M;

    vector<vi> cnx(N);

    rep(i, 0, M) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        cnx[a].push_back(b);
        cnx[b].push_back(a);
    }

    queue<int> q;
    vi vis(N);
    q.push(0);
    vis[0] = true;
    int breadth = 0;

    while(!q.empty()) {
        breadth++;

        int n = sz(q);
        while(n--) {
            int curr = q.front(); q.pop();
            for(int& neigh : cnx[curr]) {
                if(vis[neigh]) continue;
                vis[neigh] = true;
                q.push(neigh);
                if(neigh == N - 1) goto done;
            }
        }
    }

    done:
    cout << (breadth - 1) << endl;

    return 0;
}
