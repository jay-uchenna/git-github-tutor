//
//  main.cpp
//  dice
//
//  Created by Jedidiah Uchenna on 22.01.2022.
//





#include <iostream>
#include <math.h>
#include <random>
#include <string>

const int D = 40;
const int s = (const int)2 * D;

bool throw_dice()
{

    std::cout << "press y to throw dice: ";

    std::string throw_dice;
    std::getline (std::cin,throw_dice);

    if((throw_dice[0] == 'y' || throw_dice[0] == 'Y') && throw_dice.size() == 1 ){
       return true;
    }
    else return false;

}

int random_1_to_6(int first_range, int last_range)
{
    
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni( first_range, last_range);

    return uni(rng);

}
void draw_dice_circle(char (&square_arr)[D][s], int point_x, int point_y)
{
    int radius_of_c = 5;
       
   int x = 0;
   int y = 0;

   for(int i = point_x; i <= radius_of_c + point_x; i++, y++)
   {
   
       //we need to multiply the result by because while printing the OS adds an extra between rows
        x = 2 * (sqrt( (radius_of_c*radius_of_c) - (y * y) ));
       
        for (int j = (point_y-x); j <= (point_y+x); j++)
        {
            
            square_arr[point_x-y][j] = ' ';
            square_arr[point_x+y][j] = ' ';
            
        }

   }
     
}


void arrange_cirles_on_dice(char (&square_arr)[D][s])
{

    switch(random_1_to_6(1, 6)){
        case 6:
                draw_dice_circle(square_arr, 20, 20);
                draw_dice_circle(square_arr, 20, 60);
        case 4:
                draw_dice_circle(square_arr, 7, 20);
                draw_dice_circle(square_arr, 33, 60);
        case 2:
                draw_dice_circle(square_arr, 33, 20);
                draw_dice_circle(square_arr, 7, 60);
               break;

        case 5:
                draw_dice_circle(square_arr, 7, 20);
                draw_dice_circle(square_arr, 33, 60);
        case 3:
                draw_dice_circle(square_arr, 33, 20);
                draw_dice_circle(square_arr, 7, 60);
        case 1:
                draw_dice_circle(square_arr, 20, 40);
                break;
        default:
                break;
    }
}

void display_dice(char (&square_arr)[D][s])
{
    for(int i = 0; i < D; i++){
        for(int j = 0; j < s; j++){
            std::cout << square_arr[i][j];
        }
   }

   std::cout << "\n";
}
void draw_dice(char (&square_arr)[D][s])
{

   for(int i = 0; i < D; i++){
        for(int j = 0; j < s; j++){
            if (j == (s-1)){
                square_arr[i][j] = '\n';
                continue;
            }
            square_arr[i][j] = '*';
        }
   }
   arrange_cirles_on_dice(square_arr);
}


int main()
{
    
   char square_arr[D][s];

   do
   {
        
        
        draw_dice(square_arr);
        display_dice(square_arr);

   }while(throw_dice());


    return 0;
}








//deteched head
