// int 가능하게 해야함
#include <iostream>

using namespace std;

template<typename T>
struct Stack {
    T *item;
    int N;
    int capacity;
};

template<typename T>
using stack = Stack<T> *;

template<typename T>
stack<T> newStack(int capacity) {
    stack<T> s = new Stack<T>;
    s->item = new T[capacity];
    s->N = 0;
    s->capacity = capacity;
    return s;
}

template<typename T>
void free(stack<T> s) {
    delete[] s->item;
    delete s;
}

template<typename T>
int size(stack<T> s) { return s->N; }

template<typename T>
bool empty(stack<T> s) { return s->N == 0; }

template<typename T>
void pop(stack<T> s) { s->N--; }

template<typename T>
T top(stack<T> s) { return s->item[s->N - 1]; }


template<typename T>
void push(stack<T> s, T item) { s->item[s->N++] = item; }

template<typename T>
void printStack(stack<T> s) {
    if (empty(s)) return;
    T temp;
    cout << top(s) << " ";
    temp = top(s);
    pop(s);
    printStack(s);
    push(s, temp);
}

template<typename T>
void printStack_fromBottom(stack<T> s) {
    if (empty(s)) return;
    T temp;
    temp = top(s);
    pop(s);
    printStack(s);
    push(s, temp);
    cout << top(s) << " ";
}

int main() {
    int list[] = {1, 2, 3, 4, 5, 0, 6, 0, 0, 7, 0, 0, 0, 8};
// string list[] = {
//         "to", "be", "or", "not", "to",
//         "-", "be", "-", "-", "that", "-",
//         "-", "-", "is"
// };

    stack<int> s = newStack<int>(14);

    for (auto item: list) { // to be not that or be
// if (item != "-") push(s, item);

        if (item != 0) push(s, item);
        else {
            cout << top(s) << ' ';
            pop(s);
        }
    }
    cout << "\nsize: " << size(s); // 2
    cout << "\ntop : " << top(s);  //is (8)
    cout << "\nstack T: ";
    printStack(s);                 // is to (8 1)
    cout << "\nstack B: ";
    printStack_fromBottom(s);      // to is (1 8)
    cout << "\nHappy Cording" << endl;
    free(s);
    return 0;
} 