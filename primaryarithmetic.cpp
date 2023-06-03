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
 * Problem Name: Primary Arithmetic
 * Difficulty: 3.0 (Medium)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    while(true) {
        ll A, B;
        cin >> A >> B;
        if(A == 0 && B == 0) break;

        int result = 0;
        ll carry = 0;
        while(A || B) {
            carry += A % 10 + B % 10;
            carry /= 10;
            if(carry) result++;
            A /= 10, B /= 10;
        }

        if(result) cout << result << " carry operation" << (result == 1 ? "" : "s") << "." << endl;
        else cout << "No carry operation." << endl;
    }

    return 0;
}
