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
 * Problem Name: Code Guessing
 * Difficulty: 3.0 (Medium)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    int a1, a2;
    cin >> a1 >> a2;
    if(a1 > a2) swap(a1, a2);

    string s;
    cin >> s;

    if(s == "ABBA" && a2 - a1 == 3) {
        cout << (a1 + 1) << " " << (a1 + 2) << endl;
    } else if(s == "ABAB" && a1 == 6) {
        cout << "7 9" << endl;
    } else if(s == "BABA" && a2 == 4) {
        cout << "1 3" << endl;
    } else if(s == "BBAA" && a1 == 3) {
        cout << "1 2" << endl;
    } else if(s == "AABB" && a2 == 7) {
        cout << "8 9" << endl;
    } else if(s == "BAAB" && a1 == 2 && a2 == 8) {
        cout << "1 9" << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
