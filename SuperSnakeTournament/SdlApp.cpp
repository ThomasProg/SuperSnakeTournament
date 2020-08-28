#include "SdlApp.h"

#include "Color.h"

void SdlApp::drawRectangle(const Color& color, const SDL_Rect& rect)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	const SDL_Rect finalRect{rect.x * scale, rect.y * scale, rect.w * scale, rect.h * scale};
	SDL_RenderFillRect(renderer, &finalRect);
}