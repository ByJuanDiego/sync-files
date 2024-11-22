#pragma once

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_FILES 10
#define MIN_FILES 2

#define PERMISSION_MODE 0644

int init_files(int num_files, int *file_descriptors);

void close_files(int num_files, int *file_descriptors);
