#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(string key);


int main() {
    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;
    int b = 66;
    cout << b << endl;
    cout << (char) b << endl;
    // check gen_hash_index
    cout << gen_hash_index("bob") << endl;
    cout << gen_hash_index("110") << endl;

    ifstream file("lab-37-data-2.txt");  

    string line;
    map<int, list<string>> hash_table; 
    while (getline(file, line)) {
        list<string> temp;
        temp.push_back(line);
        hash_table.insert(make_pair(gen_hash_index(line), temp));
    }

    return 0;
}

int gen_hash_index(string key) {
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
