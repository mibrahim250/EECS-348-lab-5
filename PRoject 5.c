FILE *inFile;
#define MONTHS 12

float avrcalc(float sales[]) {
    float total = 0;
    for (int i = 0; i < MONTHS; i++) {
        total += sales[i];
    }
    return total / MONTHS;
}

int findMinMonth(float sales[]) {
    float minSale = sales[0];
    int minIndex = 0;
    for (int i = 1; i < MONTHS; i++) {
        if (sales[i] < minSale) {
            minSale = sales[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int findMaxMonth(float sales[]) {
    float maxSale = sales[0];
    int maxIndex = 0;
    for (int i = 1; i < MONTHS; i++) {
        if (sales[i] > maxSale) {
            maxSale = sales[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main(){

    float sales[MONTHS];  
    float average;  
    int minIndex;
    int maxIndex;

    
    inFile = fopen("data.txt", "r")

    for (int i = 0; i < MONTHS; i++) 
    {
        fscanf(inFile, "%f", &sales[i]);
    }

    fclose(inFile);

    average = avrcalc(sales);
    minIndex = findMinMonth(sales);
    maxIndex = findMaxMonth(sales);
    
    printf("Monthly sales report for 2022:\n");
    char *months[] = {"January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"};
    for (int i = 0; i < MONTHS; i++) {
        printf("%s $%.2f\n", months[i], sales[i]);
    }
    
    
    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", sales[minIndex], months[minIndex]);
    printf("Maximum sales: $%.2f (%s)\n", sales[maxIndex], months[maxIndex]);
    printf("Average sales: $%.2f\n", average);

    return 0;
}