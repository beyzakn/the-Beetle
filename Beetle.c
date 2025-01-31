#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define size 8


void pickway(); //will stay without parameters. its fine.
bool invalid(int p, int r);
bool checkend(); //will stay without parameters. its fine.

int x=0;
int y=0;

int directions[2][8]={{0,0,-1,1,-1,-1,1,1}, {-1,1,0,0,1,-1,1,-1}};
int chsnway[8]={0};
int grid[size][size] = {0};
int passtry = 0;  //how many times beetle tried to pass the border (made invalid move)


int main()
{

    srand(time(NULL));
    int a,b;

    printf("please choose a starting position x,y: ");
    scanf("%d,%d",&x,&y);


    while(checkend()== false) //while program's ending condition hasn't met, while it goes on
    {
        pickway(); //we will just calll pickway until program ends, all the job will be done inside the pickway function
    }



    for(a=0;a < size; a++) //printing the final grid matrix
    {
        for(b=0;b <size ;b++)
        {
            printf("%d\t",grid[a][b]);
        }
        printf("\n");
    }


    int allmoves= chsnway[0]+chsnway[1]+chsnway[2]+chsnway[3]+chsnway[4]+chsnway[5]+chsnway[6]+chsnway[7]+ passtry;

    printf("\n");
    // %20 gibi yüzdelik şeklinde göstermek için outputu
    printf("probability of moving left: %d%%\n", (int)((chsnway[0]* 1.0/allmoves)*100)); 
    printf("probability of moving right: %d%%\n", (int)((chsnway[1] * 1.0 / allmoves) * 100));
    printf("probability of moving up: %d%%\n", (int)((chsnway[2] * 1.0 / allmoves) * 100));
    printf("probability of moving down: %d%%\n", (int)((chsnway[3] * 1.0 / allmoves) * 100));
    printf("probability of tying to pass border: %d%%\n", (int)((passtry * 1.0 / allmoves) * 100));

  return 0;
}


//create functions below main()

bool invalid(int r, int c)
{
    if(r>size || r<0 || c>size || c<0)
    {
        return true;
    }
    return false;
}

void pickway()
{
    int rnd = rand() % size;  //the randomly chosen value that will become the directions matrix's column value.(by this, the beetle will have chosen a way)
    int new_x = x + directions[0][rnd];
    int new_y = y + directions[1][rnd];

    if (invalid(new_x,new_y)== false)
    {
        x = new_x;  //x and y are global variables. so they will not reset each time pick() called. so beetle will keep on moving from where it went in the previous step.
        y = new_y;

        grid[x][y]++; //increasing the visit count of grid's new visited element
        chsnway[rnd]++; //increasing the chosen drection's count
    }
    else
    {
        passtry++;
    }
}


bool checkend()
{
    int a,b;  //local variables. these a,b will only change in this function.they dont affect other a and b values in the code
    for(a=0;a<size;a++)
    {
        for(b=0;b<size;b++)
        {
            if(grid[a][b]==0) //if one of the element's value is 0 in grid matrix, then ending condition hasn't met
            {
                return false;
            }
        }
    }
    return true;
}
