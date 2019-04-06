//
// Created by fer on 05/04/19.
//

#include "DirectionVector.h"

DirectionVector::DirectionVector(){

    x = 0.0F;
    y = 0.0F;
    diagonal = 0;
}

DirectionVector::~DirectionVector() = default;


DirectionVector::DirectionVector(double x, double y) {

    this->x = x;
    this->y = y;
}



void DirectionVector::setX(double x){

    this->x = x;
}

void DirectionVector::setY(double y){

    this->y = y;
}

bool DirectionVector::isEqual(DirectionVector* v2) {
    return this->x == v2->x and this->y == v2->y;
}

void DirectionVector::equal(DirectionVector* v2) {
    this->x = v2->x;
    this->y = v2->y;
}

void DirectionVector::add(double x, double y) {

    this->x += x;
    this->y += y;
}

void DirectionVector::subtract(double x, double y) {
    this->x -= x;
    this->y -= y;
}

void DirectionVector::multiply(double mult) {
    this->x *= mult;
    this->y *= mult;
}

void DirectionVector::divide(double div) {
    this->x /= div;
    this->y /= div;

}

void DirectionVector::add(DirectionVector *vec) {
    this->x += vec->x;
    this->y += vec->y;
}

void DirectionVector::subtract(DirectionVector *vec) {
    this->x -= vec->x;
    this->y -= vec->y;
}

void DirectionVector::setDiagonal(int diagonalCode){
    diagonal = diagonalCode;
}

bool DirectionVector::isDiagonalRight(){
    return diagonal == 1;
}

bool DirectionVector::isDiagonalLeft(){
    return diagonal == -1;
}





