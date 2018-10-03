#include <stdlib.h>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <regex>

using namespace std;

int mazeCreate(vector<string> command , vector<vector<vector<int>>> & cell)
{

    cout << "command is :" << endl;
    cout << command[0].c_str() << endl;
    cout << command[1].c_str() << endl;

    unsigned int roadGridWidth;
    unsigned int roadGridHeight;

    roadGridWidth = atoi(command[0].substr (0,command[0].find_first_of(" ")).c_str());
    roadGridHeight = atoi(command[0].substr (command[0].find_first_of(" "),command[0].size() ).c_str());
    cout << "roadGridWidth :" << roadGridWidth << endl;
    cout << "roadGridHeight :" << roadGridHeight << endl;
    cout << "================" << endl;


   //vector<vector<vector<int>>> cell;

   cell.resize(roadGridHeight);

   for(int i = 0 ;i<cell.size();i++)
   {
       cell[i].resize(roadGridWidth);
   }

   for(int i = 0;i<cell.size();i++)
   {
       for(int j = 0 ;j<cell[0].size();j++ )
       {
           printf("cell(%d,%d)   ",i,j);
           cell[i][j].push_back(0); //0表示没有连接、 1 表示正南、2 表示正北、3 表示正东、4 表示正西
       }
       printf("\n");
   }

   string connectivity ;
   string connectivityLast = command[1];
   string connectivityCellFirst;
   string connectivityCellLast;
   string cell_x1_string;
   string cell_x2_string;
   int cell_x1;
   int cell_y1;
   int cell_x2;
   int cell_y2;
   for (int i= 0; i<command[1].find(";") + 1;i++)
   {
       connectivity = connectivityLast.substr(0,connectivityLast.find_first_of(";"));

       cout << connectivity.c_str() << endl ;

       connectivityCellFirst = connectivity.substr(0,connectivity.find_first_of(" "));
       connectivityCellLast = connectivity.substr(connectivity.find_first_of(" ") + 1,connectivity.size() - connectivityCellFirst.size());

       cout << connectivityCellFirst.c_str() << endl;
       cout << connectivityCellLast.c_str() << endl;

       cell_x1_string = connectivityCellFirst.substr (0,connectivityCellFirst.find_first_of(","));
       cell_x1 = atoi(cell_x1_string.c_str());
       cell_y1 = atoi(connectivityCellFirst.substr (connectivityCellFirst.find_first_of(",") + 1,connectivityCellFirst.size() - cell_x1_string.size() ).c_str());

       cell_x2_string = connectivityCellLast.substr (0,connectivityCellLast.find_first_of(","));
       cell_x2 = atoi(cell_x2_string.c_str());
       cell_y2 = atoi(connectivityCellLast.substr (connectivityCellLast.find_first_of(",") + 1,connectivityCellLast.size() - cell_x2_string.size() ).c_str());

       printf ("connectivity : (%d,%d) <--> (%d,%d) \n" ,cell_x1,cell_y1,cell_x2,cell_y2);

       if((cell_x1 - cell_x2) == 0)
       {


           if((cell_y1 - cell_y2) < 0)
           {

               printf("cell(%d,%d) : 1 \n",cell_x1,cell_y1);
               printf("cell(%d,%d) : 2 \n",cell_x2,cell_y2);
               cell[cell_x1][cell_y1] .push_back(1);
               cell[cell_x2][cell_y2] .push_back(2);
           }
           else
           {
               printf("cell(%d,%d) : 2 \n",cell_x1,cell_y1);
               printf("cell(%d,%d) : 1 \n",cell_x2,cell_y2);
               cell[cell_x1][cell_y1] .push_back(2);
               cell[cell_x2][cell_y2] .push_back(1);
           }
       }
       else
       {


           if((cell_x1 - cell_x2) < 0)
           {
               printf("cell(%d,%d) : 3 \n",cell_x1,cell_y1);
               printf("cell(%d,%d) : 4 \n",cell_x2,cell_y2);
               cell[cell_x1][cell_y1] .push_back(3);
               cell[cell_x2][cell_y2] .push_back(4);
           }
           else
           {
               printf("cell(%d,%d) : 4 \n",cell_x1,cell_y1);
               printf("cell(%d,%d) : 3 \n",cell_x2,cell_y2);
               cell[cell_x1][cell_y1] .push_back(4);
               cell[cell_x2][cell_y2] .push_back(3);
           }
       }


       connectivityLast = connectivityLast.substr(connectivityLast.find_first_of(";") + 1,connectivityLast.size()-connectivity.size());

       cout << connectivityLast.c_str()  << endl;

   }

   connectivityCellFirst = connectivityLast.substr(0,connectivityLast.find_first_of(" "));
   connectivityCellLast = connectivityLast.substr(connectivityLast.find_first_of(" ") + 1,connectivityLast.size() - connectivityCellFirst.size());

   cout << connectivityCellFirst.c_str() << endl;
   cout << connectivityCellLast.c_str() << endl;

   cell_x1_string = connectivityCellFirst.substr (0,connectivityCellFirst.find_first_of(","));
   cell_x1 = atoi(cell_x1_string.c_str());
   cell_y1 = atoi(connectivityCellFirst.substr (connectivityCellFirst.find_first_of(",") + 1,connectivityCellFirst.size() - cell_x1_string.size() ).c_str());

   cell_x2_string = connectivityCellLast.substr (0,connectivityCellLast.find_first_of(","));
   cell_x2 = atoi(cell_x2_string.c_str());
   cell_y2 = atoi(connectivityCellLast.substr (connectivityCellLast.find_first_of(",") + 1,connectivityCellLast.size() - cell_x2_string.size() ).c_str());

   printf ("connectivity : (%d,%d) <--> (%d,%d) \n" ,cell_x1,cell_y1,cell_x2,cell_y2);

   if((cell_x1 - cell_x2) == 0)
   {


       if((cell_y1 - cell_y2) < 0)
       {

           printf("cell(%d,%d) : 1 \n",cell_x1,cell_y1);
           printf("cell(%d,%d) : 2 \n",cell_x2,cell_y2);
           cell[cell_x1][cell_y1] .push_back(1);
           cell[cell_x2][cell_y2] .push_back(2);
       }
       else
       {
           printf("cell(%d,%d) : 2 \n",cell_x1,cell_y1);
           printf("cell(%d,%d) : 1 \n",cell_x2,cell_y2);
           cell[cell_x1][cell_y1] .push_back(2);
           cell[cell_x2][cell_y2] .push_back(1);
       }
   }
   else
   {


       if((cell_x1 - cell_x2) < 0)
       {

           printf("cell(%d,%d) : 3 \n",cell_x1,cell_y1);
           printf("cell(%d,%d) : 4 \n",cell_x2,cell_y2);
           cell[cell_x1][cell_y1] .push_back(3);
           cell[cell_x2][cell_y2] .push_back(4);
       }
       else
       {
           printf("cell(%d,%d) : 4 \n",cell_x1,cell_y1);
           printf("cell(%d,%d) : 3 \n",cell_x2,cell_y2);
           cell[cell_x1][cell_y1] .push_back(4);
           cell[cell_x2][cell_y2] .push_back(3);
       }
   }

    return 0;
}

