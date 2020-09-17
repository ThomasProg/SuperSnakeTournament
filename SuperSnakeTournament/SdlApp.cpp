#include "SdlApp.h"

#include "Color.h"

SdlApp::SdlApp()
{
	textureManager = std::make_unique<TextureManager>(*this);
}

void SdlApp::drawRectangle(const Color& color, const SDL_Rect& rect)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	const SDL_Rect finalRect{rect.x * scale, rect.y * scale, rect.w * scale, rect.h * scale};
	SDL_RenderFillRect(renderer, &finalRect);
}

void SdlApp::drawTexture(SDL_Texture* texture, const SDL_Rect* src, const SDL_Rect& dest)
{
	const SDL_Rect finalDest{ dest.x * scale, dest.y * scale, dest.w * scale, dest.h * scale };
	SDL_RenderCopy(renderer, texture, src, &finalDest);
}