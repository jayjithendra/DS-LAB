#include <stdio.h>
struct time
{
    int hour;
    int min;
    int sec;
};
struct time Read()
{
    struct time a;
    printf("Hour:");
    scanf("%d",&a.hour);
    printf("Min:");
    scanf("%d",&a.min);
    printf("sec:");
    scanf("%d",&a.sec);
    return a;
}
void Display(struct time a)
{
    printf("%d:%d:%d\n",a.hour,a.min,a.sec);
}
struct time Add(struct time a,struct time b)
{
    struct time result;
    result.sec=a.sec+b.sec;
    result.min =a.min+b.min+result.sec/60;
    result.sec%= 60;
    result.hour=a.hour+b.hour+result.min/60;
    result.min%=60;
    return result;

}
struct time Diff(struct time a,struct time b)
{
    struct time result;
    int sec1 = a.sec+a.min*60+a.hour*3600;
    int sec2 = b.sec+b.min*60+b.hour*3600;
    int diffSec=sec1-sec2;
    result.sec=diffSec%60;
    diffSec/=60;
    result.min=diffSec%60;
    diffSec/=60;
    result.hour=diffSec;
    return result;
}
int main()
{
    struct time a,b,result1,result2;
    printf("Enter time 1:\n");
    a=Read();
    printf("Enter time 2:\n");
    b=Read();
    result1=Add(a,b);
    printf("Time1+Time2\n");
    Display(result1);
    result2=Diff(a,b);
    printf("Time1-Time2\n");
    Display(result2);

}

