#include <stdio.h>
struct student
{
    char name[50];
    int rollno;
    int grade;
};
void Read(struct student students[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("student %d\n",i+1);
        printf("Enter name:");
        scanf("%s",&students[i].name);
        printf("Enter rollno:");
        scanf("%d",&students[i].rollno);
        printf("Enter grade:");
        scanf("%d",&students[i].grade);
    }
}
void Display(struct student students[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Details of student %d\n",i+1);
        printf("Name:%s\n",students[i].name);
        printf("Rollno:%d\n",students[i].rollno);
        printf("Grade:%d\n",students[i].grade);
    }
}
void Sort(struct student students[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++) {
        for(j=0;j<n-i-1;j++) {
            if(students[j].rollno>students[j + 1].rollno) {
                struct student temp=students[j];
                students[j]=students[j+1];
                students[j+1]=temp;}}}
}
int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d",&n);
    fflush(stdin);
    struct student students[n];
    Read(students,n);
    Sort(students,n);
    Display(students,n);
}
