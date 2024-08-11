#include "Vector2DInt.h"

Vector2DInt::Vector2DInt() {
	x = 0;
	y = 0;
}

Vector2DInt::Vector2DInt(int x, int y) {
	this->x = x;
	this->y = y;
}

Vector2DInt& Vector2DInt::add(const Vector2DInt& v) {
	this->x += v.x;
	this->y += v.y;
	return *this;
}

Vector2DInt& Vector2DInt::subtract(const Vector2DInt& v) {
	this->x -= v.x;
	this->y -= v.y;
	return *this;
}

Vector2DInt& Vector2DInt::multiply(const Vector2DInt& v) {
	this->x *= v.x;
	this->y *= v.y;
	return *this;
}

Vector2DInt& Vector2DInt::divide(const Vector2DInt& v) {
	this->x /= v.x;
	this->y /= v.y;
	return *this;
}

Vector2DInt& operator+(Vector2DInt& v1, const Vector2DInt& v2) {
	return v1.add(v2);
}

Vector2DInt& operator-(Vector2DInt& v1, const Vector2DInt& v2) {
	return v1.subtract(v2);
}

Vector2DInt& operator*(Vector2DInt& v1, const Vector2DInt& v2) {
	return v1.multiply(v2);
}

Vector2DInt& operator/(Vector2DInt& v1, const Vector2DInt& v2) {
	return v1.divide(v2);
}

Vector2DInt& Vector2DInt::operator+=(const Vector2DInt& v) {
	return this->add(v);
}

Vector2DInt& Vector2DInt::operator-=(const Vector2DInt& v) {
	return this->subtract(v);
}

Vector2DInt& Vector2DInt::operator*=(const Vector2DInt& v) {
	return this->multiply(v);
}

Vector2DInt& Vector2DInt::operator/=(const Vector2DInt& v) {
	return this->divide(v);
}

std::ostream& operator<<(std::ostream& stream, const Vector2DInt& v) {
	stream << "(" << v.x << ", " << v.y << ")";
	return stream;
}
