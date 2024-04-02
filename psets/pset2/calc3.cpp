//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
//서명: 이한결 분반: ECE20010-03 학번: 22100594
#include <iostream>
#include <sstream>
//----------------------------------
#include <map>
//----------------------------------

using namespace std;

int add(int a, int b) { return a + b;}
int mul(int a, int b) { return a * b;}
int sub(int a, int b) { return a - b;}
int dvd(int a, int b) { if (b!=0) return a / b; else return 0;}

int get_int() {
    int x;
    do{
        cout << "Enter an integer : ";
        string str;
        getline (cin, str);

        try {
            x = stoi(str);
            break;
        } catch (invalid_argument& e){
            cerr << e.what() << " error occurred. Retry~" << endl;
        }
    } while (true);
    return x;
}

char get_op(map<char, int(*)(int, int)> fp_map){
    string opstr;
    char op;
    for (auto x : fp_map) opstr += x.first;

    do {
        cout << "Enter an operator( "<< opstr << " ): ";
        stringstream ss;
        string str;
        getline(cin, str);
        ss << str;
        ss >> op;                            // if not found, find returns fp_map.end()
        //---------------------------------- 
        if (fp_map.find(op) != fp_map.end()) break;      // if found, op is valid
        //----------------------------------
    } while (true);                          // while op is not found in fp_map
    return op;                               // returns the operator chosen by user

}

int main (){

    //----------------------------------
    map<char, int(*)(int, int)> fp_map { make_pair('+',add), make_pair('-',sub), 
                                         make_pair('*',mul), make_pair('/',dvd)} ;
    //----------------------------------

    string opstr {"+-*/"};

    int a { get_int() };
    char op { get_op(fp_map) };
    int b { get_int() };

    //----------------------------------
    cout << a << " " << op << " " << b << " = " << fp_map[op](a, b) << endl;
    //----------------------------------
    
    return 0;


}