

#ifndef TALLER_MARVEL_CAPCOM_VECTOR2D_H
#define TALLER_MARVEL_CAPCOM_VECTOR2D_H

#include <iostream>
#include <tuple>


class DirectionVector {

public:

    double x;
    double y;
    int diagonal;

    DirectionVector();
    ~DirectionVector();
    DirectionVector(double x, double y);

    void equal(DirectionVector* v2);

    void setX(double x);
    void setY(double y);

    void add(double x, double y);
    void subtract(double x, double y);
    void multiply(double mult);
    void divide(double div);

    void add(DirectionVector* vec);
    void subtract(DirectionVector* vec);

    bool isEqual(DirectionVector* v2);

    bool isDiagonalRight();

    void setDiagonal(int diagonalCode);

    bool isDiagonalLeft();
};


#endif //TALLER_MARVEL_CAPCOM_VECTOR2D_H
