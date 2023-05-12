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
 * Problem Name: Brexit Negotiations
 * Difficulty: 5.3 (Medium)
 * Categories: Graph, Greedy
 * Algorithms: Topological Sort
 */

int main() {
    init_cin();

    int N;
    cin >> N;

    vi indegrees(N);
    vector<vi> cnx(N);
    vi costs(N);

    rep(i, 0, N) {
        int n;
        cin >> costs[i] >> n;
        rep(j, 0, n) {
            int other;
            cin >> other;
            cnx[i].push_back(other - 1); // 1 --> 0
            indegrees[other - 1]++;
        }
    }

    // do a reverse topological sort, greedily picking the node with minimal cost.
    priority_queue<pii, vector<pii>, greater<pii>> q; // {cost, index} pairs
    rep(i, 0, N) if(!indegrees[i]) q.push(pii(costs[i], i));

    int result = 0;
    for(int recap_time = N; recap_time --> 0;) {
        auto [cost, curr] = q.top(); q.pop();
        result = max(result, cost + recap_time);

        for(int& neigh : cnx[curr]) {
            if(!--indegrees[neigh]) q.push(pii(costs[neigh], neigh));
        }
    }

    cout << result << endl;

    return 0;
}
