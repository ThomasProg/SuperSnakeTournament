#pragma once

#include "Item.h"

class ItemReduceLife final : public Item
{
public:
	inline ItemReduceLife(Vec2Int loc)
		: Item(loc)
	{

	}

	void consume(Snake& snake) override final;
	void draw(SdlApp& app) override final;
};

