#include <iostream>
#include <fstream>
using namespace std;

int sum_ascii(string key);


int main() {
    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;
    int b = 66;
    cout << b << endl;
    cout << (char) b << endl;
    // check sum_ascii
    cout << sum_ascii("bob") << endl;
    cout << sum_ascii("110") << endl;

    ifstream file("lab-37-data-2.txt"); 

    string line;
    int sum = 0;
    while (getline(file, line)) {
        sum += sum_ascii(line);
    }
    cout << sum;

    return 0;
}

int sum_ascii(string key) {
    int sum = 0;
    for(char val: key) {
        sum += (int) val;
    }
    return sum; 
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
