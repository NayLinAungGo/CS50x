#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // rank is current from Rank 1:
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        // ranks[i] over ranks[j...n] where j = (i + 1)
        for (int j = i + 1; j < candidate_count; j++)
        {
            //printf("+1 to candidate %i over candidate %i\n", ranks[i], ranks[j]);
            preferences[ranks[i]][ranks[j]]++;
            //printf("It is now: %i\n", preferences[ranks[i]][ranks[j]]);
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // Check through each unique pair of candidates
    for (int i = 0; i < candidate_count; i++)
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pair_count++;
                pairs[pair_count - 1].winner = i;
                pairs[pair_count - 1].loser = j;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pair_count++;
                pairs[pair_count - 1].winner = j;
                pairs[pair_count - 1].loser = i;
            }
        }
    return;
}

// Print pairs with names and preferences
void print_pairs(void)
{
    printf("\n");
    for (int i = 0; i < pair_count; i++)
    {
        printf("Pair %i:", i);
        printf(" [%i-%i] ", pairs[i].winner, pairs[i].loser);
        printf("%s beats %s ", candidates[pairs[i].winner], candidates[pairs[i].loser]);
        printf("%i to %i\n", preferences[pairs[i].winner][pairs[i].loser], preferences[pairs[i].loser][pairs[i].winner]);
    }
    printf("\n");
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // Using bubble sort
    bool swapped;
    for (int i = 0; i < pair_count - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < pair_count - i - 1; j++)
        {
            if (preferences[pairs[j].winner][pairs[j].loser] <
                preferences[pairs[j + 1].winner][pairs[j + 1].loser])
            {
                pair temp_pair = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = temp_pair;
                printf("swapped pairs[%i] with pairs[%i]\n", j, j + 1);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    return;
}

// Detect cycles in locked pairs using depth-first search
bool creates_cycle(int loser, int winner, bool checked[])
{
    if (winner == loser) return true; // Cycle found

    checked[loser] = true; // Mark new candidate as checked

    // Recur for all locked[][] so far
    for (int i = 0; i < candidate_count; i++)
        if (locked[loser][i] && !checked[i])
           if (creates_cycle(i, winner, checked))
               return true;
    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    //print_pairs(); // for debugging

    // Repeat for every pairs
    for (int i = 0; i < pair_count; i++)
    {
        bool checked[candidate_count];
        for (int j = 0; j < candidate_count; j++)
            checked[j] = false;

        // Add locked if it doesn't create a cycle
        locked[pairs[i].winner][pairs[i].loser] = (!creates_cycle(pairs[i].loser, pairs[i].winner, checked));
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // Check each candidate to make sure they beat everyone
    for (int i = 0; i < candidate_count; i++)
    {
        int lost_count = 0;

        for (int j = 0; j < candidate_count; j++)
            if (locked[j][i] && i != j)
                lost_count++;

        if (lost_count == 0)
            printf("%s\n", candidates[i]);
    }
    return;
}
