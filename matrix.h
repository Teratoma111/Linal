#include<iostream>
#ifndef MATRIX_H
#define MATRIX_H
#include "vector.h"
class Matrix3D
{
    private:
    double a[3], b[3], c[3];
    public:
    friend std::istream& operator >> (std::istream &is, Matrix3D &mat);
    friend Matrix3D operator * (const double a, const Matrix3D& mat);
    friend std::ostream& operator << (std::ostream& os, const Matrix3D& mat);
    Matrix3D();
    Matrix3D(double a11, double a12, double a13,
    double a21, double a22, double a23, 
    double a31, double a32, double a33);

    Matrix3D operator * (const double a) const;

    Matrix3D operator - (const Matrix3D& mat) const;

    Matrix3D operator + (const Matrix3D& mat) const;

    Vector3D operator * (const Vector3D& v) const;

    Matrix3D operator * (const Matrix3D& mat) const;

    double det() const;
};

std::ostream& operator << (std::ostream& os, const Matrix3D& mat);

std::istream& operator >> (std::istream &is, Matrix3D &mat);

Matrix3D operator * (const double a, const Matrix3D& mat);
#endif