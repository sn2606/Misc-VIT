# include <stdio.h>
# include <stdlib.h>

struct something
{
    int q;
    int r;
}glob_al;

int rep(struct something st);

int main()
{
    struct something loc_al;
    int n = 2183;
    int n2 = 2345;

    loc_al.q = n / 10;
    loc_al.r = n % 10;

    glob_al.q = n2 / 10;
    glob_al.r = n2 % 10;

    printf("loc : %d\n", rep(loc_al));
    printf("glob : %d\n", rep(glob_al));

    return 0;

}

int rep(struct something st)
{   
    //struct something loc_al;
    //printf("%d\n", loc_al.q);
    printf("%d\n", glob_al.q);
    return st.q * 10 + st.r;
}
