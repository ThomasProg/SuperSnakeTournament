#include "ItemReduceLife.h"

#include "Snake.h"
#include "Color.h"

void ItemReduceLife::consume(Snake& snake)
{
	snake.popBodyPart();
}

void ItemReduceLife::draw(SdlApp& app)
{
	SDL_Texture* texture = app.textureManager->getTexture(ItemType::ItemReduceLife);
	if (texture != nullptr)
	{
		app.drawTexture(texture, NULL, SDL_Rect{ location.x,location.y,1,1 });
	}
}