//Step_5
// On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: 이한결(HanGyeol_Lee) Student Number: 22100594

#include<iostream>
#include<vector>

using namespace std;

//-------------------------------
#include<cassert> // to use assert func
//-------------------------------


/*

1. setmax_ret.cpp 소스 파일을 생성하고, 아래 코드를 추가한다.
2. 주어진배열을이용해가장큰값을찾고,99로그값을수정한다.
3. getmax()를 코딩하여 가장 큰 값을 가진 원소를 참조로 반환 한다. 단, 원소의 인덱스(index)는 반환하지 않는다.
4. setmax()를 코딩하여 가장 큰 값을 가진 원소가 참조가 반환된 것을 사용 하도록 한다. 함수에서 반환된 참조는 값을 할당하는 과정에서 좌편(할당 받는 변수) 위치에 사용될 수 있다는 점을 기억한다.
5. list 배열이 getmax()와 setmax()의 참조로 전달되도록 코딩한다.
*/

// gets the max value in the list and returns the reference of the max value
// your code here – define getmax() here

//-------------------------------
int &getmax(vector<int> &vec) {
    assert(vec.size() > 0);
    int index;
    int max = 0;

    for (size_t i = 0; i < vec.size(); i++) {
        if (max < vec[i]) { // max search in list
            index = i; // change
            max = vec[i];
        }
    }
    return vec[index];
}
//-------------------------------


// sets the max value in the list to 99
// your code here – define setmax() here

//-------------------------------
void setmax(vector<int> &vec) {
    // int &idx = getmax(vec);
    // idx = 99; // set value to 99
    getmax(vec) = 99; // 수업에서 배운내용!
}
//-------------------------------

// With a given list, find the max value, then set it to 99 in setmax()
int main(int argc, char *argv[]) {
    vector<int> list1 = {43, 10, 20, 75, 22, 33};
    vector<int> list2 = {33, 13, 45, 19, 39, 22};

    cout << ">list1: ";
    for (auto x: list1)
        cout << x << " ";
    cout << endl;

    setmax(list1);
    cout << "<list1: ";
    for (auto x: list1)
        cout << x << " ";
    cout << endl << endl;

    cout << ">list2: ";
    for (auto x: list2)
        cout << x << " ";
    cout << endl;

    setmax(list2);
    cout << "<list2: ";
    for (auto x: list2)
        cout << x << " ";
    cout << endl;

    return 0;
}