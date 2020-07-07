#ifndef __j1ARRAY_H__
#define __j1ARRAY_H__

#include "j1Module.h"
#include "p2DynArray.h"


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

public:

	p2DynArray<int*> array;

};

#endif // __j1ARRAY_H__