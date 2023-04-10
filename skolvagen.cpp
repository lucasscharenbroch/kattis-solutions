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
 * Problem Name: Going to School
 * Difficulty: 3.5
 * Categories: Dijkstra's
 * Algorithms: 
 */

int main() {
    init_cin();

    string S;
    cin >> S;
    int N = sz(S);

    bool is_north = true;

    vector<vector<pii>> cnx((N + 1) * 2);

    rep(i, 0, sz(S)) {
        int h = 0, l = 0;
        if(S[i] == 'B') h = l = 1;
        else if(S[i] == 'N') h = 1;
        else l = 1;

        // north/south crosswalks (always 1 weight)
        cnx[i * 2].push_back(pii(i * 2 + 1, 1));
        cnx[i * 2 + 1].push_back(pii(i * 2, 1));

        // east/west
        cnx[i * 2].push_back(pii((i + 1) * 2, h));
        cnx[i * 2 + 1].push_back(pii((i + 1) * 2 + 1, l));
    }

    // last n/s crossings
    cnx[N * 2].push_back(pii(N * 2 + 1, 1));
    cnx[N * 2 + 1].push_back(pii(N * 2, 1));

    int s = 0, t = N * 2;

    // find shortest path from s to t
    vi dist(N * 2 + 2, INT_MAX);
    priority_queue<pii, vector<pii>, std::greater<pii>> q;
    q.push(pii(s, 0));

    while(!q.empty()) {
        auto [cost, curr] = q.top(); q.pop();
        if(dist[curr] <= cost) continue; // already visited
        dist[curr] = cost;
        if(curr == t) break;

        for(auto& [neigh, d] : cnx[curr]) {
            if(cost + d < dist[neigh]) q.push(pii(cost + d, neigh));
        }
    }

    cout << dist[t] << endl;

    return 0;
}
