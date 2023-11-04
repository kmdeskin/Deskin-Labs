//karadeskin
#include <stdio.h>
#include <string.h>
struct monthlySales {
    char *month;
    double sales;
};
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
}