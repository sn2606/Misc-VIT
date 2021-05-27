#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *queue, q_size, head, seek = 0, diff, i, j;
  float avg;

  printf("\n-----FCFS Disk Scheduling Algorithm-----\n\n");

  printf("Enter the size of the queue: ");
  scanf("%d", &q_size);

  queue = (int *)malloc((q_size + 1) * sizeof(int));

  printf("Enter queue elements: ");
  for (i = 1; i <= q_size; i++)
  {
    scanf("%d", &queue[i]);
  }

  printf("Enter initial head position: ");
  scanf("%d", &head);

  queue[0] = head;

  for (j = 0; j <= q_size - 1; j++)
  {
    diff = abs(queue[j] - queue[j + 1]);
    seek += diff;
    printf("Move from %d to %d with Seek %d\n", queue[j], queue[j + 1], diff);
  }

  printf("\nTotal seek time is %d\t", seek);
  avg = seek / (float)q_size;
  printf("\nAverage seek time is %f\t", avg);

  return 0;
}
