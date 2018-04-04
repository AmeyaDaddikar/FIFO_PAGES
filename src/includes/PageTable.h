#ifndef PAGE_TABLE_H
#define PAGE_TABLE_H

#include "Queue.h"
#include "Page.h"

class PageTable{

private:
	Page* page_frames;			// Container for Page Frames
	unsigned int f_count; 		// Total number of pages residing in the page_frames
	unsigned int f_capacity;	// Maximum capacity of page_frames

	int page_faults;			// Counts the number of page faults that occured

	Queue page_queue;			// A queue that tracks the pages being inserted to the page_frames

public:
	PageTable(unsigned int page_frames);	//Constructor
	virtual ~PageTable(){};					//Destructor

	//GETTERS AND SETTERS
	int getPageFaults(){return this->page_faults;}

	bool isFull();	//Checks if the page_frames is full

	int getPageFrame(int id);	//Returns the location of the page by it's ID
	
	Page requestPage(int id); //Returns the page from the table using the id.
							//If page is not available, creates a new page and increments the page_faults

};

#endif
