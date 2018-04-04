#ifndef PAGE_H
#define PAGE_H

// Random generator Includes
#include<cstdlib>

//A dummy Page structure that will be stored in the PageTable
struct Page{
	// Static constants to generate IDs
	const static unsigned int MAX_PAGE_ID = 1024;
	const static unsigned int INVALID_PAGE_ID = -1;

	// public ID for every Page instance
	unsigned int id;
	
	// Constructors
	Page(){this->id = rand() % MAX_PAGE_ID;}
	Page(int id){this->id = id;}

	// Special static method to generate invalid pages
	static Page invalidPage(){return Page(Page::INVALID_PAGE_ID);}

	// '=='comparators overloaded
	virtual bool operator == (const Page& page){return this->id == page.id;}
	virtual bool operator == (const int id){return this->id == id;}

};

#endif
