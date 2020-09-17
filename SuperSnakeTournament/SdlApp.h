#pragma once

#include <memory>
#include <SDL2/SDL.h>
#include "TextureManager.h"

struct Color;

struct SdlApp
{
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	std::unique_ptr<TextureManager> textureManager;

	float scale = 50;

	SdlApp();

	void drawRectangle(const Color& color, const SDL_Rect& rect);
	void drawTexture(SDL_Texture* texture, const SDL_Rect* src, const SDL_Rect& dest);
};

