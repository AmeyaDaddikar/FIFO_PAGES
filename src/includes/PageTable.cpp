#include "PageTable.h"

PageTable::PageTable(unsigned int f_capacity):
	page_queue(Queue(f_capacity)){
	this->f_count = 0;
	this->f_capacity = f_capacity;
	this->page_faults = 0;

	this->page_frames = new Page[this->f_capacity];

	for(int i = 0; i < this->f_capacity; i++)
		this->page_frames[i] = Page();
}

bool PageTable::isFull(){return this->f_count == this->f_capacity;}

int PageTable::getPageFrame(int id){
	for(int i = 0; i < this->f_capacity; i++)
		if(this->page_frames[i] == id)
			return i;
	
	return -1;
}

Page PageTable::requestPage(int id){
	int p_frame = this->getPageFrame(id);
	if(p_frame != -1)
		return this->page_frames[p_frame];
	
	this->page_faults ++;
	Page newPage = Page(id);
	
	if(!this->isFull()){
		this->page_frames[this->f_count] = newPage;
		this->page_queue.push(this->f_count);
		this->f_count ++;
	}
	else{
		int n_page_index = page_queue.pop();
		this->page_frames[n_page_index] = newPage;
		this->page_queue.push(this->f_count);
	}

	return newPage;
}