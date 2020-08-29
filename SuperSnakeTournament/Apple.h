#pragma once

#include "Vec2Int.h"
#include "Item.h"

struct Apple : public Item
{
public:
	inline Apple(Vec2Int loc)
		: Item(loc)
	{

	}

	void consume(Snake& snake) override final;
	void draw(SdlApp& app) override final;

};

