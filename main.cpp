#include <iostream>
#include <sstream>

using namespace std;

#define PI 3.1415

void count(int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Number: " << i << endl;

    }
}

int add(int a, int b) {
    return a + b;

}


int genList(int n) {
    return 0;
}


double circleArea(double r) {
    return PI * r * r;
}

void circlePrompt() {
    double radius;
    string line;
    cout << "Enter the radiius of the circle: ";
    getline(cin, line);             // Read entire line
    stringstream(line) >> radius;   // Parse line to double (or whatever type radius is)
    cout << "The area of the circle with radius " << radius << " is " << circleArea(radius) << "\n";
}

void addPrompt() {
    int a, b;
    cout << "Enter two integers to be added: ";
    cin >> a >> b;
    cout << "The result of adding " << a << " and " << b << " is " << add(a, b) << "\n";
}

void namePrompt() {
    string name;
    cout << "Enter your name: ";
//    cin >> name;      This only extracts the first word
    getline(cin, name); // This extract the whole line
    cout << "Hello " << name << "!\n";
}

void statements() {
    // Normal while loop
    int i = 0;
    while (i < 10) {
        cout << i << ", ";
        ++i;
    }
    cout << "\n";

    // Do-while loop
    // Loop will always be executed at least once
    string line;
    do {
        cout << "Enter a word: ";
        getline(cin, line);
        cout << "You entered: " << line << "\n";
    } while (line != "stop");


    // For loop
    for (i = 0; i < 10; ++i) {
        cout << i << ", ";
    }
    cout << "\n";

    // For loop with no condition - infinite loop
    for (;;) {
        break;
    }

    // For loop with multiple counters
    for (int a = 0, b = 10; a < b; ++a, --b) {
        cout << "a: " << a << ", b: " << b << "\n";
    }


    // For loop with range/iterable
    string str("Hello");
    for (char c : str) {
        cout << c << ", ";
    }
    cout << "\n";

    // For loop using "auto" for type declaration
    for (auto c : str) {
        cout << c << ", ";
    }
    cout << "\n";



    // For loop with continue/break statements
    for (i = 0; i < 10; ++i) {
        if (i % 3 == 0) continue;
        else if (i > 7) break;
        cout << i << ", ";

    }
    cout << "\n";


    // Goto statement - Deemed low level and should be avoided
    int k = 0;
    mylabel:        // goto label
    cout << k << ", ";
    k++;
    if (k < 10) goto mylabel;   // goto statement
    cout << "\n";


    // Switch/case statement
    int x;
    switch (x) {
        case 0:     // These can only be constants, not custom conditions
        case 1:
            cout << "x is either 0 or 1\n";
        case 2:
            cout << "x is 2\n";
            break;
        case 3:
            cout << "x is 3";
            break;
        default:
            cout << "x is not 0, 1, 2, 3\n";

    }


}


bool equals(int a, int b) {
    // Showing equivalent conditionals
    bool isEqual(false);


    if (a == b) {
        isEqual = true;
    } else {
        isEqual = false;
    }

    // For branches with 1 line only
    if (a == b)
        isEqual = true;
    else
        isEqual = false;

    if (a == b) { isEqual = true; } else { isEqual = false; }


    isEqual = (a == b) ? true : false;

    isEqual = a == b;

    return isEqual;
}


int main() {
    cout << "Hello, World!" << endl;
    statements();


}