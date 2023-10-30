/**
 * @author Lyuben Georgiev
 * @brief Problem: https://leetcode.com/problems/basic-calculator-ii/description/
 * @date 30/10/2023
 * 
*/

class Solution {
public:
    int apply(char op, int left, int right) {
        switch (op) {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        }
        return left / right;
    }

    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;

        int priority[256];
        priority['+'] = 1;
        priority['-'] = 1;
        priority['*'] = 2;
        priority['/'] = 2;

        for (int i = 0; i < s.size(); ++i) {
            switch (s[i]) {
            case ' ':
                continue;
            case '+':
            case '-':
            case '*':
            case '/':
                while (!ops.empty() && priority[ops.top()] >= priority[s[i]]) {
                    int right = nums.top();
                    nums.pop();
                    int left = nums.top();
                    nums.pop();

                    nums.push(apply(ops.top(), left, right));
                    ops.pop();
                }

                ops.push(s[i]);
                break;
            default:
                int num = 0;
                while (i < s.size() && '0' <= s[i] && s[i] <= '9') {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }

                --i;
                nums.push(num);
            }
        }

        while (!ops.empty()) {
            int right = nums.top();
            nums.pop();
            int left = nums.top();
            nums.pop();

            nums.push(apply(ops.top(), left, right));
            ops.pop();
        }

        return nums.top();
    }
};