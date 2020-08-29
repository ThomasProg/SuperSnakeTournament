#pragma once

#include "SnakeBody.h"
#include "Vec2Int.h"

#include <SDL2/SDL.h>
#include <vector>
#include <cassert>

struct SdlApp;
struct TimeManager;

class Snake
{
private:
	std::vector<SnakeBody> bodyParts;
	Vec2Int direction = {1, 0};

	// in ms
	Uint32 lastUpdateTime = 0;
	Uint32 updateDelay = 100;
	Uint32 maxUpdateDelay = 150;
	Uint32 minUpdateDelay = 30;
	

public:
	Snake();

	// Returns success if update is successful
	bool update(const TimeManager& timeManager);
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

	inline bool isHead(const SnakeBody& body) const
	{
		assert(!bodyParts.empty());
		return &bodyParts.front() == &body;
	}

	inline void slowDown()
	{
		updateDelay += 10;

		if (updateDelay > maxUpdateDelay)
		{
			updateDelay = maxUpdateDelay;
		}
	}

	inline void speedUp()
	{
		updateDelay -= 10;

		if (updateDelay < minUpdateDelay)
		{
			updateDelay = minUpdateDelay;
		}
	}

	bool isHeadInsideAnotherSnake(const Snake& anotherSnake) const;
};

