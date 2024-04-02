#include <iostream>
#include <stack>

using namespace std;

void printStack(stack<string> s);

void printStack_fromBottoms(stack<string> s);

int main() {
//    int list[] = {1, 2, 3, 4, 5, 0, 6, 0, 0, 7, 0, 0, 0, 8};
    string list[] = {
            "to", "be", "or", "not", "to",
            "-", "be", "-", "-", "that", "-",
            "-", "-", "is"
    };

    stack<string> s;

    for (auto item: list) { // to be not that or be
        if (item != "-") s.push(item);
        else {
            cout << s.top() << ' ';
            s.pop();
        }
    }
    cout << "\nsize: " << s.size(); // 2
    cout << "\ntop : " << s.top(); //is (8)
    cout << "\nstack T: ";
    printStack(s);               // is to (8 1)
    cout << "\nstack B: ";
    printStack_fromBottoms(s);   // to is (1 8)
    cout << "\nHappy Cording";
    return 0;
}

//void printStack(stack<string> s) {
//    while (!s.empty()) {
//        cout << s.top() << ' ';
//        s.pop();
//    }
//    // cout << endl // now s is empty
//}

void printStack(stack<string> s) {
    if (s.empty()) return;
    string temp;
    cout << s.top() << " ";
    temp = s.top();
    s.pop();
    printStack(s);
    s.push(temp);

    //recursion version
}

//void printStack_fromBottoms(stack<string> s) {
//    stack<string> temp;
//
//    while (!s.empty()) {
//        temp.push(s.top());
//        s.pop();
//    }
//    while (!temp.empty()) {
//        cout << temp.top() << ' ';
//        temp.pop();
//    }
//}
void printStack_fromBottoms(stack<string> s) {
    if (s.empty()) return;
    string temp;
    temp = s.top();
    s.pop();
    printStack(s);
    s.push(temp);
    cout << s.top() << " ";
}