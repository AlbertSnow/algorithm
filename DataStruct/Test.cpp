#include <stack>
#include <iostream>

using namespace std;

int main() {
    stack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    cout << "element: " << intStack.top() << '\n';
    intStack.pop();
    cout << "element: " << intStack.top() << '\n';
    intStack.pop();
    cout << "element: " << intStack.top() << '\n';
    intStack.pop();
}