#include <stdio.h>

int main() {
    FILE *file = fopen("data.bin", "rb");

    if (file == NULL) {
        printf("Error opening file");
        return 1;
    }

    int num_records;
    fread(&num_records, sizeof(int), 1, file);
    printf("Number of records: %d\n", num_records);

    for (int i = 0; i < num_records; i++) {
        int id;
        fread(&id, sizeof(int), 1, file);

        char name[256];
        fread(name, sizeof(char), 256, file);

        double value;
        fread(&value, sizeof(double), 1, file);

        printf("Record %d: ID=%d, Name=%s, Value=%.2f\n", i+1, id, name, value);
    }

    fclose(file);

    return 0;
}
