// 27 aug question
# include <stdio.h>
# include <stdlib.h>
# define N 50
# define R 12

struct student
{
    char name[N];
    char regno[R];
    float marks;
};

int main()
{
    int i, n, status, option;
    char ch;
    struct student stu[N];

    printf("Enter the number of students: ");
    scanf("%d", &n);
    fflush(stdin);

    for(i = 0; i < n; i++)
    {
        printf("\nStudent %d\n", i + 1);

        printf("Enter the name: ");
        fgets(stu[i].name, N - 1, stdin);
        fflush(stdin);

        printf("Enter the registration number: ");
        fgets(stu[i].regno, R - 1, stdin);
        fflush(stdin);

        printf("Enter the marks: ");
        scanf("%f", &stu[i].marks);
        fflush(stdin);
    }


    printf("\nChoose an option:\n1. Insert a record\n2. Delete a record\n3. Sort the records\n4. Display the records\n\n");
        
    do {
        printf("Enter the option: ");
        status = scanf("%d", &option);
        fflush(stdin);

        while (status == 0 || option < 1 || option > 0)
        {
            printf("Enter the option: ");
            status = scanf("%d", &option);
            fflush(stdin);
        }

        switch (option)
        {
        case 1:

            break;

        case 2:

            break;

        case 3:
            break;

        case 4:
            break;
        
        default:
            break;
        }


        printf("Do you want to continue? [y/n]: ");
        scanf("%c", &ch);

    }while(ch != 'n' || ch != 'N');
        

    

    return 0;
}

struct student sort(struct student stu)
{
    
}