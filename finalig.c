#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int day(int year,int month);
int start_month(int month,int year);
void design(int start_day,int month,int end,int year);

int month_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Names of all the months
char *months[] = {
    "",
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

int main()
{
    while (1)
    {
        int year, start_month, end_month;
        printf("Enter Year: ");
        scanf("%d", &year);
        if (year ==0){
            exit(0);
        }

        printf("Enter start month number (1-12): ");
        scanf("%d", &start_month);

        printf("Enter end month number (1-12): ");
        scanf("%d", &end_month);
        
        if((start_month<1)){
        	start_month=1;
		}
		if(end_month>12){
			end_month=12;
		}

        design(day(year, start_month), start_month, end_month, year);
    }

    return 0;
}

int day(int year, int month)
{
    int leap = (year - 1) / 4;
    int normal = (year - 1) - leap;
    int days = leap * 2 + normal;
    return (days + start_month(month, year)) % 7;
}

int start_month(int month, int year)
{
    int total = 0;
    int i = 0;
    for (i = 1; i < month; i++)
    {
        if (i == 2)
        {
            if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
            {
                total = total + 29;
            }
            else
            {
                total = total + month_days[i];
            }
        }
        else
        {
            total += month_days[i];
        }
    }
    return total;
} 


void design(int start_day, int start_month, int end_month, int year)
{
    int i = 0;
    char *day[] = {"S", "M", "T", "W", "T", "F", "S"};

    while (start_month <= end_month)
    {
        i = 0;
        int end_day = month_days[start_month];
        // checking leap year
        if (start_month == 2)
        {
            if (year % 4 == 0)
            {
                if (year % 100 == 0)
                {
                    if (year % 400 == 0)
                    {
                        end_day++;
                    }
                }
                else
                {
                    end_day++;
                }
            }
        }

        printf("%s %d\n", months[start_month], year);
        printf("--------------------\n");

        // Print the days of the week
        for (i = 0; i < 7; i++)
        {
            printf("%s   ", day[i]);
        }
        printf("\n");

        // Print the calendar for the month
        int day_num = 1;
        for (i = 0; i < 6; i++)
        {
            int j = 0;
            for (; j < 7; j++)
            {
                if (i == 0 && j < start_day)
                {
                    printf("    ");
                }
                else if (day_num <= end_day)
                {
                    if (day_num < 10)
                    {
                        printf(" %d  ", day_num);
                    }
                    else
                    {
                        printf("%d  ", day_num);
                    }
                    day_num++;
                }
                else
                {
                    printf("    ");
                }
            }
            printf("\n");
            if (day_num > end_day)
            {
                break;
            }
        }

        printf("\n");

        start_day = (start_day + end_day) % 7;
        start_month++;
    }
}

       
