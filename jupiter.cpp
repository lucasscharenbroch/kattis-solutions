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
 * Problem Name: Jupiter Orbiter
 * Difficulty: 6.1 (Hard)
 * Categories: Network Flow
 * Algorithms: Dinic's
 */

struct edge {
    int from, to, flow, cap;
    edge(int from, int to, int flow, int cap) : from(from), to(to), flow(flow), cap(cap) { }
};

int MAX_N = 30 * 31 + 2;

vector<edge> edges;
vector<vi> cnx(MAX_N);
vi level(MAX_N);
vi vis(MAX_N);
int vis_id = 1;
int s, t;

void add_edge(int from, int to, int cap) {
    cnx[from].push_back(edges.size());
    edges.push_back(edge(from, to, 0, cap));
    cnx[to].push_back(edges.size());
    edges.push_back(edge(to, from, 0, 0));
}

bool bfs() {
    queue<int> q;
    q.push(s);
    vis[s] = ++vis_id;
    int l = 0;

    while(!q.empty()) {
        int n = q.size();
        l++;

        while(n--) {
            int curr = q.front(); q.pop();
            level[curr] = l;
            if(curr == t) return true;

            for(int& edge_id : cnx[curr]) {
                int neigh = edges[edge_id].to, edge_cap = edges[edge_id].cap - edges[edge_id].flow;
                if(vis[neigh] == vis_id || !edge_cap) continue;
                q.push(neigh);
                vis[neigh] = vis_id;
            }
        }
    }

    return false;
}

int dfs(int curr, int flow_in) {
    if(curr == t) return flow_in;

    for(int& edge_id : cnx[curr]) {
        int neigh = edges[edge_id].to, edge_cap = edges[edge_id].cap - edges[edge_id].flow;
        if(!edge_cap || level[curr] + 1 != level[neigh]) continue;

        int f;
        if(f = dfs(neigh, min(flow_in, edge_cap))) {
            edges[edge_id].flow += f; edges[edge_id ^ 1].flow -= f;
            return f;
        } else level[neigh] = -1;
    }

    return 0;
}

int calc_max_flow() {
    int max_flow = 0;

    while(bfs()) {
        int f;
        while(f = dfs(s, INT_MAX)) max_flow += f;
    }

    return max_flow;
}

int main() {
    init_cin();

    // represent this problem as a network: there are N columns of nodes, with (Q + 1) rows each,
    // where the the node @ (q, n) represents the q'th queue at after the n'th downlink.
    // and the node @ (Q + 1, n) represents the bottleneck node for total data downlinked.

    // the node @ the 0th - qth row of each col (except the last) is connected to the corresponding
    // queue in the next col (weight = (queue-sz - sum-of-edges-from-sink-into-node-in-next-col))

    // the (q + 1)th column of each row has an outgoing edge to t (the sink), whose weight is the
    // maximum data transfer in the given downlink period.

    // the new data coming into each queue after each downlink is represented as an edge from S
    // into the corresponding node.

    int N, Q, S;
    cin >> N >> Q >> S;

    s = N * Q + N, t = s + 1;

    vi s_to_q(S);
    vi q_sz(Q);

    rep(i, 0, S) { cin >> s_to_q[i]; s_to_q[i]--; }

    // read queue sizes and add edges between columns
    rep(j, 0, Q) cin >> q_sz[j];

    // add edges from queues to bottleneck-nodes
    rep(i, 0, N) {
        rep(j, 0, Q) {
            add_edge(i * Q + j, N * Q + i, INT_MAX);
        }
    }

    int total_info = 0;

    // read downlink amounts and new data amounts, add edges
    rep(i, 0, N) {
        int x;
        cin >> x; // mb for i'th downlink
        add_edge(N * Q + i, t, x); // col-bottleneck-node -> t

        vi mb_into_q(Q);

        rep(j, 0, S) {
            cin >> x;
            total_info += x;
            mb_into_q[s_to_q[j]] += x;
        }

        rep(j, 0, Q) {
            if(q_sz[j] < mb_into_q[j]) goto impossible; // q cannot hold new data

            if(i != 0) // add edge from last column to this column
                add_edge((i - 1) * Q + j, i * Q + j, q_sz[j] - mb_into_q[j]);

            add_edge(s, i * Q + j, mb_into_q[j]); // add edge with new mb from s to this node
        }
    }

    if(calc_max_flow() != total_info) goto impossible;

    cout << "possible" << endl;
    return 0;

    impossible:
    cout << "impossible" << endl;
    return 0;
}
