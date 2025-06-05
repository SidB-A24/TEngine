#pragma once
#include "raylib.h"
#include "raymath.h"

#include <functional>

//Implements a hash function for the Vector2 struct in Raylib.
namespace std
{
	template<>
	struct hash<Vector2>
	{
		size_t operator()(const Vector2& v) const //Function is promising to be const to the struct and reference is promising to be const to the passed in obj.
		{
			size_t hashX = std::hash<float>()(v.x); //Hashes the float values of the coordinates of x
			size_t hashY = std::hash<float>()(v.y); 

			return hashX ^ (hashY << 1);
			/*
			Here we use a bitwise XOR (^) to "mix" the hash of X and Y. 
			Additionally we bitshift (<< 1) the hash of Y by 1 bit to prevent hash collisions. Because {1, 2} and {2, 1} will result in the same hash value otherwise.
			*/
		}
	};

	
}

