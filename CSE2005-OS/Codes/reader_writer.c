// Simulating reader_writer problem
// Solution using semaphores

# include <stdio.h>
# include <stdlib.h>


int read_count = 0;         // How many processes are currently reading the object
int semaphore_mutex = 1;    // Semaphore to ensure mutual exclusion when read_count is being updated
int semaphore_rw_mutex = 1; // Semaphore common to both reader and writer processes

void wait(int s);
void signal(int s);
void reader(int num);
void writer(int num);

int main()
{
    int process[10] = {1, 2, 1, 1, 1, 2, 2, 2, 1, 2};
    int i;

    for(i = 0; i < 10; i++)
    {
        if(process[i] == 1)
        {
            reader(i);
        }
        else
        {
            writer(i);
        }        
    }

    return 0;
}

// Funtion to wait on semaphore s
void wait(int s)
{
    while(s <= 0);
    s--;
}

// Function to signal release
void signal(int s)
{
    s++;
}

// Funtion to simulate reader process
void reader(int num)
{
    wait(semaphore_mutex);
    read_count++;
    if (read_count == 1)
    {
        wait(semaphore_rw_mutex);
    }
    signal(semaphore_mutex);

    printf("\nP%d is performing read operation...\n", num);

    wait(semaphore_mutex);
    read_count--;
    if(read_count == 0)
    {
        signal(semaphore_rw_mutex);
    }
    signal(semaphore_mutex);    
}

// Function to simulate writer process
void writer(int num)
{
    wait(semaphore_rw_mutex);
    printf("\nP%d is performing write operation...\n", num);
    signal(semaphore_rw_mutex);
}