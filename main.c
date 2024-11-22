#include "file_utils.h"
#include "thread_utils.h"

int main(int argc, char* argv[])
{
    int num_files = 0;
    int* file_descriptors = NULL;
    pthread_t* threads_read;
    pthread_t* threads_write;

    if (argc < 2)
    {
        perror("The program must be executed in the format ./main [num_files]");
        exit(1);
    }

    if (sscanf(argv[1], "%d", &num_files) != 1) {
        perror("Invalid number of files\n");
        exit(1);
    }

    if (num_files < MIN_FILES || num_files > MAX_FILES)
    {
        perror("Invalid number of files.\n");
        exit(1);
    }

    file_descriptors = malloc(sizeof(int) * num_files);
    threads_read = malloc(sizeof(pthread_t) * num_files);
    threads_write = malloc(sizeof(pthread_t) * num_files);

    init_mutex();
    init_files(num_files, file_descriptors);

    for (int i = 0; i < num_files; ++i)
    {
        thread_args_t args;
        init_thread_args(&args, i, num_files);
        pthread_create(&threads_read[i], NULL, read_file, &args);
    }

    for (int i = 0; i < num_files; ++i)
    {
        thread_args_t args;
        init_thread_args(&args, i, num_files);
        pthread_create(&threads_write[i], NULL, write_file, &args);
    }

    for (int i = 0; i < num_files; ++i)
    {
        pthread_join(threads_read[i], NULL);
        pthread_join(threads_write[i], NULL);
    }

    // TODO: free memory
    return 0;
}
