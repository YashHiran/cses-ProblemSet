#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

// Recursive GCD
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Extended Euclidean Algorithm (Recursive)
void extendedGCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }

    int x1, y1;
    extendedGCD(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;
}

// Solve ax + by = c
bool solveDiophantine(int a, int b, int c, int &x, int &y) {
    int g = gcd(abs(a), abs(b));

    if (c % g != 0) return false; // No solution

    extendedGCD(abs(a), abs(b), x, y);

    x *= c / g;
    y *= c / g;

    if (a < 0) x = -x;
    if (b < 0) y = -y;

    return true;
}

int main() {
     #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
    int a = 30, b = 20, c = 10;
    int x, y;

    if (solveDiophantine(a, b, c, x, y)) {
        std::cout << "Solution to " << a << "*x + " << b << "*y = " << c << ":\n";
        std::cout << "x = " << x << ", y = " << y << "\n";
        std::cout << a << "*" << x << " + " << b << "*" << y << " = " << a * x + b * y << std::endl;
    } else {
        std::cout << "No solution exists for the given equation.\n";
    }

    return 0;
}
