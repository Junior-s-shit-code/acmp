#include <stdio.h>
#include <cmath>
#include <algorithm>

const double eps = 1e-6;

struct Point {

    double i;

    double j;

    static Point read() {
        double i, j;
        scanf("%lf %lf", &i, &j);
        return Point{ i, j };
    }

    double getDist() {
        return std::sqrt(i * i + j * j);
    }

    Point operator *(const int value) const{
        return Point{ i * value, j * value };
    }

    Point operator /(const int value) const{
        return Point{ i / value, j / value };
    }

    Point operator +(const Point second) const{
        return Point{ i + second.i, j + second.j };
    }

    Point operator +=(const Point second) {
        i += second.i;
        j += second.j;
        return *this;
    }

    Point operator -(const Point second) const{
        return Point{ i - second.i, j - second.j };
    }

    Point operator -=(const Point second) {
        i -= second.i;
        j -= second.j;
        return *this;
    }
};

void updateEarlyBorder(
    double &var,
    const double size
) {
    if (var == 0) {
        return;
    }
    var = std::max(var, -size);
    var = std::min(var, size);
}

double getCoef(
    double cur,
    double move,
    double size
) {
    if (std::abs(move) < eps) {
        return 0;
    } else {
        double sign = std::abs(move) / move;
        return move / (sign * size - cur);
    }
}

void updateAllBorders(
    Point cur,
    Point move,
    Point size, 
    Point &end
) {
    double iCoef = getCoef(cur.i, move.i, size.i);
    double jCoef = getCoef(cur.j, move.j, size.j);
    if (iCoef - eps < jCoef) {
        // used j
        updateEarlyBorder(end.j, size.j);
        end.i = cur.i + (end.j - cur.j) * (move.i / move.j);

    } else {
        // used i
        updateEarlyBorder(end.i, size.i);
        end.j = cur.j + (end.i - cur.i) * (move.j / move.i); 
    }
}

void moveUpdate(
    Point &cur,
    Point move,
    double &moveMousePad,
    double &moveAir,
    const Point size
) {
    while (std::abs(move.i) > eps || std::abs(move.j) > eps) {
        Point end = cur + move; 
        bool moreSizeI = (std::abs(size.i) - eps < std::abs(end.i));
        bool moreSizeJ = (std::abs(size.j) - eps < std::abs(end.j));
        if (moreSizeI || moreSizeJ) {
            updateAllBorders(cur, move, size, end);
            moveMousePad += (end - cur).getDist();
            moveAir += end.getDist();
            move -= (end - cur);
            cur = Point{ 0, 0 };
        } else {
            moveMousePad += move.getDist();
            cur += move;
            move = Point{ 0, 0 };
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nQ, moveCoef;
    scanf("%d %d", &nQ, &moveCoef);
    Point size = Point::read() / 2;
    Point cur = Point{ 0, 0 };
    double moveMousePad = 0;
    double moveAir = 0;
    for (int q = 0; q < nQ; q++) {
        Point move = Point::read() * moveCoef;
        moveUpdate(cur, move, moveMousePad, moveAir, size);
    }
    printf("%.3lf %.3lf", moveMousePad, moveAir);
    return 0;
}