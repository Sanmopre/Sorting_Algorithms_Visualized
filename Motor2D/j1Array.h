#ifndef __j1ARRAY_H__
#define __j1ARRAY_H__

#include "j1Module.h"
#include "p2DynArray.h"

struct SDL_Texture;

class j1Array : public j1Module
{
public:

	j1Array();

	// Destructor
	virtual ~j1Array();

	// Called before render is available
	bool Awake(pugi::xml_node&);

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before quitting
	bool CleanUp();

	// Draws each position
	void Draw(int position, int size);

	// Randomizes the array
	void Random_Array();


public:

	int main_array[450];

private:

	SDL_Texture* texture = nullptr;

	SDL_Texture* texture_2 = nullptr;

	SDL_Texture* texture_3 = nullptr;
};

#endif // __j1ARRAY_H__