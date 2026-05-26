#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    int sum = 0;
    char line[128];

    while (fgets(line, sizeof(line), fp)) {
        int val;
        if (sscanf(line, "%d", &val) == 1) {
            sum += val;
        } else {
            if (line[0] != '\n' && line[0] != '\r' && line[0] != '\0') {
                int len = 0;
                while (line[len] != '\n' && line[len] != '\r' && line[len] != '\0') {
                    len++;
                }
                line[len] = '\0';
                fprintf(stderr, "invalid input %s\n", line);
            }
        }
    }

    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}
