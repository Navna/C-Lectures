#include <stdio.h>

typedef enum {
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
} WeekDay;

void printWeekDay(const WeekDay day) {
    switch (day) {
    case MONDAY:
        puts("Monday");
        break;
    case TUESDAY:
        puts("Tuesday");
        break;
    case WEDNESDAY:
        puts("Wednesday");
        break;
    case THURSDAY:
        puts("Thursday");
        break;
    case FRIDAY:
        puts("Friday");
        break;
    case SATURDAY:
        puts("Saturday");
        break;
    case SUNDAY:
        puts("Sunday");
        break;
    default:
        puts("UNKNOWN!");
    }
}

int main(void) {
    int n = 0;
    scanf("%d", &n);

    printWeekDay(n);
}
