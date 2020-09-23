#pragma once

#include <iostream>
#include <cmath>


namespace vec{

  template<typename T>
  class Vector{
  private:
  	T xPos;
  	T yPos;
  	T zPos;
  	
  public:
  	Vector(T ijk)
  	:	xPos(ijk),
  		yPos(ijk),
  		zPos(ijk)
  	{}
  	Vector(T i, T j, T k)
  	:	xPos(i),
  		yPos(j),
  		zPos(k)
  	{}

	~Vector();
  	
  	// Operator Overload -  ensure operations in order of vector * scalar
  	Vector<T> operator + (const T &scalar) const; /
  	Vector<T> operator + (const Vector<T> &vector) const;
  	
  	Vector<T> operator - (const T &scalar) const; 
  	Vector<T> operator - (const Vector<T> &vector) const;

  	Vector<T> operator * (const T &scalar) const; 
  	Vector<T> operator * (const Vector<T> &vector) const;
  	
  	Vector<T> operator / (const T &scalar) const; 
  	Vector<T> operator / (const Vector<T> &vector) const;
  	
  	Vector<T> operator += (const T &scalar) const; 
  	Vector<T> operator += (const Vector<T> &vector) const;
  	
  	Vector<T> operator -= (const T &scalar) const; 
  	Vector<T> operator -= (const Vector<T> &vector) const;

	friend std::stream & operator << (std::stream &os, const Vector<T> &vector);

	// Funcs
	T magnitude() const;

	T dotProduct(const Vector<T> vector) const;

	Vector<T> crossProduct(const Vector<T> &vector) const;

	Vector<T> & normal();

  	
  };

}

