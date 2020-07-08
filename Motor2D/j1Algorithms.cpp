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
		selection = false;
		insertion = false;
		heap = false;
		pancake = false;
	}

	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_DOWN) {
		time = 0;
		selection = true;
		bubble = false;
		insertion = false;
		heap = false;
		pancake = false;
	}

	if (App->input->GetKey(SDL_SCANCODE_G) == KEY_DOWN) {
		time = 0;
		selection = false;
		bubble = false;
		insertion = true;
		heap = false;
		pancake = false;
	}


	if (App->input->GetKey(SDL_SCANCODE_H) == KEY_DOWN) {
		time = 450;
		selection = false;
		bubble = false;
		insertion = false;
		heap = true;
		pancake = false;
	}

	if (App->input->GetKey(SDL_SCANCODE_J) == KEY_DOWN) {
		time = 450;
		selection = false;
		bubble = false;
		insertion = false;
		heap = false;
		pancake = true;
	}


	if(bubble == true)
		Bubble_Sort(App->array->main_array);

	if (selection == true) {	
		Selection_Sort(App->array->main_array, time);
	}

	if (insertion == true) {
		Insertion_Sort(App->array->main_array, time);
	}

	if (heap == true) {
		Heap_Sort(App->array->main_array, time);
	}

	if (pancake  == true) {
		Pancake_Sort(App->array->main_array, time);
	}

	if (Is_Ordered(App->array->main_array)) {
		bubble = false;
		selection = false;
		insertion = false;
		heap = false;
		pancake = false;
	}

	if (heap == true || pancake == true)
		time--;
	else
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
					Swap(x_array[i], x_array[i + 1]);
				}
			}
		
	}
}

void j1Algorithms::Selection_Sort(int x_array[450], int time)
{
		int  j, min_idx;

				if(time < 450) 
				{
					min_idx = time;
					for (j = time + 1; j < 450; j++)
						if (x_array[j] < x_array[min_idx])
							min_idx = j;

					working_line = min_idx;
					working_line_2 = time;

					int k = x_array[min_idx];
					x_array[min_idx] = x_array[time];
					x_array[time] = k;
				}
			
}

void j1Algorithms::Insertion_Sort(int x_array[450], int time)
{
	int i, key, j;
	if (time < 450)
	{
		key = x_array[time];
		j = time - 1;


		while (j >= 0 && x_array[j] > key)
		{
			x_array[j + 1] = x_array[j];
			j = j - 1;
		}
		x_array[j + 1] = key;
	}
}

void j1Algorithms::Heap_Sort(int x_array[450], int time)
{

	if(time/2 - 1 >= 0)
		heapify(x_array, 450, time/2 - 1);

	if(time - 1 > 0)
	{
		Swap(x_array[0], x_array[time - 1]);
		heapify(x_array, time - 1, 0);
	}
}

void j1Algorithms::heapify(int arr[], int n, int i)
{
	int largest = i;  
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 

 
	if (l < n && arr[l] > arr[largest])
		largest = l;


	if (r < n && arr[r] > arr[largest])
		largest = r;


	if (largest != i)
	{
		Swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void j1Algorithms::Pancake_Sort(int x_array[450], int time)
{
	if (time > 1)
	{

		int mi = findMax(x_array, time);


		if (mi != time - 1)
		{
	 
			flip(x_array, mi);

	
			flip(x_array, time - 1);
		}
	}
}

void j1Algorithms::flip(int arr[], int i)
{
	int temp, start = 0;
	while (start < i)
	{
		temp = arr[start];
		arr[start] = arr[i];
		arr[i] = temp;
		start++;
		i--;
	}
}

int j1Algorithms::findMax(int arr[], int n)
{
	int mi, i;
	for (mi = 0, i = 0; i < n; ++i)
		if (arr[i] > arr[mi])
			mi = i;
	return mi;
}

void j1Algorithms::Swap(int& x, int& y)
{
		int temp = x;
		x = y;
		y = temp;
}


