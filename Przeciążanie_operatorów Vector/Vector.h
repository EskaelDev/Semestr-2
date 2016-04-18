#pragma once
class Vector
{
	float *tab;
	int increment;
public:
	Vector();
	Vector(int N, int M);
	Vector(const Vector&);

	Vector& operator=(const Vector &);
	Vector operator+(const Vector &);
	Vector operator-(const Vector &);
	Vector operator*(const Vector &);

	int Size();
	float Display();
	void PushBack(const float);


	~Vector();
};

