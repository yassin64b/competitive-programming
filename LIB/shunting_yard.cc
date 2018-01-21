map<char, int> prec{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

int shuntyard(stringstream& ss) {
    char c;
    queue<char> output;
    stack<char> ops;
    while (ss >> c) {
        if (c == '=') {
            break;
        } else {
            if (isdigit(c)) {
                output.push(c);
            } else if (c == '(') {
                ops.push(c);
            } else if (c == ')') {
                while (ops.top() != '(') {
                    output.push(ops.top());
                    ops.pop();
                }
                ops.pop();
            } else {
                //assert(c == '+' || c == '-' || c == '*' || c == '/');
                while (!ops.empty() && (ops.top() != '(' && prec[ops.top()] >= prec[c])) {
                    output.push(ops.top());
                    ops.pop();
                }
                ops.push(c);
            }
        }
    }
    while (!ops.empty()) {
        //assert(ops.top() != '(' && ops.top() != ')');
        output.push(ops.top());
        ops.pop();
    }
    
    stack<int> st;
    while (!output.empty()) {
        c = output.front();
        output.pop();
        if (isdigit(c)) {
            st.push(c - '0');
        } else {
            int x, y;
            y = st.top(); st.pop();
            x = st.top(); st.pop();
            if (c == '+') {
                st.push(x + y);
            } else if (c == '-') {
                st.push(x - y);
            } else if (c == '/') {
                st.push(x / y);
            } else {
                st.push(x * y);
            }
        }
    }
    return st.top();
}

bool arithmeticPredicate(std::string predicate) {
    stringstream ss(predicate);
    int res1 = 0, res2 = 0;
    res1 = shuntyard(ss);
    res2 = shuntyard(ss);
    return res1 == res2;
}
