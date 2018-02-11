#include <iostream>
#include <sstream>

using namespace std;

#define PI 3.1415


namespace maths {
    const double pi = 3.14;
    const double x = 1000;

    double add(double a, double b) {
        return a + b;
    }

}

// Namespaces can be split up
namespace maths { int y; }


// Prototype function. If it needs to be called before it is defined.
bool isEven(int n);


void count(int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Number: " << i << endl;

    }
}

int add(int a, int b) {
    return a + b;

}

inline int addInline(int &a, int &b) {
    //inline: Tells compiler to insert function where it is called instead of normal overhead.
    return a + b;
}

void doubleNum(int &a) {
    a *= 2;
}

int divideInts(int a, int b = 2) {
    return a / b;
}

long factorial(long n) {
    if (n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}


int division(int a, int b) {
    return a / b;
}


double division(double a, double b) {
    return a / b;
}


string addStrings(const string &s1, const string &s2) {
    // const: Variables cannot be changed, only accessed from within this function.
    // Increased efficiency for large variable types.
    return s1 + s2;

}

int genList(int n) {
    return 0;
}


template<class Tmp>
Tmp addT(Tmp a, Tmp b) {
    // Template function
    Tmp result;
    result = a + b;
    return result;
}


template<class T, class U>
bool areEqual(T a, U b) {
    return a == b;
};

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

void functions() {
    int num = 10;
    cout << "The value of num before is " << num << "\n";
    doubleNum(num);
    cout << "The value of num after is " << num << "\n";

    // Parameters are copied if passed by value, but not when passed by reference.
    // For large variables (eg. long strings) passing by value is a big performance hit.
    string s1 = "Hello ", s2 = "World!";
    cout << "'" << s1 << "' + '" << s2 << "' = '" << addStrings(s1, s2) << "'\n";

    // Inline
    int a = 5, b = 8;
    cout << a << " + " << b << " = " << addInline(a, b) << "\n";

    // Default parameters
    cout << a << " / " << 2 << " = " << divideInts(a) << "\n";
    cout << a << " / " << b << " = " << divideInts(a, b) << "\n";

    // Prototype function
    cout << a << " is " << (isEven(a) ? "even" : "odd") << "\n";
    cout << b << " is " << (isEven(b) ? "even" : "odd") << "\n";

    // Recursion
    long n = 9;
    cout << n << "! is " << factorial(n) << "\n";

    // Overloaded
    double p = 5.5, q = 10.6;
    cout << a << " / " << b << " = " << division(a, b) << "\n";
    cout << p << " / " << q << " = " << division(p, q) << "\n";

    // Templates
    int x;
    x = addT<int>(5, 10);
    cout << "5 + 10 = " << x << "\n";

    double y;
    y = addT<double>(5.5, 10.5);
    cout << "5.5 + 10.5 = " << y << "\n";

    // Note <type> is not always required
    cout << "5 and 5.0 are " << (areEqual(5, 5.0) ? "equal" : "not equal") << "\n";


}

void scopes() {
    // Blocks
    int x = 5, y = 10;
    cout << "x = " << x << " y = " << y << "\n";
    {
        int x = 7;
        cout << "x = " << x << " y = " << y << "\n";
        y = 2;
    }
    cout << "x = " << x << " y = " << y << "\n";

    // Namespaces
    cout << "x = " << x << "\n";
    cout << "maths::x = " << maths::x << "\n";

    // Using
    using maths::pi;
    cout << "pi = " << pi << "\n";
    cout << "pi = " << maths::pi << "\n";

    using namespace maths;
    cout << "5 + 10 = " << add(5, 10) << "\n";

    // Alias
    namespace m = maths;
    cout << m::pi << "\n";

    // Storage
    // global variables are initialised to 0
    // local variables may be initialised to any value
    int k;
    cout << "k = " << k << " \n";


}


bool isEven(int n) {
    return n % 2 == 0;
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
    scopes();

}