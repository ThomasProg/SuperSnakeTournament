#pragma once

struct Vec2Int
{
	int x, y;

	Vec2Int& operator+=(const Vec2Int& rhs)
	{
		x += rhs.x;
		y += rhs.y;

		return *this;
	}
};

