#pragma once

struct Color
{
	int r, g, b, a;

	inline static Color green()
	{
		return Color{0,255,0,255};
	}
};

