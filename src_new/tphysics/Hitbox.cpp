#include "Hitbox.h"

//
//RECTANGLE
//
TPhysics::HitBox_Rectangle::HitBox_Rectangle(Vector2 dimensions, Vector2 pos, float rotRadians)
	: p_dimensions(dimensions), p_pos(pos), p_rotRadians(rotRadians), HitBox()
{


}

bool TPhysics::HitBox_Rectangle::is_pt_in_hitbox(Vector2 pt)
{
	Vector2 transformedPt = Vector2Rotate((pt-p_pos), -p_rotRadians) + p_pos;

	if (((p_pos - (p_dimensions * 0.5)) <= pt) && (pt <= (p_pos + (p_dimensions * 0.5))))
	{
		return true;
	}
	
}

std::vector<Vector2> TPhysics::HitBox_Rectangle::get_points_on_perimeter(size_t count)
{
	std::vector<Vector2> preTransformPoints =
	{
		(p_pos - (p_dimensions * 0.5)),
		(p_pos + (p_dimensions * 0.5)),
		(p_pos - (p_dimensions * 0.5) + Vector2{p_dimensions.x, 0}),
		(p_pos - (p_dimensions * 0.5) + Vector2{0, p_dimensions.y})
	};
	std::vector<Vector2> transformedPoints;

	for (Vector2 pt : preTransformPoints)
	{
		transformedPoints.push_back(Vector2Rotate((pt-p_pos), p_rotRadians) + p_pos);
	}

	return transformedPoints;
}

//
//CIRCLE
//

TPhysics::HitBox_Circle::HitBox_Circle(Vector2 pos, float radius)
	:p_pos(pos), p_radius(radius)
{

}

bool TPhysics::HitBox_Circle::is_pt_in_hitbox(Vector2 pt)
{
	return Vector2Length(pt - p_pos) <= p_radius;
}
