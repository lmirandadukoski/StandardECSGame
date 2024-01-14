#ifndef Vector2D_h
#define Vector2D_h

#include <iostream>

struct Vector2D {
public:
	float x;
	float y;

	Vector2D();
	Vector2D(float x, float y);

	Vector2D& add(const Vector2D& v);
	Vector2D& subtract(const Vector2D& v);
	Vector2D& multiply(const Vector2D& v);
	Vector2D& divide(const Vector2D& v);

	friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);

	Vector2D& operator +=(const Vector2D& v);
	Vector2D& operator -=(const Vector2D& v);
	Vector2D& operator *=(const Vector2D& v);
	Vector2D& operator /=(const Vector2D& v);

	friend std::ostream& operator<<(std::ostream& stream, const Vector2D& v);
};

#endif
