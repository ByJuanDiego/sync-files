#include "file_utils.h"

int init_files(int num_files, int *file_descriptors) {
    int files_created = 0;

    if (num_files < 0) {
        fprintf(stderr, "Please enter a positive number of files\n");
        return files_created;
    }

    if (num_files > MAX_FILES) {
        fprintf(stderr, "Number of files exceeds limit (%d)\n", MAX_FILES);
        return files_created;
    }

    for (int i = 0; i < num_files; ++i) {
        char file_name[20];
        snprintf(file_name, sizeof(file_name), "resource_%d.dat", i);

        int fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, PERMISSION_MODE);
        if (fd == -1) {
            perror("Error creating file");
            continue;
        }

        file_descriptors[files_created] = fd;
        ++files_created;
    }

    return files_created;
}

void close_files(int num_files, int *file_descriptors) {
    for (int i = 0; i < num_files; ++i) {
        if (file_descriptors[i] != -1) {
            close(file_descriptors[i]);
        }
    }
}
