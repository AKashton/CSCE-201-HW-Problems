//////////////////////////////////////////////////////
// CSCE A201
// Ashton Curry
// 1/28/22
// Purpose: Print out a dinner menu
//////////////////////////////////////////////////////
#include "stdio.h"

const char SALAD[20] = "Green Salad";
const char MEAT[25] = "Chicken Marsala";
const char VEGGIE[50] = "Carrots with lemon butter";
const char STARCH[20] = "Mashed potatoes";
const char DESSERT1[20] = "Cheesecake";
const char DESSERT2[20] = "Tiramisu";
int numdesserts = 2;

int main()
{
        printf("First course: %s\n", SALAD);
        printf("Main course: %s with %s and %s\n", MEAT, VEGGIE, STARCH);
        printf("There are %d desserts:\n", numdesserts);
        printf("Dessert 1: %s\nDessert 2: %s",DESSERT1, DESSERT2);
        return 0;
}