#include <cs50.h>
#include <stdio.h>

typedef struct
{
    string name;
    int votes;
}
candidate;

candidate get_candidate(void);

int main(void)
{
    candidate alice;
    alice.name = "Alice";
    alice.votes = 5;

    printf("%s has %i votes.\n", alice.name, alice.votes);

    candidate new_candidate = get_candidate();
    printf("%s has %i votes.\n", new_candidate.name, new_candidate.votes);
    
    candidate candidates[3];
    for (int i = 0; i < 3; i++)
        candidates[i] = get_candidate();

    for (int i = 0; i < 3; i++)
        printf("Candidate %i is named %s and has %i votes.\n", i + 1, candidates[i].name, candidates[i].votes);

    return 0;
}

candidate get_candidate(void)
{
    //candidate new_candidate;
    //new_candidate.name = get_string("Name: ");
    //new_candidate.votes = get_float("Votes: ");
    //return new_candidate;

    // Turns out you can also do this
    //string name = get_string("Name: ");
    //int votes = get_float("Votes: ");
    //return (candidate){ name, votes };

    // Or even sillier
    return (candidate){ get_string("Name: "), get_float("Votes: ") };
}
