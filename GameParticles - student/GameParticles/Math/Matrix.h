#ifndef MATRIX_H
#define MATRIX_H

// includes
#include "Enum.h"
#include "Vect4D.h"

// forward declare
class Vect4D;

// class
class __declspec(align(16)) Matrix
{
public:

	// local enumerations
	enum MatrixRowEnum
	{
		MATRIX_ROW_0,
		MATRIX_ROW_1,
		MATRIX_ROW_2,
		MATRIX_ROW_3
	};

	Matrix();
	Matrix(Matrix& t);
	Matrix(Vect4D &tV0, Vect4D &tV1, Vect4D &tV2, Vect4D &tV3);
	~Matrix();

	void set(MatrixRowEnum row, const Vect4D &t);
	void set(const Vect4D &t0, const Vect4D &t1, const Vect4D &t2, const Vect4D &t3);
	void get(MatrixRowEnum row, Vect4D &vOut) const;
	void get(Vect4D &t0, Vect4D &t1, Vect4D &t2, Vect4D &t3) const;

	void setIdentMatrix();
	void setTransMatrix(const Vect4D &t);
	void setScaleMatrix(const Vect4D &s);
	void setRotZMatrix(const float &az);

	float &operator[](INDEX_ENUM e);

	Matrix operator*(Matrix &t);
	//Matrix operator*(float s);

	float Determinant();

	void Inverse(Matrix &out);
	Matrix GetAdjugate();
	void operator/=(const float &t);

	

public:
	// Level 4 complains nameless struct/union ...
	#pragma warning( disable : 4201)

	union
	{
		struct
		{
			Vect4D v0;
			Vect4D v1;
			Vect4D v2;
			Vect4D v3;
		};

		struct
		{
			// ROW 0
			float m0;
			float m1;
			float m2;
			float m3;

			// ROW 1
			float m4;
			float m5;
			float m6;
			float m7;

			// ROW 2
			float m8;
			float m9;
			float m10;
			float m11;

			// ROW 3
			float m12;
			float m13;
			float m14;
			float m15;
		};
	};
};

#endif  // Matrix.h
