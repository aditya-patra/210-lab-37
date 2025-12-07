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
        auto it = hash_table.find(gen_hash_index(line));
        if (it == hash_table.end()) {
            list<string> temp;
            temp.push_back(line);
            hash_table.insert(make_pair(gen_hash_index(line), temp));
        }
        else {
            it->second.push_front(line);
        }
    }
    // menu printing Lab 38
    int input = -1;
    while (true) {
        cout << "Menu: \n  1 - print 100 entries\n  2 - search for a key\n  3 - add key\n  4 - remove key\n  5 - modify key\n  6 - Exit\n";
        cout << "Enter your choice: ";
        cin >> input;
        if (input == 1) {
            int cnt = 0;
            for (const auto& pair : hash_table) {
                cout << pair.first << endl;
                for (auto i = pair.second.begin(); i != pair.second.end(); i++) {
                    cout << *i << " "; 
                }
                cout << endl << endl;
                cnt++;
                if (cnt == 100) {
                    break; 
                }
            }
        }
        if (input == 2) {
            string key;
            cout << "Enter key value: ";
            cin >> key;
            int hash = gen_hash_index(key);
            auto it = hash_table.find(hash);
            if (it == hash_table.end()) {
                cout << "Key not present in hash table" << endl;
            }
            else {
                bool present = false;
                for(auto index = it->second.begin(); index != it->second.end(); index++) {
                    if (*index == key) {
                        present = true; 
                        break;
                    }
                }
                if (present) {
                    cout << "Key present at hash bin " << hash << endl;
                }
                else {
                    cout << "Key not present in hash table" << endl;
                }
            }
        }
        else if (input == 3) {
            string key;
            cout << "Enter key value: ";
            cin >> key;
            auto it = hash_table.find(gen_hash_index(key));
            if (it == hash_table.end()) {
                list<string> temp;
                temp.push_back(key);
                hash_table.insert(make_pair(gen_hash_index(key), temp));
            }
            else { 
                it->second.push_front(key);
            } 
            cout << "Key added" << endl;
        }
        else if (input == 4) {
            string key;
            cout << "Enter key value: ";
            cin >> key;
            auto it = hash_table.find(gen_hash_index(key));
            if (it == hash_table.end()) {
                cout << "Key not present in hash table" << endl;
            }
            else {
                bool present = false;
                for(auto index = it->second.begin(); index != it->second.end(); index++) {
                    if (*index == key) {
                        present = true;
                        it->second.erase(index);
                        break;
                    }
                }
                if (!present) {
                    cout << "Key not present in hash table" << endl;
                }
            }
        } 
        else if (input == 5) {
            string key;
            cout << "Enter key value: ";
            cin >> key;
            auto it = hash_table.find(gen_hash_index(key));
            if (it == hash_table.end()) {
                cout << "Key not present in hash table" << endl;
            }
            else {
                bool present = false;
                for(auto index = it->second.begin(); index != it->second.end(); index++) {
                    if (*index == key) {
                        present = true;
                        it->second.erase(index);
                        break;
                    }
                }
                if (!present) {
                    cout << "Key not present in hash table" << endl;
                }
            }
            string key;
            cout << "Enter key value: ";
            cin >> key;
            auto it = hash_table.find(gen_hash_index(key));
            if (it == hash_table.end()) {
                list<string> temp;
                temp.push_back(key);
                hash_table.insert(make_pair(gen_hash_index(key), temp));
            }
            else { 
                it->second.push_front(key);
            } 
            cout << "Key added" << endl;
        }
        else if (input == 6) { 
            break;
        }
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
