#include<stdio.h>

void delay();
void alarm(int entered_sec,int entered_hr,int entered_min);

int entered_sec,entered_hr,entered_min;
int seconds,hours,minutes;

int main(){
    


    // User input for setting time
    printf("Set your time: ");
    scanf("%d %d %d",&hours,&minutes,&seconds);

    // Set an alarm
    printf("Set an alarm: ");
    scanf("%d %d %d",&entered_hr,&entered_min,&entered_sec);

    while(1){
        printf("%02d:%02d:%02d\n",hours,minutes,seconds);

        delay();

                if(seconds == 59)
                {
                    seconds = 0;
                    minutes++;
                }else{
                    seconds++;
                }
                // printf("%02d:%02d:%02d\n",hours,minutes,seconds);

                if(minutes == 60){

                    minutes = 0;
                    hours++;
                }

                if(hours == 24){

                    hours = 0;
                }

                alarm(entered_sec,entered_hr,entered_min);
    }

}

void delay()
{
    for(long long i=0;i<1200000000;i++){

    }
}

void alarm(int entered_sec,int entered_hr,int entered_min){
    if(hours == entered_hr && minutes == entered_min && seconds == entered_sec){
        printf("Alert! Alarm activated");
    }
}