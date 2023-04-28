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
 * Problem Name: Frosh Week
 * Difficulty: 5.2 (Medium)
 * Categories: Divide & Conquer
 * Algorithms: Merge Sort / Inversion Count
 */

ll inv_count = 0;

void msort(vi& a, int s, int e) {
    assert(s < e); // TODO remove (debug)
    if(e - s == 1) return;

    int ls = s, le = s + (e - s) / 2;
    int rs = s + (e - s) / 2, re = e;

    msort(a, ls, le);
    msort(a, rs, re);

    vi merged(e - s);
    rep(i, s, e) {
        if(rs != re && (ls == le || a[ls] > a[rs])) {
            inv_count += le - ls;
            merged[i - s] = a[rs++];
        } else merged[i - s] = a[ls++];
    }

    rep(i, s, e) a[i] = merged[i - s]; // copy merged into a
}

int main() {
    init_cin();

    int N;
    cin >> N;

    vi a(N);

    rep(i, 0, N) cin >> a[i];

    // use merge-sort to count the number of inversions in a
    msort(a, 0, sz(a));

    cout << inv_count << endl;

    return 0;
}
