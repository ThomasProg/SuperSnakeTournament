#pragma once

#include "SnakeBody.h"
#include "Vec2Int.h"

#include <SDL2/SDL.h>
#include <vector>
#include <cassert>

struct SdlApp;

class Snake
{
private:
	std::vector<SnakeBody> bodyParts;
	Vec2Int direction = {1, 0};

public:
	Snake();

	void update();
	void draw(SdlApp& app);
	void inputs(const SDL_Event& event);

	inline Vec2Int getHeadLocation() const
	{									  
		assert(!bodyParts.empty());
		return bodyParts.front().location;
	}

	inline void addBodyPart()
	{
		bodyParts.emplace_back();
	}

	inline void popBodyPart()
	{				   
		if (bodyParts.size() > 1)
		{
			bodyParts.pop_back();
		}
	}
};

