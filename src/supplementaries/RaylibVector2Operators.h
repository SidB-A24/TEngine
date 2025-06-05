#pragma once

#include "raylib.h"

//Addition
inline Vector2 operator+(const Vector2& v1, const Vector2& v2)
{
	return Vector2{
		v1.x + v2.x,
		v1.y + v2.y
	};
}

//Dot product
inline float operator*(const Vector2& v1, const Vector2& v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

//Cross product
inline float operator%(const Vector2& v1, const Vector2& v2)
{
	return v1.x * v2.y - v1.y * v2.x; //From determinant
}

//Scaling
inline Vector2 operator*(const Vector2& v, float F)
{
	return Vector2{
		v.x * F,
		v.y * F
	};
}

//Equality
inline bool operator==(const Vector2& v1, const Vector2& v2)
{
	return (v1.x == v2.x) && (v1.y == v2.y);
}