#include <cs50.h>
#include <stdio.h>

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[3];
int candidate_count;

// Print the winner of the election, if there is one
bool print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        // if vote percentage of current candidate is majority (>50%)
        if ((double)candidates[i].votes > ((double)candidate_count / 2.0))
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

int main(void)
{
    candidate_count = 3;
    candidates[0].name = "Alice";
    candidates[1].name = "Bob";
    candidates[2].name = "Charlie";
    candidates[0].votes = 1;
    candidates[1].votes = 1;
    candidates[2].votes = 1;
    if (print_winner())
        printf("Success!\n");
    return 0;
}
