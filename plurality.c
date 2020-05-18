#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
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
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // Loop over all candidates
    for (int x = 0; x < candidate_count; x++)
    {
        if (strcmp(name, candidates[x].name) == 0) // Check that vote matches a candidate's name
        {
            candidates[x].votes++; // Update vote count
            return true;
        }
    }

    // In the case the vote does not match the candidates' names
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Keep track of the most votes
    int most_votes = 0;

    // Loop over all candidates
    for (int y = 0; y < candidate_count; y++)
    {
        if (candidates[y].votes > most_votes) //check for the largest number of votes
        {
            most_votes = candidates[y].votes;
        }
    }

    //Loop over all candidates
    for (int z = 0; z < candidate_count; z++)
    {
        if(candidates[z].votes == most_votes)
        {
            printf("%s\n", candidates[z].name);
        }
    }

    return;
}

