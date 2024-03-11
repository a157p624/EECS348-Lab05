#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 12
#define MAX_LINE_LENGTH 100

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    float numbers[MAX_LINES];
    const char *months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };
    int i = 0;
    float sum = 0;
    float min_number = 0;
    float max_number = 0;

    // Open file
    file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Couldn't open");
        return 1;
    }

    // Read each line and convert string number into float
    while (fgets(line, sizeof(line), file) && i < MAX_LINES) {
        numbers[i] = atof(line);
        sum += numbers[i];
      // Find min and max number
        if (i == 0 || numbers[i] < min_number) {
            min_number = numbers[i];
        }
        if (i == 0 || numbers[i] > max_number) {
            max_number = numbers[i];
        }
        i++;
    }

    // Close file
    fclose(file);

    // Print months and sales
    printf("Monthly sales report for 2022\n");
    printf("%-15s %s\n", "Month", "Sales");
    for (int j = 0; j < i; j++) {
        printf("%-15s %s%.2f \n", months[j], "$", numbers[j]);
    }

    // Print minimum, maximum, and average sales
    printf("\nSales summary:");
    printf("\nMinimum sales: %s%.2f (%s)\n", "$", min_number, months[i - 12]);
    printf("Maximum sales: %s%.2f (%s)\n", "$", max_number, months[i - 1]);
    float average = sum / i;
    printf("Average sales: %s%.2f\n", "$", average);

    // Calculate and print six-month moving averages
    printf("\nSix-month moving average:\n");
    for (int j = 5; j < i; j++) {
        float moving_average = (numbers[j] + numbers[j - 1] + numbers[j - 2] + numbers[j - 3] + numbers[j - 4] + numbers[j - 5]) / 6;
        printf("%-15s%s%-15s %s%.2f\n", months[j - 5]," - ", months[j], "$", moving_average);
    }

    // Array to store sorted months and sales
    float sorted_numbers[MAX_LINES];
    const char *sorted_months[MAX_LINES];
    // Copy sales and months arrays into the sorted arrays
    for (int j = 0; j < i; j++) {
        sorted_numbers[j] = numbers[j];
        sorted_months[j] = months[j];
    }
    // Sort the sorted arrays in descending order
    for (int j = 0; j < i; j++) {
        for (int k = j + 1; k < i; k++) {
            if (sorted_numbers[j] < sorted_numbers[k]) {
                float temp_number = sorted_numbers[j];
                const char *temp_month = sorted_months[j];
                sorted_numbers[j] = sorted_numbers[k];
                sorted_months[j] = sorted_months[k];
                sorted_numbers[k] = temp_number;
                sorted_months[k] = temp_month;
            }
        }
    }

    // Print the sorted months and sales
    printf("\n\nSales report (highest to lowest):\n");
    printf("-------------------------\n");
    for (int j = 0; j < i; j++) {
        printf("%-15s %.2f\n", sorted_months[j], sorted_numbers[j]);
    }
    return 0;
}
