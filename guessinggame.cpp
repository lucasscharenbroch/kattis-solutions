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
 * Problem Name: Guessing Game
 * Difficulty: 3.0 (Medium)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    while(true) {
        int G;
        cin >> G;
        if(G == 0) break;

        int low = 0, high = 11;

        while(true) {
            string s;
            cin >> ws; // skip whitespace
            getline(cin, s);

            if(s == "right on") break;
            else if(s == "too high") high = min(high, G);
            else low = max(low, G);

            cin >> G;
        }

        if(!(low < G) || !(G < high) || !(low < high)) cout << "Stan is dishonest" << endl;
        else cout << "Stan may be honest" << endl;
    }

    return 0;
}
