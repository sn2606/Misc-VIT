// BATCH 4 
// SWARANJANA NAYAK - 19BCE0977

// Design a structure laptop with the specification model(dell, HP etc), cost, quantity.  
// Customer places a order based on the requirement.  
// Prepare a Bill in the following format

// Product Model    Quantity                  Cost

// Dell                2                      1,50,000
// HP                  1                      1,00,000

// Total cost                                 3,00,000

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define N 10

// Struct definition of laptop
typedef struct laptop
{
    char **model;
    int *cost;
    int *quantity;
}Laptop;

enum cost_val{HP = 100000, Dell = 150000, Lenovo = 120000, Acer = 143000};

// Prototyping functions
Laptop *initialize_laptop(Laptop *order, int no_of_items);


int main()
{
    int i, j, no_of_customers = 0, no_of_items, total_cost, value;
    char more;
    Laptop **orders; // an array of orders for multiple customers, if they come.

    orders = (Laptop **)malloc(N * sizeof(Laptop *));
    for(i = 0; i < N; i++)
    {
        *(orders + i) = NULL;
    }

    do
    {
        printf("\nWelcome Customer %d!\n", no_of_customers + 1);
        printf("\nHow many items Laptops are you going to buy?: ");
        scanf("%d", &no_of_items);
        fflush(stdin);

        orders[no_of_customers] = initialize_laptop(orders[no_of_customers], no_of_items);

        total_cost = 0;
        for(i = 0; i < no_of_items; i++)
        {
            printf("What is model name you want for item %d?: ", i + 1);
            fflush(stdin);
            fgets(orders[no_of_customers]->model[i], N, stdin);
            //printf("\n%s", orders[no_of_customers]->model[i]);

            printf("How many laptops of that model do you want?: ");
            scanf("%d", ((*(orders + no_of_customers))->quantity) + i);

            if(strcmp(orders[no_of_customers]->model[i], "HP\n") == 0)
            {
                printf("yes");
                value = 100000;
            }
            else if(strcmp(orders[no_of_customers]->model[i], "Dell\n") == 0)
            {
                value = 150000;
            }
            else if(strcmp(orders[no_of_customers]->model[i], "Lenovo\n") == 0)
            {
                value = 120000;
            }
            else if(strcmp(orders[no_of_customers]->model[i], "Acer\n") == 0)
            {
                value = 143000;
            }

            orders[no_of_customers]->cost[i] = orders[no_of_customers]->quantity[i]  * value;
            total_cost += *(((*(orders + no_of_customers))->cost) + i);
        }

        printf("\nCustomer %d, your bill is:-", no_of_customers + 1);
        printf("\n\nProduct Model    Quantity                  Cost\n");
        printf("-----------------------------------------------------\n");
        for(i = 0; i < no_of_items; i++)
        {
            printf("%s\t\t\t%d\t%d\n", *(((*(orders + no_of_customers))->model) + i), *(((*(orders + no_of_customers))->quantity) + i), *(((*(orders + no_of_customers))->cost) + i));
        }

        printf("-------------------------------------------------------\n");
        printf("Total Cost                                     %d\n\n", total_cost);

        printf("Thank you Customer %d!\n", no_of_customers + 1);
        printf("\n================================================================\n\n");

        fflush(stdin);
        printf("Is there a next customer?: ");
        scanf("%c", &more);

        if(more != 'n')
        {
            no_of_customers++;
            no_of_items = 0;
            total_cost = 0;
        }


    } while (more != 'n');
    
    
    return 0;
}

// Function to initialize the laptop struct to hold the information
Laptop *initialize_laptop(Laptop *order, int no_of_items)
{
    int i;

    order = (Laptop *)malloc(sizeof(Laptop));
    //printf("hello");
    order->model = (char **)malloc(no_of_items * sizeof(char*));
    for(i = 0; i < no_of_items; i++)
    {
        *((order->model)+i) = (char *)malloc(N * sizeof(char));
    }

    order->cost  = (int *)malloc(no_of_items * sizeof(int));
    order->quantity = (int *)malloc(no_of_items * sizeof(int));

    return order;
}