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
 * Problem Name: Ants
 * Difficulty: 2.4 (Easy)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    int T;
    cin >> T;

    while(T--) {
        // ignore collision of ants - "walking in opposite directions" can instead
        // be though of as "walking through"
        //
        // earliest time: farthest distance of any ant from an edge
        // latest time: (length of pole) - (smallest length between ant and edge)

        int L, N;
        cin >> L >> N;

        int farthest_from_edge = 0;
        int closest_to_edge = INT_MAX;

        while(N--) {
            int pos; // position of ant
            cin >> pos;

            farthest_from_edge = max(farthest_from_edge, min(pos, L - pos));
            closest_to_edge = min(closest_to_edge, min(pos, L - pos));
        }

        cout << farthest_from_edge << " " << L - closest_to_edge << endl;
    }

    return 0;
}
