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
 * Problem Name: Cantina of Babel
 * Difficulty: 3.0 (Medium)
 * Categories: SCC, Graph
 * Algorithms: Tarjan's Algorithm
 */

void dfs(int i, int N, vi& id, stack<int>& s, vector<bool>& on_stack, 
         vi& low, vi& speaks, unordered_map<int, vi>& can_hear, int& new_id) {

    low[i] = id[i] = new_id++;
    s.push(i);
    on_stack[i] = true;

    for(int& neigh : can_hear[speaks[i]]) {
        if(id[neigh] == 0) dfs(neigh, N, id, s, on_stack, low, speaks, can_hear, new_id);
        if(on_stack[neigh]) low[i] = min(low[i], low[neigh]);
    }

    if(low[i] == id[i]) { // new SCC
        while(s.top() != i) {
            low[s.top()] = id[i];
            on_stack[s.top()] = false; s.pop();
        }
        on_stack[i] = false; s.pop();
    }
}

int largest_scc(int N, vi& speaks, unordered_map<int, vi>& can_hear) {
    vector<bool> on_stack(N, false);
    stack<int> s;
    vi low(N), id(N);
    int new_id = 1;

    // set low to SCC id.
    rep(i, 0, N) if(id[i] == 0) dfs(i, N, id, s, on_stack, low, speaks, can_hear, new_id);

    // find the size of the largest SCC
    unordered_map<int, int> scc_size;
    int largest = 0;
    rep(i, 0, N) largest = max(largest, ++scc_size[low[i]]);
    return largest;
}

int main() {
    init_cin();

    int N;
    cin >> N >> ws;

    unordered_map<string, int> id; // id of each langage
    int new_id = 1;
    vi speaks(N);
    unordered_map<int, vi> can_hear;

    rep(i, 0, N) {
        string l;
        getline(cin, l);
        stringstream ls(l);

        string name;
        ls >> name; // ignore name

        string lang;
        ls >> lang >> ws;
        if(id[lang] == 0) id[lang] = new_id++;
        speaks[i] = id[lang];
        can_hear[id[lang]].push_back(i);

        while(!ls.eof()) {
            string lang;
            ls >> lang >> ws;
            if(id[lang] == 0) id[lang] = new_id++;
            can_hear[id[lang]].push_back(i);
        }
    }

    cout << (N - largest_scc(N, speaks, can_hear)) << endl;

    return 0;
}
