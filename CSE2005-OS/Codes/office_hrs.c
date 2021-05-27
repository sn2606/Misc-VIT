# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# define N 3

int professor_can_answer = 1; // (Binary) Semaphore to ensure mutual exclusion in asking questions
// Since professor can answer only one question at a time
// initialized to 0. Initially professor is not answering questions
int student_can_ask = 1; 
/********************************************************************************************/
int professor_asleep = 1;   // Flag variable to check if professor is asleep or not. High logic.
int no_of_students = 0;     // Number of students currently in the room. Initialized to 0
int can_come_in = 1;        // If number of students is greater than 3, new students cant come in (flag variable)
int has_come_in = 0;

// Prototyping functions
void leave(int n);
void come_in(int n);
int out_room_student(int n);
void wait(int s);
void signal(int s);
void in_room_student();
void professor();

// Driver function
int main()
{
    
    professor();
    in_room_student();
    out_room_student(2);
    out_room_student(1);
    in_room_student();
    professor();
    in_room_student();
    professor();
    professor();
    
    return 0;
}

// Dont wait outside room
void leave(int n)
{
    printf("\n%d students could not be admitted since room is crowded.", n);
}

void come_in(int n)
{
    printf("\n%d students were admitted in the room.", n);
    no_of_students += n;
}

// Function to simulate how student out of the room behaves
int out_room_student(int n)
{
    int available_space = N - no_of_students;
    
    if(available_space == 0)
    {
        can_come_in = 0;
        leave(n);
    }
    else if(available_space > 0 && n <= available_space)
    {
        can_come_in = 1;
        has_come_in = 1;
        come_in(n);
    }
    else if(available_space > 0 && n > available_space)
    {
        can_come_in = 1;
        has_come_in = 1;
        leave(n - available_space);
        come_in(available_space);
    }
       
    return available_space;
}

// Funtion to wait on semaphore s
void wait(int s)
{
    printf("\nPlease wait till your turn comes!\n");
    while(s <= 0);
    s--;
}

// Function to signal release
void signal(int s)
{
    s++;
}

// Function to simulate how student inside a room behaves
void in_room_student()
{
    if(no_of_students)
    {
        wait(student_can_ask);
        printf("\nStudent is asking a question...");
        signal(student_can_ask);
    }
    else
    {
        printf("\nNo students in the room!");
    }
    
}


// Function to simulate how professor behaves
void professor()
{
    if (no_of_students == 0)
    {
        can_come_in = 1;
        has_come_in = 0;
        professor_asleep = 1;
        printf("\nProfessor is asleep.");
        return;
    }

    if(no_of_students == 0 && has_come_in == 1)
    {
        professor_asleep = 0;
        printf("\nProfessor is awake now.");
        professor_can_answer = 1;
        return;
    }

    if(professor_asleep)
    {
        wait(professor_can_answer);
        printf("\nProfessor is answering student's question...");
        printf("\nStudent's question satisfied.");
        no_of_students--;
        printf("\nStudent has left the room as question was satisfied.");
        signal(professor_can_answer);
    }
}