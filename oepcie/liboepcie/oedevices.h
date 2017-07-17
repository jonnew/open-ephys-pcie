#ifndef _INCL_GUARD_THREE
#define _INCL_GUARD_THREE

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define MAX_DEVICE_ID 3
#define DEVICE_TYPES 4

typedef struct device{
	size_t read_offset;
	size_t read_size;
	size_t write_offset;
	size_t write_size;

	int id;
} device_t;

/*
 * This is the way we settled on to hardcode device information. You are 
 * initializing a global array of devices with hardcoded information for every
 * device. You can get a devices basic info by indexing into the DEVICES array
 * with the devices id. In practice, this will be read by the header file.
 */

static const device_t DEVICES[DEVICE_TYPES] = {
	{.read_offset = 0, .read_size = (16 * 32), 
		.write_offset = 0, .write_size = 0, .id = 0}, // RHD2032
	{.read_offset = 0, .read_size = (16 * 64), 
		.write_offset = 0, .write_size = 0, .id = 1}, // RHD2064
	{.read_offset = 0, .read_size = (32 * 6), 
		.write_offset = 0, .write_size = 0, .id = 2}, // MPU950
	{.read_offset = 0, .read_size = (32 * 1),
		.write_offset = 0, .write_size = 0, .id = 3}  // Imaginary temp sensor
};

#endif