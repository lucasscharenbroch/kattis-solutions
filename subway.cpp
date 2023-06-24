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
 * Problem Name: Subway Tree System
 * Difficulty: 4.7 (Medium)
 * Categories: Divide and Conquer
 * Algorithms: 
 */

string sort_tree(string s) {
    if(s == "01") return s;

    // find subtrees
    vector<string> subtrees;
    string curr = "";
    int depth = 0;
    rep(i, 0, sz(s)) {
        depth += s[i] == '0' ? 1 : -1;
        curr += s[i];
        if(depth == 0) {
            subtrees.push_back(curr);
            curr = "";
        }
    }

    if(sz(subtrees) == 1) return "0" + sort_tree(s.substr(1, sz(s) - 2)) + "1";
    for(string& subtree : subtrees) {
        subtree = sort_tree(subtree);
    }

    sort(all(subtrees));

    string result = "";
    rep(i, 0, sz(subtrees)) result += subtrees[i];
    return result;
}

int main() {
    init_cin();

    int T;
    cin >> T;

    while(T--) {
        string A, B;
        cin >> A >> B;

        cout << (sort_tree(A) == sort_tree(B) ? "same" : "different") << endl;
    }

    return 0;
}
