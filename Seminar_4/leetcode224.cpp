/**
 * @author Lyuben Georgiev
 * @brief Problem: https://leetcode.com/problems/basic-calculator/description/
 * @date 30/10/2023
 * 
*/

class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;

        int priority[1<<(sizeof(char)*8)];
        priority['('] = 0;
        priority['+'] = 1;
        priority['-'] = 1;
        // priority['*'] = 2;
        // priority['/'] = 2;

        bool unary = true;

        for (int i = 0; i < s.size(); ++i) {
            switch (s[i]) {
            case ' ':
                continue;
            case '(':
                ops.push('(');
                unary = true;
                break;
            case ')':
                while (ops.top() != '(') {
                    int right = nums.top();
                    nums.pop();
                    int left = nums.top();
                    nums.pop();

                    if (ops.top() == '+') {
                        nums.push(left + right);
                    } else {
                        nums.push(left - right);
                    }
                    ops.pop();
                }

                unary = false;
                ops.pop();
                break;
            case '-':
                if (unary) {
                    nums.push(0);
                }
            case '+':
                while (!ops.empty() && priority[ops.top()] >= priority[s[i]]) {
                    int right = nums.top();
                    nums.pop();
                    int left = nums.top();
                    nums.pop();

                    if (ops.top() == '+') {
                        nums.push(left + right);
                    } else {
                        nums.push(left - right);
                    }
                    ops.pop();
                }

                ops.push(s[i]);

                unary = false;
                break;
            default: // Number
                int num = 0;
                while ('0' <= s[i] && s[i] <= '9') {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }

                --i;
                nums.push(num);
                unary = false;
            }
        }

        while (!ops.empty()) {
            int right = nums.top();
            nums.pop();
            int left = nums.top();
            nums.pop();

            if (ops.top() == '+') {
                nums.push(left + right);
            } else {
                nums.push(left - right);
            }
            ops.pop();
        }

        return nums.top();
    }
};