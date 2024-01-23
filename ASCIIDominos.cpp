#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

template<typename T>
void print(const vector<T>& vec) {
    for (auto& i : vec) {
        cout << i << " ";
    }
    cout << "\r"; // Carriage return to move cursor to start of line
    cout.flush(); // Flush the buffer to ensure immediate output
    this_thread::sleep_for(chrono::milliseconds(100)); // Delay for visual effect
}

int main() {
    vector<char> dominos(50, '|');

    for (int i = 0; i < dominos.size(); i++) {
        print(dominos);

        if (dominos[i] == '|') {
            dominos[i] = '/';
            if (i > 0 && dominos[i-1] == '/') {
                dominos[i-1] = '_';
            }
        }
    }
    print(dominos);

    dominos[dominos.size() - 1] = '_';

    print(dominos);

    cout << "\n";

    return 0;
}
