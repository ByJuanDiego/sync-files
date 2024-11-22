#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>


extern pthread_mutex_t mutex;

typedef struct {
    int tid;
    int num_files;
} thread_args_t;

void init_thread_args(thread_args_t *args, int tid, int num_files);

void init_mutex();

void lock();

void unlock();

void *write_file(void *args);

void *read_file(void *args);
