#ifndef Vector2DInt_h
#define Vector2DInt_h

#include <iostream>

struct Vector2DInt {
public:
	int x;
	int y;

	Vector2DInt();
	Vector2DInt(int x, int y);

	Vector2DInt& add(const Vector2DInt& v);
	Vector2DInt& subtract(const Vector2DInt& v);
	Vector2DInt& multiply(const Vector2DInt& v);
	Vector2DInt& divide(const Vector2DInt& v);

	friend Vector2DInt& operator+(Vector2DInt& v1, const Vector2DInt& v2);
	friend Vector2DInt& operator-(Vector2DInt& v1, const Vector2DInt& v2);
	friend Vector2DInt& operator*(Vector2DInt& v1, const Vector2DInt& v2);
	friend Vector2DInt& operator/(Vector2DInt& v1, const Vector2DInt& v2);

	Vector2DInt& operator +=(const Vector2DInt& v);
	Vector2DInt& operator -=(const Vector2DInt& v);
	Vector2DInt& operator *=(const Vector2DInt& v);
	Vector2DInt& operator /=(const Vector2DInt& v);

	friend std::ostream& operator<<(std::ostream& stream, const Vector2DInt& v);
};

#endif
