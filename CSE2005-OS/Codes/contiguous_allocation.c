# include <stdio.h>
# include <string.h>
# define len 20
# define N 30

struct fileTable
{
    char name[len];
    int start;
    int no_of_blocks;
} file_table[N];

int main()
{
    int i, j, n;
    char s[len];

    printf("Enter no of files: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter file name %d: ", i + 1);
        scanf("%s", file_table[i].name);

        printf("Enter starting block of file %d: ", i + 1);
        scanf("%d", &file_table[i].start);

        printf("Enter no of blocks in file %d: ", i + 1);
        scanf("%d", &file_table[i].no_of_blocks);
    }

    printf("\nEnter the file name to be searched: ");
    scanf("%s", s);

    for (i = 0; i < n; i++)
    {
        if (strcmp(s, file_table[i].name) == 0)
            break;
    }
    
    if (i == n)
    {
        printf("\nFile Not Found");
    }
    else
    {
        printf("\nFILE NAME\t START BLOCK\t NO OF BLOCKS\t BLOCKS OCCUPIED\n");
        printf("\n  %s\t\t%d\t\t%d\t\t", file_table[i].name, file_table[i].start, file_table[i].no_of_blocks);
        for (j = 0; j < file_table[i].no_of_blocks; j++)
            printf("%d, ", file_table[i].start + j);
    }

    return 0;
}