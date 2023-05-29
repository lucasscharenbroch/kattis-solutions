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
 * Problem Name: Erdos Numbers
 * Difficulty: 5.2 (Medium)
 * Categories: Graph
 * Algorithms: BFS
 */

int main() {
    init_cin();

    vector<string> authors;
    vector<vector<string>> coauthors;
    unordered_map<string, int> author_id; // unique positive id for every author
    int new_id = 1;
    vi degree(2000 * 600, INT_MAX); // author-id to degree-from-erdos

    while(!(cin >> ws).eof()) {
        string l;
        getline(cin, l);
        stringstream ls(l);

        string name;
        ls >> name;
        authors.push_back(name);
        coauthors.push_back(vector<string>());
        if(author_id[name] == 0) author_id[name] = new_id++;

        while(!(ls >> ws).eof()) {
            string name;
            ls >> name;
            if(author_id[name] == 0) author_id[name] = new_id++;
            coauthors.back().push_back(name);
        }
    }

    // build cnx
    vector<vi> cnx(new_id - 1);
    rep(i, 0, sz(authors)) rep(j, 0, sz(coauthors[i])) {
        int id = author_id[authors[i]] - 1;
        int neigh = author_id[coauthors[i][j]] - 1;
        cnx[id].push_back(neigh);
        cnx[neigh].push_back(id);
    }

    // bfs from erdos
    int s = author_id["PAUL_ERDOS"] - 1;
    queue<int> q;
    vi vis(sz(cnx));
    q.push(s);
    vis[s] = true;
    int breadth = -1;

    while(!q.empty()) {
        int n = sz(q);
        breadth++;

        while(n--) {
            int curr = q.front(); q.pop();
            degree[curr] = breadth;

            for(int& neigh : cnx[curr]) {
                if(vis[neigh]) continue;
                vis[neigh] = true;
                q.push(neigh);
            }
        }
    }

    rep(i, 0, sz(authors)) {
        cout << authors[i] << " ";
        int deg = degree[author_id[authors[i]] - 1];
        if(deg == INT_MAX) cout << "no-connection";
        else cout << deg;
        cout << endl;
    }

    return 0;
}
