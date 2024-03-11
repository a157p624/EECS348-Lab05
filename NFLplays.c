#include <stdio.h>

// Function to print all possible combinations of scoring plays for a given score
void combinations(int score, int td2, int td1, int td, int fg, int safety) {
    // Print counts of each scoring play and return
    if (score == 0) {
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2, td1, td, fg, safety);
        return;
    }
    // If score is at least one of the scoring points, subtract that score and use recursion
    if (score >= 8) combinations(score - 8, td2 + 1, td1, td, fg, safety);
    if (score >= 7) combinations(score - 7, td2, td1 + 1, td, fg, safety);
    if (score >= 6) combinations(score - 6, td2, td1, td + 1, fg, safety);
    if (score >= 3) combinations(score - 3, td2, td1, td, fg + 1, safety);
    if (score >= 2) combinations(score - 2, td2, td1, td, fg, safety + 1);
}

int main() {
    int score;
    // Ask user for score
    printf("Enter 0 or 1 to STOP\n");
    // Loop until score is 0 or 1
    while (1) {
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        // If score is 0 or 1, break loop
        if (score <= 1) break;
        // Call function to print all possibilities
        combinations(score, 0, 0, 0, 0, 0);
    }
    return 0;
}
