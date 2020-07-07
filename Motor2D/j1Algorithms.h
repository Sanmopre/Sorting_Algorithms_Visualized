#ifndef __j1ALGORITHMS_H__
#define __j1ALGORITHMS_H__

#include "j1Module.h"

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


public:

};

#endif // __j1ALGORITHMS_H__