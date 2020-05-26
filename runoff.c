#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s \n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // Loop over all candidates
    for (int x = 0; x < candidate_count; x++)
    {
        if (strcmp(name, candidates[x].name) == 0) // Check that vote matches a candidate's name
        {
            preferences[voter][rank] = x; // Record the vote as the position of the candidate, i.e. 0, 1, 2,...
            return true;
        }
    }

    // In the case the vote does not match the candidates' names
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // Keep track of the voters' rankings
    int ranking;
    int can; // To easily point out the relevant candidate

    for (int v = 0; v < voter_count; v++) // Loop through the voters
    {
        ranking = 0;
        can = preferences[v][ranking]; // candidate's position

        while (candidates[can].eliminated == true) // In case the candidate has been eliminated
            {
                ranking++; // Note the voter's next ranking
                can = preferences[v][ranking]; // updating the candidate's position
            }

        candidates[can].votes++; // Add to the candidate's votes
    }

    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // The number of votes needed to win
    int to_win = round(1 + (voter_count/2));

    for (int y = 0; y < candidate_count; y++) // Loop through all candidates
    {
        if ((!candidates[y].eliminated) && (candidates[y].votes > to_win || candidates[y].votes == to_win))
        {
            printf("%s majority \n", candidates[y].name);
            return true;
        }
    }

    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // Keep track of the least votes
    int least_votes = candidates[0].votes;

    // Loop over all candidates
    for (int z = 1; z < candidate_count; z++)
    {
        if ((!candidates[z].eliminated) && (candidates[z].votes < least_votes)) // Check that the candidate has not been eliminated and that the votes are less than the variable
        {
            least_votes = candidates[z].votes;
        }
    }

    return least_votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // Check that the number of votes for each candidate is the same
    int counter = 0;
    int checker = 0;

    // Loop over all candidates
    for (int t = 0; t < candidate_count; t++)
    {
        if (!candidates[t].eliminated) // Check that the candidate has not been eliminated
        {
            if (candidates[t].votes == min)
            {
                counter++;
                checker++;
            }
            else
            {
                checker++;
            }
        }
    }

    if (counter == checker)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Eliminate the candidate (or candidiates) in last place
void eliminate(int min)
{
    // Loop over all candidates
    for (int e = 0; e < candidate_count; e++)
    {
        if ((!candidates[e].eliminated) && (candidates[e].votes == min))// Check that the candidate has not already been eliminated and has the minimum number of votes
        {
                candidates[e].eliminated = true; // Mark the candidate as eliminated
        }
    }

    return;
}
