#pragma once
		 
#include "Vec2Int.h"

#include "ItemType.h"

class Snake;
struct SdlApp;

class Item
{
protected:
	Vec2Int location;
	struct SDL_Texture* texture;

public:
	inline Item(Vec2Int loc)
		: location(loc)
	{

	}

	virtual void consume(Snake& snake) = 0;
	virtual void draw(SdlApp& app) = 0;
};

