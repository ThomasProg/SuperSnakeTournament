#include "SpeedUpItem.h"

#include "Snake.h"
#include "Color.h"

void SpeedUpItem::consume(Snake& snake)
{
	snake.speedUp();
}

void SpeedUpItem::draw(SdlApp& app)
{
	SDL_Texture* texture = app.textureManager->getTexture(ItemType::SpeedUpItem);
	if (texture != nullptr)
	{
		app.drawTexture(texture, NULL, SDL_Rect{ location.x,location.y,1,1 });
	}
}