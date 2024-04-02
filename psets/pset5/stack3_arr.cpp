#include <iostream>
// #include <stack>

using namespace std;


// 함수 reference 반환?

struct Stack {
    string *item;
    int N;
    int capacity;
};

using stack = Stack *;


stack newStack(int capacity = 1) {
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

int size(stack s) {
    return s->N;// code here
}

void push(stack s, string item) {
    s->item[s->N++] = item;
    //-----------------------------------------
    if (s->N == s->capacity) {
        s->capacity *= 2;
        string *temp = new string[s->capacity];
        for (int i = 0; i < s->capacity / 2; i++)
            temp[i] = s->item[i];
        delete[] s->item;
        s->item = temp;
    }
    //-----------------------------------------
}

void pop(stack s) {
    s->N--;
    //-----------------------------------------
    if (s->N <= s->capacity / 4) {
        s->capacity /= 2;
        string *temp = new string[s->capacity];
        for (int i = 0; i < s->capacity / 2; i++)
            temp[i] = s->item[i];
        delete[] s->item;
        s->item = temp;
    }
    //-----------------------------------------
}

bool empty(stack s) { return s->N == 0; }


string top(stack s) { return s->item[s->N - 1]; }


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
    int list[] = {1, 2, 3, 4, 5, 0, 6, 0, 0, 7, 0, 0, 0, 8};
    string list[] = {
            "to", "be", "or", "not", "to",
            "-", "be", "-", "-", "that", "-",
            "-", "-", "is"
    };

    stack s = newStack();

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