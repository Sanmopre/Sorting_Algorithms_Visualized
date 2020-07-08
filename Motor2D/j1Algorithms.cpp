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
		bubble = true;
	}

	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_DOWN) {
		selection = true;
	}

	if(bubble == true)
		Bubble_Sort(App->array->main_array);

	if (selection == true) {
		Selection_Sort(App->array->main_array);
		time = 0;
	}

	if (Is_Ordered(App->array->main_array)) {
		bubble = false;
		selection = false;
	}

	time++;
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
	if (!Is_Ordered(x_array)) {

			for (int i = 0; i < 450; ++i) {
				if (x_array[i] > x_array[i + 1]) {
					int k = x_array[i];

					working_line = i;
					working_line_2 = i + 1;
					x_array[i] = x_array[i + 1];
					x_array[i + 1] = k;
				}
			}
		
	}
}

void j1Algorithms::Selection_Sort(int x_array[450])
{
		int i, j, min_idx;
		if (!Is_Ordered(x_array)) {
			if (time % 2) {
				for (i = 0; i < 450; i++)
				{
					min_idx = i;
					for (j = i + 1; j < 450; j++)
						if (x_array[j] < x_array[min_idx])
							min_idx = j;

					working_line = min_idx;
					working_line_2 = i;

					int k = x_array[min_idx];
					x_array[min_idx] = x_array[i];
					x_array[i] = k;
				}
			}
		}
}


