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
 * Problem Name: 4 thought
 * Difficulty: 3.2 (Medium)
 * Categories: Search
 * Algorithms: Backtracking, Shunting Yard
 */

void exec_operator(vi& num_stack, vector<char>& op_stack) {
    char o = op_stack.back(); op_stack.pop_back();
    int b = num_stack.back(); num_stack.pop_back();
    int a = num_stack.back(); num_stack.pop_back();

    if(o == '+') num_stack.push_back(a + b);
    else if(o == '-') num_stack.push_back(a - b);
    else if(o == '*') num_stack.push_back(a * b);
    else if(o == '/') num_stack.push_back(a / b);
}

int eval(vector<char>& ops) {
    vi num_stack;
    vector<char> op_stack;

    rep(i, 0, sz(ops)) {
        num_stack.push_back(4);

        while(sz(op_stack) &&
             (op_stack.back() == '*' || op_stack.back() == '/') >=
             (ops[i] == '*' || ops[i] == '/')) exec_operator(num_stack, op_stack);

        op_stack.push_back(ops[i]);
    }

    num_stack.push_back(4);

    while(sz(op_stack)) exec_operator(num_stack, op_stack);

    return num_stack[0];
}

void search(vector<char>& ops, unordered_map<int, string>& eq) {
    if(sz(ops) == 3) {
        char s[30];
        int solution = eval(ops);
        sprintf(&s[0], "4 %c 4 %c 4 %c 4 = %d", ops[0], ops[1], ops[2], solution);
        eq[solution] = s;
        return;
    }

    for(char& c : vector<char> {'+', '-', '*', '/'}) {
        ops.push_back(c);
        search(ops, eq);
        ops.pop_back();
    }
}

int main() {
    init_cin();

    int T;
    cin >> T;

    unordered_map<int, string> eq; // map result to equation
    vector<char> ops; // used operators

    search(ops, eq);

    while(T--) {
        int N;
        cin >> N;

        cout << (sz(eq[N]) ? eq[N] : "no solution") << endl;
    }

    return 0;
}
