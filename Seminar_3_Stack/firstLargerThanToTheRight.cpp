#include <iostream>
#include <vector>
#include <stack>

/*Задача: На първия ред се въвежда число n, a на втория n естествени числа. 
За всяко едно число да се намери индексът на първото по-голямо число надясно 
от него. Ако такова число не съществува, да се изведе -1. 
Пример:  n = 7
индекс | 0 | 1 | 2 | 3 | 4 | 5 | 6
число  | 1 | 7 | 2 | 4 | 1 | 3 | 5
отговор| 1 |-1 | 3 | 6 | 5 | 6 |-1
*/

/*Сложност: O(n) */

void solve(const std::vector<int> &arr, int n) {
    std::stack<int> st;
    std::stack<int> result;

    for (int i = arr.size() - 1; i >= 0; --i) {
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }
        if (st.empty()) {
            result.push(-1);
        } else {
            result.push(st.top());
        }
        st.push(i);
    }

    while (!result.empty()) {
        std::cout << result.top() << ' ';
        result.pop();
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    solve(arr, n);

    return 0;
}