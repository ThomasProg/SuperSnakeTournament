#include "Snake.h"
#include "SdlApp.h"
#include "Color.h"

Snake::Snake()
{
	for (int i = 0; i < 1; i++)
	{
		bodyParts.emplace_back();
	}

	bodyParts.front().location = { 0,0 };
}

void Snake::draw(SdlApp& app)
{
	for (SnakeBody& body : bodyParts)
	{
		body.draw(app);
	}
}

void Snake::update()
{
	if (!bodyParts.empty())
	{
		std::vector<SnakeBody>::iterator it = bodyParts.begin();
		Vec2Int lastLoc = it->location;
		it->location += direction;
		
		++it;

		while (it != bodyParts.end())
		{
			Vec2Int temp = it->location;
			it->location = lastLoc;
			lastLoc = temp;

			++it;
		}
	}
}

void Snake::inputs(const SDL_Event& event)
{
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.scancode)
		{
		case SDL_SCANCODE_W:
			direction = {0, -1};
			break;
		case SDL_SCANCODE_S:
			direction = { 0, 1 };
			break;
		case SDL_SCANCODE_A:
			direction = { -1, 0 };
			break;
		case SDL_SCANCODE_D:
			direction = { 1, 0 };
			break;

		default:
			break;
		}
	}
}