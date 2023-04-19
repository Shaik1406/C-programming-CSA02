#include <stdio.h>
#include <string.h>

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *error_file = fopen("error_log.txt", "w");

    if (input_file == NULL || error_file == NULL) {
        printf("Error opening files");
        return 1;
    }

    char line[1024];

    while (fgets(line, sizeof(line), input_file)) {
        if (strstr(line, "error")) {
            fputs(line, error_file);
        }
    }

    fclose(input_file);
    fclose(error_file);

    error_file = fopen("error_log.txt", "r");

    if (error_file == NULL) {
        printf("Error opening error log file");
        return 1;
    }

    printf("Contents of error log file:\n");

    while (fgets(line, sizeof(line), error_file)) {
        printf("%s", line);
    }

    fclose(error_file);

    return 0;
}
