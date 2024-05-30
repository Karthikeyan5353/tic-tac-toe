#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 3
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

void displayCandidates(Candidate candidates[], int count);
void vote(Candidate candidates[], int count);
void displayResults(Candidate candidates[], int count);

int main() {
    Candidate candidates[MAX_CANDIDATES] = {
        {"Alice", 0},
        {"Bob", 0},
        {"Charlie", 0}
    };
    int voterCount = 0;
    int choice;

    while (voterCount < MAX_VOTERS) {
        printf("Voter %d:\n", voterCount + 1);
        displayCandidates(candidates, MAX_CANDIDATES);
        vote(candidates, MAX_CANDIDATES);
        voterCount++;

        printf("Do you want to add another vote? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
        if (choice == 0) break;
    }

    displayResults(candidates, MAX_CANDIDATES);

    return 0;
}

void displayCandidates(Candidate candidates[], int count) {
    printf("Candidates:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

void vote(Candidate candidates[], int count) {
    int vote;
    printf("Enter the number of the candidate you want to vote for: ");
    scanf("%d", &vote);
    if (vote > 0 && vote <= count) {
        candidates[vote - 1].votes++;
    } else {
        printf("Invalid vote. Try again.\n");
        vote(candidates, count);
    }
}

void displayResults(Candidate candidates[], int count) {
    printf("\nVoting Results:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    // Determine the winner
    int maxVotes = 0;
    int winnerIndex = -1;
    for (int i = 0; i < count; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winnerIndex = i;
        }
    }

    if (winnerIndex != -1) {
        printf("Winner: %s with %d votes\n", candidates[winnerIndex].name, candidates[winnerIndex].votes);
    } else {
        printf("No winner determined.\n");
    }
}
