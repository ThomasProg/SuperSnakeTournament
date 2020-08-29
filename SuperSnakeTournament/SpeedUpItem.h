#pragma once

#include "Item.h"

class SpeedUpItem final : public Item
{
public:
	inline SpeedUpItem(Vec2Int loc)
		: Item(loc)
	{

	}

	void consume(Snake& snake) override final;
	void draw(SdlApp& app) override final;
};

