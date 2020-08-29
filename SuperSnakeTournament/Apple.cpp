#include "Apple.h"

#include "Snake.h"
#include "Color.h"
#include "SdlApp.h"

void Apple::consume(Snake& snake)
{
	snake.addBodyPart();
}
												 
void Apple::draw(SdlApp& app)
{
	app.drawRectangle(Color::red(), SDL_Rect{location.x,location.y,1,1});
}