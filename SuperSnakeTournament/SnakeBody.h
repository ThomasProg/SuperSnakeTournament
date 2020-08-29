#pragma once

#include "SdlApp.h"
#include "Vec2Int.h"

struct SnakeBody
{
	Vec2Int location = { -10, -10 };

	void draw(SdlApp& app);
};

