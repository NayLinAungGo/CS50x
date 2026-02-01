#include <cs50.h>
#include <stdio.h>

typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

int main (void)
{
    int candidate_count = 3;
    candidate candidates[3];
    
    candidate_count = 3;
    candidates[0].name = "Alice";
    candidates[1].name = "Bob";
    candidates[2].name = "Charlie";
    candidates[0].votes = 2;
    candidates[1].votes = 6;
    candidates[2].votes = 2;
    candidates[0].eliminated = false;
    candidates[1].eliminated = true;
    candidates[2].eliminated = false;
    int min = 2;

    for (int i = 0, n = candidate_count; i < n; i++)
    {
        if (candidates[i].votes == min && !candidates[i].eliminated)
        {
            candidates[i].eliminated = true;
            printf("Candidate %s eliminated\n", candidates[i].name);
            candidate_count--;
        }
    }
    return 0;
}
