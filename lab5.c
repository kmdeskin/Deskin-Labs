//karadeskin
#include <stdio.h>
#include <string.h>
struct monthlySales {
    char *month;
    double sales;
};
typedef struct {
    int td2pt;
    int tdfg;
    int td;
    int fg;
    int safety;
} scoring;
//I created a data structure, scoring, that stores different point values for scoring in a football game 
//theres touchdown conversion, touchdown field goal , touchdown, fieldgoal, and safety
void calculateCombinations(int score, scoring combinations[], int *numCombinations) {
    *numCombinations = 0;
    printf("Possible combinations of scoring plays:\n");
    for (int td2pt = 0; td2pt * 8 <= score; td2pt++) { 
        for (int tdfg = 0; tdfg * 7 + td2pt * 8 <= score; tdfg++) {
            for (int td = 0; td * 6 + tdfg * 7 + td2pt * 8 <= score; td++) {
                for (int fg = 0; fg * 3 + td * 6 + tdfg * 7 + td2pt * 8 <= score; fg++) {
                    int remaining = score - (fg * 3 + td * 6 + tdfg * 7 + td2pt * 8);
                    if (remaining % 2 == 0) {
                        int safety = remaining / 2;
                        combinations[*numCombinations].td2pt = td2pt;
                        combinations[*numCombinations].tdfg = tdfg;
                        combinations[*numCombinations].td = td;
                        combinations[*numCombinations].fg = fg;
                        combinations[*numCombinations].safety = safety;
                        (*numCombinations)++;
                    }
                }
            }
        }
    }
}
//then there is also a function, calculateCombinations, that takes 3 params; score, combinations[], and #numCombinations
//score is an int that represents the score of the game 
//combinations[] is an array that stores the score combinations 
//*numCombinations is a pointer to the number of combos found 
//then my function uses for loops to find the different combinations found 
//inside the nested loops, the remaining points needed to reach the score by subracting points earned from touchdowns, conversions, and field goals are calculated
//with the number of combinations initialized to 0, the first for loop iterates through the number of 2 point conversions + touchdown
//the second for loop iterates through the number of field goals + touchdown 
//the 3rd one iterates through all of the times there is a touchdown + fieldgoal points + conversion points
//this for loop iterates through the times when there is a standalone fielgoal 
//the last one calculates the remaining points needed to reach total score 
//then the last for loop of the function checks if the remaining score is even to distribute the remaining points to savety
//savety is 2 points, so safety/2 works 
//then the combination is stored in arrray 
//at the very end, the number of combinations has to be incremented to keep track of combos 
int main() {
    printf("\nMonthly sales report for 2022:\n");
    double sales[] = {
        23458.01,
        40112.00,
        56011.85,
        37820.88,
        37904.67,
        60200.22,
        72400.31,
        56210.89,
        67230.84,
        68233.12,
        80950.34,
        95225.22,
    };
    char *months[] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    int numberofMonths = sizeof(sales) / sizeof(sales[0]);
    double movingAverage = 0.0;
    double minimumSales = sales[0];
    double maximumSales = sales[0];
    double totalSales = 0.0;
    printf("Month\t\tSales\n");
    for (int i = 0; i < numberofMonths; i++) {
        double currentSales = sales[i];
        printf("%s\t$%.2f\n", months[i], currentSales);
        if (currentSales < minimumSales) {
            minimumSales = currentSales;
        }
        if (currentSales > maximumSales) {
            maximumSales = currentSales;
        }
        totalSales += currentSales;
    }
    double averageSales = totalSales / numberofMonths;
    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", minimumSales, months[0]);
    printf("Maximum sales: $%.2f (%s)\n", maximumSales, months[numberofMonths - 1]);
    printf("Average sales: $%.2f\n", averageSales);
    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 0; i <= numberofMonths - 6; i++) {
        for (int j = 0; j < 6; j++) {
            movingAverage += sales[i + j];
        }
        movingAverage /= 6;
        printf("%s - %s $%.2f\n", months[i], months[i + 5], movingAverage);
        movingAverage = 0.0;
    }
    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month\tSales\n");
    struct monthlySales monthlyData[numberofMonths];
    for (int i = 0; i < numberofMonths; i++) {
        monthlyData[i].month = months[i];
        monthlyData[i].sales = sales[i];
    }
    for (int i = 0; i < numberofMonths - 1; i++) {
        for (int j = i + 1; j < numberofMonths; j++) {
            if (monthlyData[i].sales < monthlyData[j].sales) {
                struct monthlySales temp = monthlyData[i];
                monthlyData[i] = monthlyData[j];
                monthlyData[j] = temp;
            }
        }
    }
    for (int i = 0; i < numberofMonths; i++) {
        printf("%s\t$%.2f\n", monthlyData[i].month, monthlyData[i].sales);
    }
    //this is the end of the main logic for the first problem
    //the first problem is a monthly sales report 
    //an array sales holds the monthly sales data as double values
    //an array of strings months contains the names of the months
    //the number of months is calculated using sizeof(sales) / sizeof(sales[0])
    //I printed the sales report first 
    //I iterated through the number of months and stored each sales value[i] to the current value 
    //then I printed the month with the current sales value to 2 dec places and updated the total, max, and min status
    //now i calculate the average sales dividing total sales by number of months 
    //now I am on the sales summary 
    //i printed the min w/month
    //i printed the max/w month 
    //then the average 
    //now i am on the 6th month moving average report  
    //the for loop iterates through every 6 group of months
    //the inner loop sums each 6-month period of data 
    //now printing report values from highest to lowest
    //used the structure, monthlySales, with 2 member variables, month & sales. holds information abt the sales
    //the first for loop, monthlyData[i].month = months[i]; assigns the month name from the months array to the month member of the monthlyData structure for each element
    //does same thing for sales
    //next sort the data to show the highest sales months first by swapping months in the array 
    printf("\n");
    while (1) { 
        int score;
        scoring combinations[1000];
        int numCombinations = 0;
        printf("\n");
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        if (score <= 1) {
            break;
        }
        calculateCombinations(score, combinations, &numCombinations);
        for (int i = 0; i < numCombinations; i++) {
            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                combinations[i].td2pt, combinations[i].tdfg, combinations[i].td, combinations[i].fg, combinations[i].safety);
        }
    }
    return 0;
    //now the second problem's logic is implemented 
    //I used a while to keep the menu running until the user terminates the code 
    //created a score int to store user input 
    //created size of combos array
    //enter 0 or 1 to stop, but if the score is greater than 1, then calculate score combos by passing values in the function
    //prints out all the combos of plays 
}

