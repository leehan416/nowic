// On my honour, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// 서명: HanGyeol Lee (이한결) 학번: 22100594
#include <iostream>
#include <vector>

using namespace std;


struct Stack {
    vector<string> item;
};

using stack = Stack *;


stack newStack() {
    stack s = new Stack;
    return s;
}

void free(stack s) {
    delete s;
}


int size(stack s) {
    return s->item.size();
}

bool empty(stack s) {
    return s->item.empty();
}

//------------------------------------
void pop(stack s) {
    s->item.pop_back();
}
//------------------------------------

//------------------------------------
//reference func
string &top(stack s) {
    return s->item[s->item.size()-1];
}
//------------------------------------


//------------------------------------
//reference parameter
void push(stack s, string &item) {
    s->item.push_back(item);
}
//------------------------------------


// 스텍 데이터를 남기기 위해서 함수를 수정했습니다.
void printStack(stack s) {
    // while (!empty(s)) {
    //     cout << top(s) << ' ';
    //     pop(s);
    // }
    // cout << endl;
//------------------------------------
    stack temp = newStack();
    temp->item = s->item;

    while (!empty(temp)) {
        cout << top(temp) << ' ';
        pop(temp);
    }
    cout << endl;

    free(temp);
//------------------------------------
}

void printStack_fromBottom(stack s) {
//------------------------------------
    stack temp = newStack();
    temp->item = s->item;
    stack back = newStack();

    while (!empty(temp)) {
        push(back, top(temp));
        pop(temp);
    }

    while (!empty(back)) {
        cout << top(back) << ' ';
        pop(back);
    }

    free(temp);
    free(back);
//------------------------------------
}

int main() {

    string list[] = {
            "to", "be", "or", "not", "to",
            "-", "be", "-", "-", "that", "-",
            "-", "-", "is"
    };

    stack s = newStack();

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

    cout << "\nsize: " << size(s);
    cout << "\ntop : " << top(s);
    cout << "\nstack T: ";
    printStack(s);
    cout << "\nstack B: ";
    printStack_fromBottom(s);
    cout << "\nHappy Cording" << endl;

    free(s);
    return 0;
}
