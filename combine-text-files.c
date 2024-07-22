#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// Function to check if a file is a text file
int is_text_file(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        return 0;
    }
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if ((ch < 32 || ch > 126) && ch != 10 && ch != 13 && ch != 9) {
            fclose(file);
            return 0;
        }
    }
    fclose(file);
    return 1;
}

// Function to read and append files
void read_and_append_files(const char *input_folder, FILE *out_file, const char *output_file_name, const char *relative_path) {
    struct dirent *entry;
    DIR *dp = opendir(input_folder);
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_name[0] == '.') continue;

        char file_path[1024];
        snprintf(file_path, sizeof(file_path), "%s/%s", input_folder, entry->d_name);

        struct stat statbuf;
        if (stat(file_path, &statbuf) == -1) {
            perror("stat");
            continue;
        }

        char new_relative_path[1024];
        if (relative_path[0] == '\0') {
            snprintf(new_relative_path, sizeof(new_relative_path), "%s", entry->d_name);
        } else {
            snprintf(new_relative_path, sizeof(new_relative_path), "%s/%s", relative_path, entry->d_name);
        }

        if (S_ISDIR(statbuf.st_mode)) {
            read_and_append_files(file_path, out_file, output_file_name, new_relative_path);
        } else {
            // Skip the output file itself
            if (strcmp(entry->d_name, output_file_name) == 0) continue;

            if (is_text_file(file_path)) {
                fprintf(out_file, "File: %s\n", new_relative_path);
                fprintf(out_file, "------\n");

                FILE *in_file = fopen(file_path, "r");
                if (in_file) {
                    char buffer[1024];
                    size_t n;
                    while ((n = fread(buffer, 1, sizeof(buffer), in_file)) > 0) {
                        fwrite(buffer, 1, n, out_file);
                    }
                    fclose(in_file);
                }

                fprintf(out_file, "\n------\n\n");
            }
        }
    }

    closedir(dp);
}

int main() {
    char input_folder[1024];
    if (getcwd(input_folder, sizeof(input_folder)) == NULL) {
        perror("getcwd");
        return 1;
    }

    char output_file_path[1024];
    snprintf(output_file_path, sizeof(output_file_path), "%s/single_file.txt", input_folder);

    FILE *out_file = fopen(output_file_path, "w");
    if (!out_file) {
        perror("fopen");
        return 1;
    }

    // Pass the name of the output file and an empty initial relative path to the function
    read_and_append_files(input_folder, out_file, "single_file.txt", "");
    fclose(out_file);

    printf("All text files from '%s' have been combined into '%s'.\n", input_folder, output_file_path);
    return 0;
}
