#!/bin/bash
if [[ "$1" == "--build" ]];
then
	echo "Rebuilding Project" && ./build.sh
fi

if ! [ -e bin/PAGE_FIFO ];
then
	echo "PROJECT EXECUTABLE NOT FOUND. Rebuilding Project..." && ./build.sh
fi

bin/PAGE_FIFO
