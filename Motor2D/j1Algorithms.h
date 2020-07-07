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


	void Select_Sort(Sorting_Algorithms s_type = Sorting_Algorithms::NONE);


public:

	Sorting_Algorithms type;

};

#endif // __j1ALGORITHMS_H__