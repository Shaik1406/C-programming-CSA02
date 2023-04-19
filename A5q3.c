#include <stdio.h>
#include <string.h>

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening files");
        return 1;
    }

    char line[1024];

    while (fgets(line, sizeof(line), input_file)) {
        char *pos = line;
        while ((pos = strstr(pos, "red")) != NULL) {
            fprintf(output_file, "%.*s", (int)(pos-line), line);
            fputs("blue", output_file);
            pos += 3;
        }
        fputs(line, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}
