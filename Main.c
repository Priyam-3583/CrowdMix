#include <stdio.h>

struct Song
{
    char title[50];
    int bpm;
    int votes;
};

int main()
{
    /* built-in song library (votes start at 0) */
    struct Song s[6] = {
        {"Levels", 126, 0},
        {"Titanium", 126, 0},
        {"Animals", 128, 0},
        {"WakeMeUp", 124, 0},
        {"Closer", 95, 0},
        {"Faded", 90, 0}
    };
    struct Song temp;
    int n = 6, m = 0, i, j, gap, diff, ok, c, total = 0;

    /* title banner */
    printf("=====================================\n");
    printf("   CROWDMIX - Crowd Voted DJ Planner\n");
    printf("=====================================\n\n");

    /* show the song library */
    printf("Song Library:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d. %s\n", i + 1, s[i].title);
    }

    /* ask votes for each song by name (only valid numbers accepted) */
    printf("\nEnter votes:\n");
    for (i = 0; i < n; i++)
    {
        do
        {
            printf("Votes for %s: ", s[i].title);
            ok = scanf("%d", &s[i].votes);

            if (ok == EOF)
            {
                printf("\nInput ended. Exiting.\n");
                return 0;
            }

            if (ok == 0)
            {
                printf("Please enter a number only.\n");
                /* throw away the wrong input */
                while ((c = getchar()) != '\n' && c != EOF)
                {
                }
            }
            else if (s[i].votes < 0)
            {
                printf("Votes cannot be negative.\n");
            }
        } while (ok == 0 || s[i].votes < 0);

        total = total + s[i].votes;
    }
    printf("\n");

    /* sort: most votes first */
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (s[j].votes < s[j + 1].votes)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    /* count songs that got votes (they are at the top after sorting) */
    for (i = 0; i < n; i++)
    {
        if (s[i].votes > 0)
        {
            m++;
        }
    }

    /* zero votes: show total and exit */
    if (m == 0)
    {
        printf("Total Votes: %d\n", total);
        printf("No votes received. No set to build.\n");
        return 0;
    }

    /* final set list as a table with vote percentage */
    printf("========== FINAL SET LIST ==========\n");
    printf("%-6s%-12s%-6s%-8s%s\n", "Rank", "Song", "BPM", "Votes", "Share");
    printf("------------------------------------\n");
    for (i = 0; i < m; i++)
    {
        printf("%-6d%-12s%-6d%-8d%.1f%%\n", i + 1, s[i].title, s[i].bpm, s[i].votes, s[i].votes * 100.0 / total);
    }
    printf("------------------------------------\n");

    /* crowd favourite (shows all songs if there is a tie) */
    printf("\nCrowd Favourite: ");
    for (i = 0; i < m && s[i].votes == s[0].votes; i++)
    {
        if (i > 0)
        {
            printf(", ");
        }
        printf("%s", s[i].title);
    }
    if (i > 1)
    {
        printf(" (%d votes each)\n", s[0].votes);
    }
    else
    {
        printf(" (%d votes)\n", s[0].votes);
    }
    printf("Total Votes: %d\n", total);

    /* unique feature: BPM mix check with tempo direction */
    printf("\n============= MIX CHECK ============\n");
    if (m == 1)
    {
        printf("Only one song in the set. No mixing needed.\n");
    }

    for (i = 0; i < m - 1; i++)
    {
        diff = s[i + 1].bpm - s[i].bpm;
        gap = diff;
        if (gap < 0)
        {
            gap = -gap;
        }

        printf("%-10s -> %-10s : ", s[i].title, s[i + 1].title);

        if (gap > 8)
        {
            printf("HARD TO MIX");
        }
        else
        {
            printf("Smooth");
        }

        if (diff > 0)
        {
            printf(" (Speed UP)\n");
        }
        else if (diff < 0)
        {
            printf(" (Slow DOWN)\n");
        }
        else
        {
            printf(" (Same tempo)\n");
        }
    }

printf("\n=====================================\n");
printf(" Thank you for using CROWDMIX!\n");
printf("=====================================\n");

    return 0;
}
