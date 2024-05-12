class Solution {

    int val(int a, int b, char c) {
        if (c == '+') {
            return a + b;
        }
        if (c == '*') {
            return a * b;
        }
        if (c == '-') {
            return a - b;
        }
        return 0;
    }

public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        bool isANumber = true;
        for (int i = 0; i < expression.size(); i++) {
            if (!isdigit(expression[i])) {
                isANumber = false;
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                for (int j : left) {
                    for (int k : right) {
                        ans.push_back(val(j, k, expression[i]));
                    }
                }
            }
        }
        if (isANumber) {
            ans.push_back(stoi(expression));
        }
        return ans;
    }
};