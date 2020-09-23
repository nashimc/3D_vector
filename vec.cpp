#include "vec.hpp"

vec::Vector(T ijk)
:	xPos(ijk),
  	yPos(ijk),
  	zPos(ijk)
{}

vec::Vector(T i, T j, T k)
:	xPos(i),
	yPos(j),
	zPos(k)
{}

Vector<T> vec::Vector::operator + (const T &scalar) const{
	return Vector<T>(xPos + scalar, yPos + scalar, zPos + scalar);
}

Vector<T> vec::Vector::operator + (const Vector<T> &vector) const{
	return Vector<T>(xPos + vector.xPos, yPos + vector.yPos, zPos + vector.zPos);
}

Vector<T> vec::Vector::operator - (const T &scalar) const{
	return Vector<T>(xPos - scalar, yPos - scalar, zPos - scalar);
}

Vector<T> vec::Vector::operator - (const Vector<T> &vector) const{
	return Vector<T>(xPos - vector.xPos, yPos - vector.yPos, zPos - vector.zPos);
}

Vector<T> vec::Vector::operator * (const T &scalar) const{
	return Vector<T>(xPos * scalar, yPos * scalar, zPos * scalar);
}

Vector<T> vec::Vector::operator * (const Vector<T> &vector) const{
	return Vector<T>(xPos * vector.xPos, yPos * vector.yPos, zPos * vector.zPos);
}

Vector<T> vec::Vector::operator / (const T &scalar) const{
	return Vector<T>(xPos / scalar, yPos / scalar, zPos / scalar);
}

Vector<T> vec::Vector::operator / (const Vector<T> &vector) const{
	return Vector<T>(xPos / vector.xPos, yPos / vector.yPos, zPos / vector.zPos);
}

Vector<T> vec::Vector::operator += (const T &scalar) const{
	return Vector<T>(xPos += scalar, yPos += scalar, zPos += scalar);
}

Vector<T> vec::Vector::operator += (const Vector<T> &vector) const{
	return Vector<T>(xPos += vector.xPos, yPos += vector.yPos, zPos += vector.zPos);
}

Vector<T> vec::Vector::operator -= (const T &scalar) const{
	return Vector<T>(xPos -= scalar, yPos -= scalar, zPos -= scalar);
}

Vector<T> vec::Vector::operator -= (const Vector<T> &vector) const{
	return Vector<T>(xPos - vector.xPos, yPos -= vector.yPos, zPos -= vector.zPos);
}

// reference current object
// std::cout << vector << endl;
std::stream & vec::Vector::operator << (std::stream &os, const Vector<T> &vector){
	os << vector.xPos << " " << vector.yPos << " " << vector.zPos;
	return os
}

T vec::Vector::magnitude() const{
	return sqrt((xPos * xPos) + (xPos * xPos) + (zPos * zPos))
}

T vec::Vector::dotProduct(const Vector<T> vector) const{
	return xPos * vector.yPos + yPos * vector.yPos + zPos * vector.zPos
}

Vector<T> vec::Vector::crossProduct(const Vector<T> &vector) const{
	return Vector<T>(yPos * vector.zPos - zPos * vector.yPos,
						zPos * vector.xPos - xPos * vector.zPos,
						xPos * vector.yPos - yPos * vector.xPos)
}

// & reference current object vector
Vector<T> & vec::normal(){
	T inverse = 1 / magnitude();
	xPos *= inverse,
	yPos *= inverse,
	zPos *= inverse;
	return *this;
}
