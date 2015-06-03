#include <stdio.h>
#include <stdlib.h>
int getMinSteps(int);
int min (int,int);
int main()
{
    int number_to_one=0;
    int steps_required = 0;
    printf("Enter the Number you feel to be analyzed\n");
    scanf("%d",&number_to_one);
    steps_required = getMinSteps(number_to_one);
    printf("The Minimum number of steps required are %d", steps_required);
    return 0;
}

int getMinSteps ( int number_to_one )
{
int saved_results[number_to_one + 1];
int result_counter = 2;
saved_results[1] = 0;
while(result_counter <= number_to_one)
{
saved_results[result_counter] = 1 + saved_results[(result_counter-1)];
if(result_counter%2==0) saved_results[result_counter] = min( saved_results[result_counter] , 1+ saved_results[result_counter/2] );
if(result_counter%3==0) saved_results[result_counter] = min( saved_results[result_counter] , 1+ saved_results[result_counter/3] );
result_counter++;
}
return saved_results[number_to_one];
}

int min(int integer1, int integer2)
{
    int min = 0;
    if(integer1 != integer2)
    {
        if(integer1 > integer2)
        {
           min =  integer2;
        }
        else
            min = integer1;
    }
    else
    {
        min = integer1;
    }
    return min;
}
