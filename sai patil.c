#include <stdio.h>
#include <string.h>

#define NUM_PEOPLE 4
#define NUM_DAYS 5

int calculateExpenses(int *expenses, int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return *expenses + calculateExpenses(expenses + 1, n - 1); 

    }
}

int main()
{
    int expenses[NUM_PEOPLE][NUM_DAYS]; 
    char names[NUM_PEOPLE][51] = {"Swayamprabha", "Uday", "Shreya", "Sai"};
    char places[NUM_DAYS][100] = {
        "Shaniwar Wada", "Phoenix Mall", "Sinhagad", "Shrimant Dagdusheth Halwai Ganpati Mandir", "Raja Dinkar Kelkar Museum" };

    int i, j;

    
    printf("Enter the daily expenses for each friend visiting different places:\n");
    for (i = 0; i < NUM_PEOPLE; i++)
    {
        printf("\nFriend %d (%s):\n", i + 1, names[i]);
        for (j = 0; j < NUM_DAYS; j++)
        {
            printf("Expenses on Day %d (Visiting %s): ", j + 1, places[j]);
            scanf("%d", &expenses[i][j]);
        }
    }

    
    printf("\n--- Trip Expense Summary ---\n");
    printf("=========================================\n");
    printf("| %-15s | %-15s |\n", "Name", "Total Expense");
    printf("=========================================\n");

    int grandTotal = 0;
    for (i = 0; i < NUM_PEOPLE; i++)
    {
        int totalExpense = calculateExpenses(expenses[i], NUM_DAYS); 
        printf("| %-15s | %-15d |\n", names[i], totalExpense);
        grandTotal += totalExpense;
    }
    printf("=========================================\n");
    printf("\nGrand Total Expenses: %d\n", grandTotal);
    printf("=========================================\n");
    printf("Each person should contribute: %d\n", grandTotal / NUM_PEOPLE);
    printf("=========================================\n");

    return 0;
}