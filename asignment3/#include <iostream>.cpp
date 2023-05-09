#include <iostream>
#include <cmath>
#include <string>

struct Vector {
    double x;
    double y;
};

Vector add(const Vector& v1, const Vector& v2) {
    return {v1.x + v2.x, v1.y + v2.y};
}

Vector subtract(const Vector& v1, const Vector& v2) {
    return {v1.x - v2.x, v1.y - v2.y};
}

Vector scale(const Vector& v, double scalar) {
    return {v.x * scalar, v.y * scalar};
}

double length(const Vector& v) {
    return std::sqrt(v.x * v.x + v.y * v.y);
}

Vector normalize(const Vector& v) {
    double len = length(v);
    return {v.x / len, v.y / len};
}

int main() {
    std::string command;
    std::cin >> command;
    Vector v1, v2;

    if (command == "add" || command == "subtract") {
        std::cin >> v1.x >> v1.y >> v2.x >> v2.y;
        Vector result = (command == "add") ? add(v1, v2) : subtract(v1, v2);
        std::cout << result.x << " " << result.y << std::endl;
    } 
    else if (command == "scale") {
        double scalar;
        std::cin >> v1.x >> v1.y >> scalar;
        Vector result = scale(v1, scalar);
        std::cout << result.x << " " << result.y << std::endl;
    } 
    else if (command == "length") {
        std::cin >> v1.x >> v1.y;
        std::cout << length(v1) << std::endl;
    } 
    else if (command == "normalize") {
        std::cin >> v1.x >> v1.y;
        Vector result = normalize(v1);
        std::cout << result.x << " " << result.y << std::endl;
    }

    return 0;
}
