#include <iostream>
#include <string>

using namespace std;

int main(){

    string aStr;
    char aChar = 65;

    aStr.assign(1, aChar);
    cout << aStr << " " << aStr.length();

    aStr.assign(1, aChar);
    cout << aStr << " " << aStr.length();

    return 0;
}