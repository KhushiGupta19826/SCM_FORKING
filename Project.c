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
        int year;
        printf("Enter Year: ");
        scanf("%d", &year);
        int tem = day(year,2);
   
        desgin(tem , 2,4,year);
      
    }

    return 0;
}
int day(int year , int month){
	int leap  = (year-1)/4;
	int normal = (year-1) - leap;
	int days = leap*2 + normal;
	return (days+start_month(month))%7;
}
int start_month(int month , int year){
	int total = 0;
	int i =0 ; 
	for(i =1 ; i<month ; i++){
		if(month == 1){
			 if(year %4 ==0 ){
			 	if(year%100 == 0 ){
			 		if(year%400 == 0 ){
			 			total =total+month_days[i]+1;
					 }else{
					 	total =total+month_days[i];
					 }
				 }else{
				 	total =total+month_days[i];
				 }
			 }else{
			 	total =total+month_days[i];
			 }
		}else{
				total+=month_days[i];
		}
	
	}
	return total;
}
void desgin(int start_day , int month , int end , int year){
	int i =0 ; 
	char *day[] = {"S", "M","T","W","T","F","s"};

	
	int tem = start_day;
	while(end>=month){
		i  =0;
		tem = start_day;
	for(i =  0 ; i <7 ; i++){
		printf("%s  " , day[i] );
	}
		i = 1;
        	int end_day = month_days[month];
        	// checking leap year
        	if(month == 2){
        		if(year%4 == 0 ){
        			if(year%100 == 0 ){
        				if(year%400 == 0 ){
        					end_day++;
						}
					}else{
						end_day++;
					}
				}
			}
        	printf("\n");
		while(i<=end_day){
		int j = 0;
		
		for(; j<7 ; j++){
			
			if(start_day==0){
			
			    if(i<10){
			    		printf("%d  " , i);
				}else{
						printf("%d " , i);
				}
			   
						i++;
				if(i >end_day){
			    	
			    	break;
				}
						
			}else{
				
				start_day--;
				printf("   ");
			}
	      
		}
			printf("\n");
	}

		start_day = (tem+end_day)%7;
			printf("\n");
		
		month++;;
	
	}
	

		
		
	    
		
	}
	

