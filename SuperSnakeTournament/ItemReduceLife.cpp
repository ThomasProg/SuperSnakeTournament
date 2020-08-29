#include "ItemReduceLife.h"

#include "Snake.h"
#include "Color.h"

void ItemReduceLife::consume(Snake& snake)
{
	snake.popBodyPart();
}

void ItemReduceLife::draw(SdlApp& app)
{
	app.drawRectangle(Color::blue(), SDL_Rect{ location.x,location.y,1,1 });
}