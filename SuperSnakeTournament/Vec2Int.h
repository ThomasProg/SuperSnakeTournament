#pragma once

struct Vec2Int
{
	int x, y;

	inline Vec2Int& operator+=(const Vec2Int& rhs)
	{
		x += rhs.x;
		y += rhs.y;

		return *this;
	}

	inline bool operator==(const Vec2Int& rhs)
	{
		return x == rhs.x && y == rhs.y;
	}
};