void mazeRender(vector<vector<vector<int>>> cell)
{
    printf("=============\n" );

    vector<vector<char>> mazeText;

    mazeText.resize(cell.size() * 2 +1);

    for(int i = 0 ;i<mazeText.size();i++)
    {
        mazeText[i].resize(cell[0].size() * 2 +1);
    }

    for(int i = 0;i<mazeText.size();i++)
    {
        for(int j = 0 ;j<mazeText[0].size();j++ )
        {
            //printf("[M] ",i,j);
            mazeText[i][j] = 'M'; //0表示没有连接、 1 表示正南、2 表示正北、3 表示正东、4 表示正西
        }
           //printf("\n");
    }

    for(int i = 0;i<cell.size();i++)
    {
        for(int j = 0 ;j<cell[0].size();j++ )
        {

            mazeText[i * 2 + 1][j * 2 + 1] = 'R';


            printf("[" );
            //0表示没有连接、 1 表示正南、2 表示正北、3 表示正东、4 表示正西
            for (int k =1;k<cell[i][j].size();k++)
            {
                printf(" %d ", cell[i][j][k] );

                if(cell[i][j][k] == 1)
                {
                     mazeText[i * 2 + 1][j * 2 + 1 + 1] = 'R';
                }

                if(cell[i][j][k] == 2)
                {
                     mazeText[i * 2 + 1][j * 2 + 1 - 1] = 'R';
                }

                if(cell[i][j][k] == 3)
                {
                     mazeText[i * 2 + 1 + 1][j * 2 + 1 ] = 'R';
                }

                if(cell[i][j][k] == 4)
                {
                     mazeText[i * 2 + 1 - 1][j * 2 + 1 ] = 'R';
                }
            }
            printf("]      " );

        }

        printf("\n");
    }
    printf("====mazeText====\n" );
    for(int i = 0;i<mazeText.size();i++)
    {
        for(int j = 0 ;j<mazeText[0].size();j++ )
        {
            printf("[%c] ",mazeText[i][j]);
            //mazeText[i][j] = 'M'; //0表示没有连接、 1 表示正南、2 表示正北、3 表示正东、4 表示正西
        }
        printf("\n");
    }

}

int main(int argc, char *argv[])
{
    vector<string> command;
    command.push_back("3 3");
    command.push_back("0,1 0,2;0,0 1,0;0,1 1,1;0,2 1,2;1,0 1,1;1,1 1,2;1,1 2,1;1,2 2,2;2,0 2,1");

    vector<vector<vector<int>>> maze;
    mazeCreate(command,maze);

    mazeRender(maze);

    return 0;
}
