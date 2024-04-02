// Step_6
// On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: 이한결(HanGyeol_Lee) Student Number: 22100594


#include<iostream>
#include <cctype> // to use toupper

using namespace std;

int main() {
    size_t i; // index of string
    string input; // user input
    
    cout << "Enter words: ";

    //input data
    getline(cin, input);

    // change to upper case
    for (i = 0; i < input.length(); i++) {
        input[i] = (char) toupper(input[i]);
    }
    
    // print
    cout << input << endl;

    return 0;
}