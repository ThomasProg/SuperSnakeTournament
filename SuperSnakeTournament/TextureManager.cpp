#include "TextureManager.h"

#include "SdlApp.h"
#include <SDL_image.h>

TextureManager::TextureManager(SdlApp& app)
	: sdlApp(app)
{

}

TextureManager::~TextureManager()
{
	for (std::pair<const ItemType, SDL_Texture*> tex : textures)
	{
		if (tex.second != nullptr)
		{
			SDL_DestroyTexture(tex.second);
		}
	}
}

bool TextureManager::addTexture(const char* filename, ItemType key)
{
	SDL_Surface* surface = IMG_Load(filename);
	if (surface != nullptr)
	{
		textures.emplace(key, SDL_CreateTextureFromSurface(sdlApp.renderer, surface));
		SDL_FreeSurface(surface);
		return true;
	}
	return false;
}

SDL_Texture* TextureManager::getTexture(ItemType key)
{
	std::map<const ItemType, SDL_Texture*>::iterator it = textures.find(key);
	if (it != textures.end())
	{
		return it->second;
	}
	else
	{
		return nullptr;
	}
}