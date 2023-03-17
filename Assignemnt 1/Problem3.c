//Author: Kai Ibarrondo
//RUID: kai51
//Problem 3, Assignment 1

#include <stdio.h>

// function to determine manager's pay rate.
double manager(void){
    double pay_rate;
    //query user for mangers pay rate info
    printf("Please enter manager's pay rate: ");
    scanf("%lf", &pay_rate);
    return pay_rate;
}
// function to determine hourly worker's pay rate.
double hourly_workers(void){
    double pay_rate;
    int hours_worked;
    //query user for information necessary to calculate the hourly workers pay rate.
    printf("Please enter hourly workers pay rate: ");
    scanf("%lf", &pay_rate);
    printf("Please enter amount of hours worked: ");
    scanf("%d", &hours_worked);

    //use and if else statement to calculate overtime.
    if(hours_worked > 40){
        double overtime_pay = 1.5 * pay_rate * (hours_worked - 40);
        return (pay_rate * 40) + overtime_pay;
    }
    else{
        return pay_rate * hours_worked;
    }
}
// function to determine commission worker's pay rate.
double commission(void){
    double gross_sales;
    //query user for information to calculate pay rate.
    printf("Please enter commission employee's gross weekly sales: ");
    scanf("%lf", &gross_sales);
    //return the commission workers sales
    return 350 + (.065 * gross_sales);
}
// function to determine pieceworker's pay rate.
double pieceworkers(void){
    int num_items;
    double pay_rate;
    //query user for information to calculate pay rate.
    printf("Please enter the number of items completed: ");
    scanf("%d", &num_items);
    printf("Please enter employee's per item pay rate: ");
    scanf("%lf", &pay_rate);
    return num_items * pay_rate;
}

int main(){
    //initialize variables
    int employee_type;
    //query user for employee code 
    printf("Please enter employee code (-1 to end): ");
    scanf("%d", &employee_type);
    while(employee_type != -1){
        //use switch to test which pay code was entered. 
        //And then output the appropriate sentence and pay.
        switch(employee_type){
            case 1:
                printf("The manager's weekly pay is %.2lf\n\n", manager());
                break;
            case 2:
                printf("The hourly workers employee's weekly pay is %.2lf\n\n", hourly_workers());
                break;
            case 3:
                printf("The commission employee's pay is %.2lf\n\n", commission());
                break;
            case 4:
                printf("The pieceworker's weekly pay is %.2lf\n\n", pieceworkers());
                break;
            default:
                printf("Invalid employee code!\n\n");
                break;
        }
        //query user again to keep the loop going until -1 is entered. 
        printf("Please enter employee code (-1 to end): ");
        scanf("%d", &employee_type);
    }
    return 0;
}
