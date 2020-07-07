#include "j1App.h"
#include "j1Array.h"
#include "j1Textures.h"
#include "j1Render.h"
#include "j1Input.h"
#include <stdlib.h>  
#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )

j1Array::j1Array() : j1Module()
{
	name.create("array");
}

// Destructor
j1Array::~j1Array()
{}

// Called before render is available
bool j1Array::Awake(pugi::xml_node& config)
{
	bool ret = true;
	

	return ret;
}

bool j1Array::Start()
{
	texture = App->tex->Load("textures/texture.png");
	Random_Array();

	return true;
}

bool j1Array::PreUpdate()
{

	return true;
}

bool j1Array::Update(float dt)
{

	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN) {
		Random_Array();
	}

	for (int i = 0; i < 450; i++) {
		Draw(i, main_array[i]);
	}
	return true;
}

// Called before quitting
bool j1Array::CleanUp()
{
	
	return true;
}

void j1Array::Draw(int position, int size)
{
	for (int i = 0; i < size; i++) {
		App->render->Blit(texture, position * 2, 890 - i);
	}
}

void j1Array::Random_Array()
{
	for (int i = 0; i < 450; i++) {
		main_array[i] = rand() % 450 + 1;
	}
}

