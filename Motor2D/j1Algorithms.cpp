#include "j1App.h"
#include "j1Algorithms.h"
#include "j1Input.h"
#include "j1Array.h"
#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )

j1Algorithms::j1Algorithms() : j1Module()
{
	name.create("algorithms");
}

// Destructor
j1Algorithms::~j1Algorithms()
{}

// Called before render is available
bool j1Algorithms::Awake(pugi::xml_node& config)
{
	 
	return true;
}

bool j1Algorithms::Start()
{

	return true;
}

bool j1Algorithms::PreUpdate()
{

	return true;
}

bool j1Algorithms::Update(float dt)
{

	if (App->input->GetKey(SDL_SCANCODE_F) == KEY_DOWN) {
		Bubble_Sort(App->array->main_array);
	}

	return true;
}

// Called before quitting
bool j1Algorithms::CleanUp()
{

	return true;
}

bool j1Algorithms::Is_Ordered(int y_array[450])
{
	for (int x = 0; x < 450; x++) {
		if (y_array[x] > y_array[x + 1]) {
			return false;
		}
	}
	return true;
}

void j1Algorithms::Bubble_Sort(int x_array[450])
{
	while (!Is_Ordered(x_array)) {

		for (int i = 0; i < 450; ++i) {
			if (x_array[i] > x_array[i + 1]) {
				int k = x_array[i];

				x_array[i] = x_array[i + 1];
				x_array[i + 1] = k;
			}
		}

	}
}

void j1Algorithms::Select_Sort(Sorting_Algorithms s_type )
{
	switch (s_type) {
	case Sorting_Algorithms::BUBBLE_SORT:
		Bubble_Sort(App->array->main_array);
		break;

	case Sorting_Algorithms::NONE:
		break;
	}
}

