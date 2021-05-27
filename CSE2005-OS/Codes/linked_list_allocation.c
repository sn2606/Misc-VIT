# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define len 20
# define N 30

struct fileTable
{
    char name[len];
    int no_of_blocks;
    struct block *start;
} file_table[N];

struct block
{
    int bno;
    struct block *next;
};

int main()
{
    int i, j, n;
    char s[len];
    struct block *temp;

    printf("Enter no of files: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter file name %d: ", i + 1);
        scanf("%s", file_table[i].name);

        printf("Enter no of blocks in file %d: ", i + 1);
        scanf("%d", &file_table[i].no_of_blocks);
        file_table[i].start = (struct block *)malloc(sizeof(struct block));
        temp = file_table[i].start;
        
        printf("Enter the blocks of the file: ");
        scanf("%d", &temp->bno);
        temp->next = NULL;
        for (j = 1; j < file_table[i].no_of_blocks; j++)
        {
            temp->next = (struct block *)malloc(sizeof(struct block));
            temp = temp->next;
            scanf("%d", &temp->bno);
        }
        temp->next = NULL;
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
        printf("\nFILE NAME NO OF BLOCKS BLOCKS OCCUPIED");
        printf("\n %s\t\t%d\t", file_table[i].name, file_table[i].no_of_blocks);
        temp = file_table[i].start;
        for (j = 0; j < file_table[i].no_of_blocks; j++)
        {
            printf("%d->", temp->bno);
            temp = temp->next;
        }
    }

    return 0;
}