#include <stdio.h>
#include <stdlib.h>


//? Number of days in each month
int month_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//!month_days[0]=0 to start indexing from 1


//? Names of all the months 
char *months[] = {
    "", //! to start indexing from 1
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
    "December"};
int main()
{
    while (1)
    {
        int year, month,day,days_in_Month,weekDay=0;
        printf("Enter Year: ");
        scanf("%d", &year);

        //?Condition check for leap year 
        if((year%4==0)&&(year%100!=0)||(year%400==0)){
            month_days[2]=29;
        }
        else{
            month_days[2]=28;
        }

        //?Printing the actual calender
        for (month = 1; month <= 12; month++)
        {
            days_in_Month=month_days[month];
            printf("\n\n-----------------%s-----------------", months[month]);
            printf("\n\n\tSun\tMon\tTue\twed\tthur\tfri\tsat\n");
            
            //?Printing dates
            //!Kuch galat hora hai printing me
            for(day=1;day<=days_in_Month;day++){
                printf("%d\t",day);
                if(++weekDay>6){
                    printf("\n");
                }
            }
        }
    }

    return 0;
}