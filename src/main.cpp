// I/O INCLUDE
#include <iostream>

// PAGE TABLE
#include "includes/PageTable.h"

// RANDOM GENERATOR INCLUDES
#include <cstdlib>
#include <ctime>

int main(int argc, char** argv){
	
	srand(time(0));		// initiating random generator
	PageTable table(32);	// initiating page requests
	
	int TOTAL_REQUESTS = 1000;
	int MAX_PAGE_ID    = 32;

	// Requests TOTAL_REQUESTS of random pages
	for(int i = 0; i < TOTAL_REQUESTS; i++){
		Page req_page = table.requestPage(std::rand() % MAX_PAGE_ID);
		std::cout << req_page.id << ", "<<table.getPageFaults()<< std::endl;
	}
	
	// Calculates the percentage of page faults occured
	std::cout << "FAULT PERCENTAGE = " << ((float) table.getPageFaults() / TOTAL_REQUESTS) * 100 << std::endl;
	return 0;
}
