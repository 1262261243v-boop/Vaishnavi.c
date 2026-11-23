#include <stdio.h>


int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


int getStartDayOfYear(int year) {
    int y = year - 1;
    return (year + y / 4 - y / 100 + y / 400) % 7;
}

int main() {
    int year;
    const char *months[12] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };
    int daysInMonth[12] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    printf("Enter year: ");
    if (scanf("%d", &year) != 1 || year < 1) {
        printf("Please enter a valid positive year.\n");
        return 1;
    }

   
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    int currentDay = getStartDayOfYear(year);

    for (int m = 0; m < 12; m++) {
        printf("\n------------ %s %d ------------\n", months[m], year);
        printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

     
        for (int space = 0; space < currentDay; space++) {
            printf("     ");
        }

        
        for (int day = 1; day <= daysInMonth[m]; day++) {
            printf("%3d  ", day);
            currentDay = (currentDay + 1) % 7;

            if (currentDay == 0) {
                printf("\n");
            }
        }

        
        if (currentDay != 0) {
            printf("\n");
        }
    }

    return 0;
}
