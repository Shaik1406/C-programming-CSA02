#include <stdio.h>

int main() {
    FILE *input_file = fopen("data.txt", "r");
    FILE *output_file = fopen("statistics.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening files");
        return 1;
    }

    int letter_counts[26] = {0}; // initialize all counts to 0

    int c;
    while ((c = fgetc(input_file)) != EOF) {
        if (c >= 'a' && c <= 'z') {
            letter_counts[c - 'a']++;
        } else if (c >= 'A' && c <= 'Z') {
            letter_counts[c - 'A']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        fprintf(output_file, "%c: %d\n", 'A' + i, letter_counts[i] + letter_counts[i + 32]);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}
