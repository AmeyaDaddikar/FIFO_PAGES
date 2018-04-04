# FIFO_PAGES
An attempt to demonstrate the FIFO mechanism of the Pages in the computer architectures.

## IMPLEMENTATION
The implementation is simple, and comprises of 3 main classes:
1. A dummy Page structure
2. A Queue class to simulate a fixed size queue
3. A PageTable class to manage the page frames and the queue.

The Pages are identified by their IDs. Whenever the user requests for a Page, the following algorithm is followed:

```
SEARCH page IN page_frames ACCORDING TO page_id
IF page EXISTS IN page_frames
    RETURN page
ELSE
    INCREMENT page_faults
    CREATE new_page with new_page.id = page_id
    IF page_frames IS NOT FULL
        ADD new_page to page_frames
    ELSE
        GET frame_number OF FIRST PAGE REQUESTED (USING QUEUE)
        REPLACE THE PAGE AT THE FRAME frame_number WITH new_frame
    
    RETURN new_frame
```

## INSTALLATION AND EXECUTION
The project was created and written entirely on shell, so there isn't a well defined project workspace.
use build.sh to compile the project
use run.sh to run the project

