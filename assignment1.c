#include<stdio.h>

int main() {
    int n,i,j;
    int marks[50][5];
    int total[50];
    float percentage[50];
    char name[50][30];
    char grade[50];
    printf("Enter number of students: ");
    scanf("%d", &n);

    for(i=0;i<n;i++) {
        printf("\nEnter name of student %d: ", i + 1);
        scanf("%s",name[i]);

        total[i]=0;

        printf("Enter marks of 5 subjects: ");
        for (j=0;j<5;j++) {
            scanf("%d",&marks[i][j]);
            total[i]+=marks[i][j];
        }

        percentage[i]=total[i]/ 5.0;

        if (percentage[i]>= 90){
            grade[i] = 'A';
        }
        else if (percentage[i] >= 75){
            grade[i] = 'B';
        }
        else if (percentage[i] >= 60){
            grade[i] = 'C';
        }
        else if (percentage[i] >= 50){
            grade[i] = 'D';
        }
        else{
            grade[i] = 'F';
        }
    }

    printf("\n----- STUDENT RESULTS -----\n");

    int highest= 0;

    for (i = 0;i<n;i++) {
        printf("\nName       : %s", name[i]);
        printf("\nTotal      : %d/500", total[i]);
        printf("\nPercentage : %.2f%%", percentage[i]);
        printf("\nGrade      : %c\n", grade[i]);

        if (percentage[i]>percentage[highest])
            highest=i;
    }

    printf("\nHighest Percentage:");
    printf("\nName       :%s",name[highest]);
    printf("\nPercentage :%.2f%%\n",percentage[highest]);

    return 0;
}