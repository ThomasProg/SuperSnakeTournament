#include "SlowDownItem.h"

#include "Snake.h"
#include "Color.h"

void SlowDownItem::consume(Snake& snake) 
{
	snake.slowDown();
}

void SlowDownItem::draw(SdlApp& app)
{
	SDL_Texture* texture = app.textureManager->getTexture(ItemType::SlowDownItem);
	if (texture != nullptr)
	{
		app.drawTexture(texture, NULL, SDL_Rect{ location.x,location.y,1,1 });
	}
}