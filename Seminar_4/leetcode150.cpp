/**
 * @author Lyuben Georgiev
 * @brief Problem: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
 * @date 30/10/2023
 * 
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;

        for (int i = 0; i < tokens.size(); ++i) {
            string tok = tokens[i];

            if (tok == "+" || tok == "-" || tok == "*" || tok == "/") {
                int right = operands.top();
                operands.pop();
                int left = operands.top();
                operands.pop();

                if (tok == "+") {
                    operands.push(left + right);
                } else if (tok == "-") {
                    operands.push(left - right);
                } else if (tok == "*") {
                    operands.push(left * right);
                } else {
                    operands.push(left / right);
                }
            } else { // Number
                operands.push(stoi(tok));
            }
        }

        return operands.top();
    }
};