#include <stdio.h>

int at[] = {0, 1, 2, 4, 5};
int bt[] = {3, 8, 6, 4, 2};
int ct[5];
int tat[5];
int wt[5];

void printProcessDetails()
{
    printf("Arrival Time:");
    for (int i = 0; i < 5; i++)
    {
        printf("\t %d", at[i]);
    }

    printf("\nBurst Time:");
    for (int i = 0; i < 5; i++)
    {
        printf("\t %d", bt[i]);
    }

    printf("\nCompleted Time:");
    for (int i = 0; i < 5; i++)
    {
        printf("\t %d", ct[i]);
    }

    printf("\nTAT :\t");
    for (int i = 0; i < 5; i++)
    {
        printf("\t %d", tat[i]);
    }

    printf("\nWaiting Time:");
    for (int i = 0; i < 5; i++)
    {
        printf("\t %d", wt[i]);
    }
}
double avg(int arr[])
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += arr[i];
    }

    return (float)sum / 5.0;
}

int main()
{

    // first come first server algorithm
    int second = 0;
    for (int i = 0; i < 5; i++)
    {
        ct[i] = second + bt[i];
        second += bt[i];

        tat[i] = ct[i] - at[i];
        wt[i] = ct[i] - bt[i];

        // printf("at: %d\t bt: %d\t ct: %d\t second: %d\t tat: %d\t wt: %d\n", at[i], bt[i], ct[i], second, tat[i], wt[i]);
    }

    printProcessDetails();

    double tatAverage = avg(tat);
    double wtAverage = avg(wt);

    printf("\n\nTurn Around Time Average: %.2f\n", tatAverage);
    printf("Waiting Time Average: %.2f\n", wtAverage);

    return 0;
}
