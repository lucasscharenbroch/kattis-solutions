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
 * Problem Name: Pear-wise Voting
 * Difficulty: 4.1 (Medium)
 * Categories: Graph
 * Algorithms: 
 */

int main() {
    init_cin();

    int N, M;
    cin >> N >> M;

    vector<vi> ballots(M, vi(N)); // ballots[i] = {permutation of integers [0, N)}
                                  // representing the position of the letters on
                                  // the respective ballot
    vi ballot_cnts(M);

    rep(i, 0, M) {
        cin >> ballot_cnts[i];
        string S;
        cin >> S;
        rep(j, 0, sz(S)) ballots[i][S[j] - 'A'] = j;
    }

    // create a graph with candidates as vertices.
    // add an edge from x to y iff x can beat y
    // candidate z can win iff d can reach all other nodes

    vector<vi> cnx(N);
    rep(i, 0, N) rep(j, 0, N) {
        int i_cnt = 0, j_cnt = 0;

        rep(m, 0, M) {
            i_cnt += (ballots[m][i] < ballots[m][j]) * ballot_cnts[m];
            j_cnt += (ballots[m][i] > ballots[m][j]) * ballot_cnts[m];
        }

        if(i_cnt > j_cnt) cnx[i].push_back(j);
        else cnx[j].push_back(i);
    }

    // bfs to check for connectivity for each node

    rep(i, 0, N) {
        queue<int> q;
        q.push(i);
        vector<bool> vis(N);
        int num_vis = 0;

        while(!q.empty()) {
            int curr = q.front(); q.pop();

            for(int& neigh : cnx[curr]) {
                if(vis[neigh]) continue;
                vis[neigh] = true;
                num_vis++;
                q.push(neigh);
            }
        }

        cout << (char)('A' + i) << ": can" << (num_vis == N ? "" : "'t") << " win" << endl;
    }

    return 0;
}
