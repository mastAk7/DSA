#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
// (add) #include <string>
 // (add) #include <chrono>
using namespace std;
int main() {
    string target;
    getline(cin,target);
    string display = "";
    srand(time(0));

    for (int i = 0; i < int(target.size()); i++) {
        // Animate random characters at position i
        for (int j = 0; j < 10; j++) {
            char c = char(32 + rand() % 95); // random printable char
            cout << "\r" << display + c << flush;
            this_thread::sleep_for(chrono::milliseconds(50));
        }
        // Set correct character
        display += target[i];
        cout << "\r" << display << flush;
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    cout << endl;
}
