#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    FILE *fp;
    char filename[100];
    char delimiter[] = ",";
    char buffer[1000];
    int count = 0;
    double current_number, sum = 0, avg = 0, variance = 0, std_dev = 0;
    double max_number = -INFINITY, min_number = INFINITY;

    // Get filename from user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Process data from the file
    while (fgets(buffer, 1000, fp)) {
        char *token = strtok(buffer, delimiter);
        while (token != NULL) {
            sscanf(token, "%lf", &current_number);
            sum += current_number;
            count++;
            if (current_number > max_number) {
                max_number = current_number;
            }
            if (current_number < min_number) {
                min_number = current_number;
            }
            token = strtok(NULL, delimiter);
        }
    }

    // Close the file
    fclose(fp);

    // Calculate average
    avg = sum / count;

    // Calculate variance and standard deviation
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    while (fgets(buffer, 1000, fp)) {
        char *token = strtok(buffer, delimiter);
        while (token != NULL) {
            sscanf(token, "%lf", &current_number);
            variance += pow(current_number - avg, 2);
            token = strtok(NULL, delimiter);
        }
    }
    fclose(fp);
    variance /= count;
    std_dev = sqrt(variance);

    // Output results
    printf("Largest number: %.2lf\n", max_number);
    printf("Smallest number: %.2lf\n", min_number);
    printf("Average of the numbers: %.2lf\n", avg);
    printf("Standard deviation of the numbers: %.2lf\n", std_dev);

    return 0;
}
