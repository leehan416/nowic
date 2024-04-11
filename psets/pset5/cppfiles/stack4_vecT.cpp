// On my honour, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// 서명: HanGyeol Lee (이한결) 학번: 22100594
#include <iostream>
#include <vector>

using namespace std;


template<typename T>
struct Stack {
    vector<T> item;
};

template<typename T>
using stack = Stack<T> *;

template<typename T>
void free(stack<T> s);

template<typename T>
stack<T> newStack();

template<typename T>
T top(stack<T> s);

template<typename T>
void push(stack<T> s, T item);

template<typename T>
void pop(stack<T> s);

template<typename T>
int size(stack<T> s);

template<typename T>
bool empty(stack<T> s);

template<typename T>
void printStack(stack<T> s);

template<typename T>
void printStack_fromBottom(stack<T> s);


int main() {
//    int list[] = {1, 2, 3, 4, 5, 0, 6, 0, 0, 7, 0, 0, 0, 8};
    string list[] = {
            "to", "be", "or", "not", "to",
            "-", "be", "-", "-", "that", "-",
            "-", "-", "is"
    };
    stack<string> s = newStack<string>();
    
    //-----------------------------------------
    // check for size and capacity
    cout << "size : " << size(s) << " " << "capacity : " << s->item.capacity() << endl << endl;
    //-----------------------------------------
    
    for (auto item: list) { // to be not that or be
        if (item != "-") push(s, item);
        else {
            cout << top(s) << ' ';
            pop(s);
        }
    }

    //-----------------------------------------
    // check for size and capacity
    cout << endl << endl << "size : " << size(s) << " " << "capacity : " <<s->item.capacity() << endl;
    //-----------------------------------------


    cout << "\nsize: " << size(s); // 2
    cout << "\ntop : " << top(s); //is (8)
    cout << "\nstack T: ";
    printStack(s);               // is to (8 1)
    cout << "\nstack B: ";
    printStack_fromBottom(s);   // to is (1 8)
    cout << "\nHappy Cording" << endl;
    return 0;
}

template<typename T>
void free(stack<T> s) {
    delete s;
}

template<typename T>
stack<T> newStack() {
    stack<T> s = new Stack<T>;
    return s;
}

template<typename T>
T top(stack<T> s) {
    return s->item.back();
}

template<typename T>
void push(stack<T> s, T item) {
    s->item.push_back(item);
}

template<typename T>
void pop(stack<T> s) {
    s->item.pop_back();
}

template<typename T>
int size(stack<T> s) {
    return s->item.size();
}

template<typename T>
bool empty(stack<T> s) {
    return s->item.empty()
}

// 스텍 데이터를 남기기 위해서 함수를 수정했습니다.
template<typename T>
void printStack(stack<T> s) {
    // while (!empty(s)) {
    //     cout << top(s) << ' ';
    //     pop(s);
    // }
    // cout << endl;
    //-----------------------------------------
    stack<T> temp = newStack<T>();
    temp->item = s->item;

    while (!empty(temp)) {
        cout << top(temp) << ' ';
        pop(temp);
    }
    cout << endl;

    free(temp);
    //-----------------------------------------

}


template<typename T>
void printStack_fromBottom(stack<T> s) {
    //-----------------------------------------

    stack<T> temp = newStack<T>();
    stack<T> back = newStack<T>();

    temp->item = s->item;

    // reverse
    while (!empty(temp)) {
        push(back, top(temp));
        pop(temp);
    }

    // print
    while (!empty(back)) {
        cout << top(back) << ' ';
        pop(back);
    }

    // free
    free(temp);
    free(back);
    //-----------------------------------------

}