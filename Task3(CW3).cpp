#include <iostream>
#include <cmath>

using namespace std;

struct Vector{
    Vector() {}

    Vector(double x, double y) : x(x), y(y) {}

    double length() const{
        return sqrt(x * x + y * y);
    }

    double x;
    double y;
};

int main() {

    Vector vector(2, -4);
    cout << "Length: " << vector.length() << endl;

    return 0;
}
