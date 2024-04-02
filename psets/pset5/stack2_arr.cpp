// int 가능하게 해야함
#include <iostream>

using namespace std;

struct Stack {
    string *item;
    int N;
    int capacity;
};

using stack = Stack *;


stack newStack(int capacity) {
    stack s = new Stack;
    s->item = new string[capacity];
    s->N = 0;
    s->capacity = capacity;
    return s;
}

void free(stack s) {
    delete[] s->item;
    delete s;
}

int size(stack s) { return s->N; }

bool empty(stack s) { return s->N == 0; }

void pop(stack s) { s->N--; }

string top(stack s) { return s->item[s->N - 1]; }

void push(stack s, string item) { s->item[s->N++] = item; }

void printStack(stack s) {
    if (empty(s)) return;
    string temp;
    cout << top(s) << " ";
    temp = top(s);
    pop(s);
    printStack(s);
    push(s, temp);
}


void printStack_fromBottom(stack s) {
    if (empty(s)) return;
    string temp;
    temp = top(s);
    pop(s);
    printStack(s);
    push(s, temp);
    cout << top(s) << " ";
}

int main() {
//    int list[] = {1, 2, 3, 4, 5, 0, 6, 0, 0, 7, 0, 0, 0, 8};
    string list[] = {
            "to", "be", "or", "not", "to",
            "-", "be", "-", "-", "that", "-",
            "-", "-", "is"
    };

    stack s = newStack(14);

    for (auto item: list) { // to be not that or be
        if (item != "-") push(s, item);
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
    cout << "\nHappy Cording";
    free(s);
    return 0;
}