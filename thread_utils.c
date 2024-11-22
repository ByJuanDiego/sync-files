#include "thread_utils.h"


pthread_mutex_t mutex;

void init_thread_args(thread_args_t *args, int tid, int num_files)
{
    args->tid = tid;
    args->num_files = num_files;
}

void init_mutex()
{
    pthread_mutex_init(&mutex, NULL);
}

void lock()
{
    pthread_mutex_lock(&mutex);
}

void unlock() 
{
    pthread_mutex_unlock(&mutex);
}

void *write_file(void *args)
{
    thread_args_t *targs = (thread_args_t *)args;

    int tid = targs->tid;
    int num_files = targs->num_files;

    srand(time(NULL));

    while (1)
    {
        int fd = rand() % num_files;

        // TODO
        // lock();
        // lseek(fd, tid, SEEK_SET);
        // unlock();
    }
}

void *read_file(void *args)
{
    thread_args_t *targs = (thread_args_t *)args;

    int tid = targs->tid;
    int num_files = targs->num_files;

    srand(time(NULL));

    while (1)
    {
        int fd = rand() % num_files;

        // TODO
        // lock();
        // lseek(fd, tid, SEEK_SET);
        // unlock();
    }
}
