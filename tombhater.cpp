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
 * Problem Name: Tomb Hater
 * Difficulty: 7.3 (Hard)
 * Categories: Search, String Matching
 * Algorithms: BFS
 */

struct trie_node {
    vector<trie_node *> children;
    trie_node(): children(27, nullptr) { }
};

trie_node eow; // placeholder node to put at children[26]

int main() {
    init_cin();

    int R, C, K;
    cin >> R >> C >> K;

    vector<vector<char>> grid(R, vector<char>(C));
    rep(i, 0, R) rep(j, 0, C) cin >> grid[i][j];

    vector<string> words(K);
    rep(i, 0, K) cin >> words[i];

    trie_node t;
    // build t from words
    for(auto& word : words) {
        trie_node *curr = &t;
        rep(i, 0, sz(word)) {
            int c = word[i] - 'A';
            if(curr->children[c] != nullptr) curr = curr->children[c];
            else curr = curr->children[c] = new trie_node();
        }
        curr->children[26] = &eow;
    }

    // directions
    int DOWN = 0;
    int LEFT = 1;
    int RIGHT = 2;

    // bfs from top row
    queue<pair<pair<pii, int>, set<trie_node *>>> q;
    vector<unordered_map<trie_node *, bool>> vis(R * C * 3); // for each cell, for each direction

    set<trie_node *> t_set = {&t};
    rep(j, 0, C) q.push(pair<pair<pii, int>, set<trie_node *>>(pair<pii, int>(pii(0, j), DOWN), t_set));
    int breadth = 0;

    while(sz(q)) {
        breadth++;
        int n = sz(q);

        while(n--) {
            auto [pos_dir, tnodes] = q.front(); q.pop();
            auto [pos, dir] = pos_dir;
            auto& [i, j] = pos;

            int c = grid[i][j] - 'A';
            bool is_eow = false;

            set<trie_node *> next_tnodes;

            for(auto node : tnodes) {
                if(node->children[c] == nullptr) continue; // can't continue along this node-path
                node = node->children[c];
                next_tnodes.insert(node);
                if(node->children[26] != nullptr) is_eow = true;
            }

            if(is_eow) next_tnodes.insert(&t); // can match the word and return to top of trie

            if(is_eow && i == R - 1) goto found_path;
            if(!sz(next_tnodes)) continue;

            for(auto [dr, dc] : vector<pii>{{1, 0}, {0, 1}, {0, -1}}) {
                int new_dir = dr == 1 ? DOWN : dc == 1 ? RIGHT : LEFT;

                // can't go back in same direction
                if(dir == RIGHT && new_dir == LEFT) continue;
                if(dir == LEFT && new_dir == RIGHT) continue;

                int r = i + dr, c = j + dc;
                if(r < 0 || c < 0 || r >= sz(grid) || c >= sz(grid[0])) continue;

                set<trie_node *> dir_tnodes;

                for(auto node : next_tnodes) {
                    if(vis[(r * C + c) + R * C * new_dir][node]) continue;
                    vis[(r * C + c) + R * C * new_dir][node] = true;
                    dir_tnodes.insert(node);
                }

                if(sz(dir_tnodes)) {
                    q.push(pair<pair<pii, int>, set<trie_node *>>(pair<pii, int>(pii(r, c), new_dir), dir_tnodes));
                }
            }
        }
    }

    cout << "impossible" << endl;
    return 0;

    found_path:
    cout << breadth << endl;

    return 0;
}
