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
 * Problem Name: Circuit Math
 * Difficulty: 2.1 (Easy)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    int N;
    cin >> N;

    vi input;
    char c;
    rep(i, 0, N) {
        cin >> c;
        input.push_back(c == 'T');
    }

    vector<char> circuit;

    while(!(cin >> ws).eof()) {
        cin >> c;
        circuit.push_back(c);
    }

    vi stack;

    rep(i, 0, sz(circuit)) {
        if(circuit[i] >= 'A' && circuit[i] <= 'Z') {
            stack.push_back(input[circuit[i] - 'A']);
        } else if(circuit[i] == '-') {
            int back = stack.back(); stack.pop_back();
            stack.push_back(!back);
        } else if(circuit[i] == '*') { // and
            int a = stack.back(); stack.pop_back();
            int b = stack.back(); stack.pop_back();
            stack.push_back(a && b);
        } else if(circuit[i] == '+') { // or
            int a = stack.back(); stack.pop_back();
            int b = stack.back(); stack.pop_back();
            stack.push_back(a || b);
        } else assert(false);
    }

    cout << (stack[0] ? 'T' : 'F') << endl;

    return 0;
}
