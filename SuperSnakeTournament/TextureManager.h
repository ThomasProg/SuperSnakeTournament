#pragma once

#include <map>
#include "ItemType.h"

struct SdlApp;
struct SDL_Texture;

class TextureManager
{
private:
	std::map<ItemType, SDL_Texture*> textures;
	SdlApp& sdlApp;

public:
	TextureManager(SdlApp& app);
	~TextureManager();

	// Returns true if the texture is added correctly
	bool addTexture(const char* filename, ItemType key);

	SDL_Texture* getTexture(ItemType key);
};

