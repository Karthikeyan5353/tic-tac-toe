#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10

// Structure to represent a candidate
typedef struct {
    char name[50];
    int votes;
} Candidate;

// Function to cast a vote for a candidate
void vote(Candidate candidates[], int numCandidates) {
    int choice;
    printf("Candidates:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
    printf("Enter your choice (1-%d): ", numCandidates);
    scanf("%d", &choice);

    // Validate choice
    if (choice < 1 || choice > numCandidates) {
        printf("Invalid choice!\n");
        return;
    }

    // Increment vote count for the chosen candidate
    candidates[choice - 1].votes++;
    printf("You have voted for %s.\n", candidates[choice - 1].name);
}

// Function to display the results
void displayResults(Candidate candidates[], int numCandidates) {
    printf("Voting Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int numCandidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);

    // Validate number of candidates
    if (numCandidates < 1 || numCandidates > MAX_CANDIDATES) {
        printf("Invalid number of candidates!\n");
        return 1;
    }

    // Initialize candidates
    Candidate candidates[MAX_CANDIDATES];
    for (int i = 0; i < numCandidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    int choice;
    do {
        printf("\n1. Vote\n");
        printf("2. Display Results\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                vote(candidates, numCandidates);
                break;
            case 2:
                displayResults(candidates, numCandidates);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}
