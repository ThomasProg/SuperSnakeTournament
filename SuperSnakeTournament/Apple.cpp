#include "Apple.h"

#include "Snake.h"
#include "Color.h"
#include "SdlApp.h"
#include "ItemType.h"

#include <SDL_image.h>
#include <iostream>

void Apple::consume(Snake& snake)
{
	snake.addBodyPart();
}
												 
void Apple::draw(SdlApp& app)
{
	SDL_Texture* texture = app.textureManager->getTexture(ItemType::Apple);
	if (texture != nullptr)
	{
		app.drawTexture(texture, NULL, SDL_Rect{ location.x,location.y,1,1 });
	}
}

