#include <stdio.h>
#include <string.h>

struct Voter {
    char name[50];
    char nid[30];
    char location[50];
    int vote;
};

int main() {
    struct Voter voters[100];
    int totalVoters = 0;

    // vote count variables
    int vote_bnp = 0;
    int vote_ncp = 0;
    int vote_ji = 0;

    int choice;
    int i;
    int isDuplicate; // Flag to check if user exists

    while(1) {
        printf("\n=========== DIGITAL VOTING SYSTEM ===========\n");

        printf("\n1. Add New Voter & Vote");
        printf("\n2. Count Result");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            // ---- First Page ----
            printf("\n---- First Page: Voter Information ----\n");

            printf("Enter Name: ");
            scanf("%s", voters[totalVoters].name);

            printf("Enter National ID: ");
            scanf("%s", voters[totalVoters].nid);

            // ==========================================
            // START: DUPLICATE CHECK CODE
            // ==========================================
            isDuplicate = 0; // Reset flag

            // Loop through all existing voters to check NID
            for(i = 0; i < totalVoters; i++) {
                if(strcmp(voters[totalVoters].nid, voters[i].nid) == 0) {
                    isDuplicate = 1; // Found a match!
                    break;
                }
            }

            if(isDuplicate == 1) {
                printf("\ntry agin .user scam detected .\n");
                continue; // Skips the rest of the code and goes back to the menu
            }
            // ==========================================
            // END: DUPLICATE CHECK CODE
            // ==========================================

            printf("Enter Location: ");
            scanf("%s", voters[totalVoters].location);

            // ---- Second Page ----
            printf("\n---- Second Page: Select Candidate ----\n");
            printf("1. BNP (🌽 Ear of Corn)\n");
            printf("2. NCP (🌼 Water Lily)\n");
            printf("3. JI  (⚖️ Balance Scale)\n");

            printf("Select your candidate (1/2/3): ");
            scanf("%d", &voters[totalVoters].vote);

            // save vote
            if (voters[totalVoters].vote == 1) vote_bnp++;
            else if (voters[totalVoters].vote == 2) vote_ncp++;
            else if (voters[totalVoters].vote == 3) vote_ji++;
            else {
                printf("Invalid Vote!\n");
                // If vote is invalid, we shouldn't increment totalVoters or save details
                continue;
            }

            totalVoters++; // Only increment if vote was successful

            printf("\nYour vote has been submitted successfully!\n");
        }

        else if(choice == 2) {
            printf("\n=========== VOTING RESULT ===========\n");
            printf("\nTotal Voters: %d\n", totalVoters);

            printf("BNP (🌽): %d votes\n", vote_bnp);
            printf("NCP (🌼): %d votes\n", vote_ncp);
            printf("JI  (⚖️): %d votes\n", vote_ji);

            // find winner
            if (vote_bnp > vote_ncp && vote_bnp > vote_ji)
                printf("\nWinner: BNP (🌽 Ear of Corn)\n");
            else if (vote_ncp > vote_bnp && vote_ncp > vote_ji)
                printf("\nWinner: NCP (🌼 Water Lily)\n");
            else if (vote_ji > vote_bnp && vote_ji > vote_ncp)
                printf("\nWinner: JI (⚖️ Balance Scale)\n");
            else
                printf("\nResult: Tie Between Candidates!\n");

            break;
        }

        else {
            printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
