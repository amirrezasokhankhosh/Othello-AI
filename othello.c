#include <stdio.h>
void moves(int *validcell[8][8], int field[8][8], int x, int y, int competitor);
void right(int *validcell[8][8], int field[8][8], int x, int y, int competitor);
void left(int *validcell[8][8], int field[8][8], int x, int y, int competitor);
void up(int *validcell[8][8], int field[8][8], int x, int y, int competitor);
void down(int *validcell[8][8], int field[8][8], int x, int y, int competitor);
void right_up(int *validcell[8][8], int field[8][8], int x, int y, int competitor);
void left_up(int *validcell[8][8], int field[8][8], int x, int y, int competitor);
void left_down(int *validcell[8][8], int field[8][8], int x, int y, int competitor);
void right_down(int *validcell[8][8], int field[8][8], int x, int y, int competitor);
int nextmove ( int validcell[8][8] , int scorematrix[8][8]);
int main(int argc, char *argv[])
{
    int player = argv[9][0] - 48;
    int field[8][8], validcell[8][8], competitor;
    if (player == 2)
    {
        competitor = 1;
    }
    else if (player == 1)
    {
        competitor = 2;
    }

    int scorematrix[8][8]={ {120,-20,20, 5, 5,20,-20,120},
                            {-20,-40,-5,-5,-5,-5,-40,-20},
                            { 20, -5,15, 3, 3,15, -5, 20},
                            {  5, -5, 3, 3, 3, 3, -5,  5},
                            {  5, -5, 3, 3, 3, 3, -5,  5},
                            { 20, -5,15, 3, 3,15, -5, 20},
                            {-20,-40,-5,-5,-5,-5,-40,-20},
                            {120,-20,20, 5, 5,20,-20,120}};
    
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            field[i][j] = argv[i + 1][j] - 48;
            validcell[i][j] = 0;
        }
    }
    
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (field[i][j] == player)
            {
                //player is i , j
                moves(validcell, field, i, j, competitor);
            }
        }
    }
    nextmove(validcell ,scorematrix);
    return 0;
}
void moves(int *validcell[8][8], int field[8][8], int x, int y, int competitor)
{
    if (x < 7 && field[x + 1][y] == competitor)
    {
        //now we are going to check down on x + 1 , y
        down(validcell, field, x + 1, y, competitor);
    }
    if (x < 7 && y > 0 && field[x + 1][y - 1] == competitor)
    {
        //now we are going to check left_down on x + 1 , y - 1
        left_down(validcell, field, x + 1, y - 1, competitor);
    }
    if (y > 0 && field[x][y - 1] == competitor)
    {
        //now we are going to check left on x - 1 , y
        left(validcell, field, x, y - 1, competitor);
    }
    if (x > 0 && y > 0 && field[x - 1][y - 1] == competitor)
    {
        //now we are going to check left_up on x - 1 , y - 1
        left_up(validcell, field, x - 1, y - 1, competitor);
    }
    if (x > 0 && field[x - 1][y] == competitor)
    {
        //now we are going to check up on x - 1 , y
        up(validcell, field, x - 1, y, competitor);
    }
    if (x > 0 && y < 7 && field[x - 1][y + 1] == competitor)
    {
        //now we are going to check right_up on x - 1 , y + 1
        right_up(validcell, field, x - 1, y + 1, competitor);
    }
    if (y < 7 && field[x][y + 1] == competitor)
    {
        //now we are going to check right on x , y + 1
        right(validcell, field, x, y + 1, competitor);
    }
    if (x < 7 && y < 7 && field[x + 1][y + 1] == competitor)
    {
        //now we are going to check right_down on x + 1 , y + 1
        right_down(validcell, field, x + 1, y + 1, competitor);
    }
}
void down(int *validcell[8][8], int field[8][8], int x, int y, int competitor)
{
    if (x < 7 && field[x + 1][y] == competitor)
    {
        //now we are going to check down on x + 1 , y
        down(validcell, field, x + 1, y, competitor);
    }
    if (x <= 7 && field[x + 1][y] == 0)
    {
        //found x + 1 , y
        validcell[x + 1][y] = 1;
    }
}
void up(int *validcell[8][8], int field[8][8], int x, int y, int competitor)
{
    if (x > 0 && field[x - 1][y] == competitor)
    {
        //now we are going to check up on x - 1 , y
        up(validcell, field, x - 1, y, competitor);
    }
    if (x >= 0 && field[x - 1][y] == 0)
    {
        //found x - 1 , y
        validcell[x - 1][y] = 1;
    }
}
void left(int *validcell[8][8], int field[8][8], int x, int y, int competitor)
{
    if (y > 0 && field[x][y - 1] == competitor)
    {
        //now we are going to check left on x , y - 1
        left(validcell, field, x - 1, y, competitor);
    }
    if (y >= 0 && field[x][y - 1] == 0)
    {
        //found x , y - 1
        validcell[x][y - 1] = 1;
    }
}
void right(int *validcell[8][8], int field[8][8], int x, int y, int competitor)
{
    if (y < 7 && field[x][y + 1] == competitor)
    {
        //now we are going to check right on x , y + 1
        right(validcell, field, x, y + 1, competitor);
    }
    if (y <= 7 && field[x][y + 1] == 0)
    {
        //found x , y + 1
        validcell[x][y + 1] = 1;
    }
}
void left_down(int *validcell[8][8], int field[8][8], int x, int y, int competitor)
{
    if (x < 7 && y > 0 && field[x + 1][y - 1] == competitor)
    {
        //now we are going to check left_down on x + 1 , y - 1
        left_down(validcell, field, x + 1, y - 1, competitor);
    }
    if (x <= 7 && y >= 0 && field[x + 1][y - 1] == 0)
    {
        //found x + 1 , y - 1
        validcell[x + 1][y - 1] = 1;
    }
}
void left_up(int *validcell[8][8], int field[8][8], int x, int y, int competitor)
{
    if (x > 0 && y > 0 && field[x - 1][y - 1] == competitor)
    {
        //now we are going to check left_up on x - 1 , y - 1
        left_up(validcell, field, x - 1, y - 1, competitor);
    }
    if (x >= 0 && y >= 0 && field[x - 1][y - 1] == 0)
    {
        //found x - 1 , y - 1
        validcell[x - 1][y - 1] = 1;
    }
}
void right_up(int *validcell[8][8], int field[8][8], int x, int y, int competitor)
{
    if (x > 0 && y < 7 && field[x - 1][y + 1] == competitor)
    {
        //now we are going to check right_up on x - 1 , y + 1
        right_up(validcell, field, x - 1, y + 1, competitor);
    }
    if (x >= 0 && y <= 7 && field[x - 1][y + 1] == 0)
    {
        //found x - 1 , y + 1
        validcell[x - 1][y + 1] = 1;
    }
}
void right_down(int *validcell[8][8], int field[8][8], int x, int y, int competitor)
{
    if (x < 7 && y < 7 && field[x + 1][y + 1] == competitor)
    {
        //now we are going to check right_down on x + 1 , y + 1
        right_down(validcell, field, x + 1, y + 1, competitor);
    }
    if (x <= 7 && y <= 7 && field[x + 1][y + 1] == 0)
    {
        //found x + 1 , y + 1
        validcell[x + 1][y + 1] = 1;
    }
}
int nextmove ( int validcell[8][8] , int scorematrix[8][8])
{
    int availablecell[64];
    int bestcell [8][8];
    for ( int i=0;i<8;i++)
    {
        for( int j=0;j<8;j++)
        {
            availablecell[8*i+j]=-200;
            bestcell [i][j]=-200; 
        }
    }

    for ( int i=0;i<8;i++)
    {
        for( int j=0;j<8;j++)
        {
            if ( validcell[i][j]==1)
            {
                availablecell[8*i+j]=scorematrix[i][j];
                bestcell [i][j]=scorematrix[i][j];  
            }
        }
    }

    for ( int i=0;i<63;i++)
    if ( availablecell[i+1]<availablecell[i])
    {
        int t=availablecell[i+1];
        availablecell[i+1]=availablecell[i];
        availablecell[i]=t;
    }

    for( int i=0;i<8;i++)
    {
        for( int j=0;j<8;j++)
        if(availablecell[63]==bestcell[i][j])
        {
            printf("%d %d" ,j ,i);
            availablecell[63]=-300;
        }
    }
}