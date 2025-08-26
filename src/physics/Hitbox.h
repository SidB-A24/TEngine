#pragma once

#include "raylib.h"
#include "raymath.h"
#include "../supplementaries/RaylibVector2Operators.h"

#include <vector>

namespace TPhysics
{
	class HitBox
	{
	public:
		virtual bool is_pt_in_hitbox(Vector2 pt) { return false; };

		virtual std::vector<Vector2> get_points_on_perimeter(size_t count) 
		{
				return { Vector2{0, 0}, Vector2{0, 0} };
		} //This count doesnt really matter too much. 
	};

	class HitBox_Rectangle : public HitBox
	{
	public:
		HitBox_Rectangle(Vector2 dimensions, Vector2 posCenter, float rotRadians);

		bool is_pt_in_hitbox(Vector2 pt) override;

		std::vector<Vector2> get_points_on_perimeter(size_t count) override;


	private:
		Vector2 p_dimensions;
		Vector2 p_pos; //Center of the rectangle
		float p_rotRadians;
	};

	class HitBox_Circle : public HitBox
	{
	public:
		HitBox_Circle(Vector2 pos, float radius);
		
		bool is_pt_in_hitbox(Vector2 pt) override;

	private:
		float p_radius;
		Vector2 p_pos;
		float p_rotRadians;
	};
}