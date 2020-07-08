#ifndef __j1ALGORITHMS_H__
#define __j1ALGORITHMS_H__

#include "j1Module.h"


enum Sorting_Algorithms {
	BUBBLE_SORT,
	NONE
};




class j1Algorithms: public j1Module
{
public:

	j1Algorithms();

	// Destructor
	virtual ~j1Algorithms();

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

	bool Is_Ordered(int y_array[450]);
	
	void Bubble_Sort(int x_array[450]);
	void Selection_Sort(int x_array[450], int time);
	void Insertion_Sort(int x_array[450], int time);


	void Swap(int& x, int& y);

public:

	bool bubble = false;
	bool selection = false;
	bool insertion = false;



	Sorting_Algorithms type;
	int time = 0;

	int working_line = 0;
	int working_line_2 = 0;

};

#endif // __j1ALGORITHMS_H__