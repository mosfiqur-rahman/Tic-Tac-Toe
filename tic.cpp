// Main File by Mosfiqur Rahman
// Drexel University 2016

#include <vector>
#include <iostream>
#include <string>
#include "symbol.h"
#include "tic.h"
#include <sstream>
using namespace std;


//Default Constructor
tBoard::tBoard()
//Makes a board with all blank spaces
{
	
	for(int i =0; i< 9; i++)
	{
		gameboard.push_back(BLANK);
	}
}




bool tBoard::move(symbol m, int x, int y)
//Makes a move on the board
//X is the row and y is the column
//m is the symbol to place (either X or O)
{
	
	int position = 3*x + y;
	if(gameboard[position] != BLANK)
        {
            return false;
//If the move is illegal, returns false and doesn't change the table
	    
        }
   	else
	{
		gameboard[position] = m; 
//It returns true if the move was made and changes the table
	}   	
}

bool tBoard::game_over()
//Returns true if the game is over
//This could be because of a winner or because of a tie
{
	if(winner()!= BLANK)
	{
		return true;
	}
	else
	{
		for(int j =0; j< 9; j++)
		{
			if (gameboard[j] == BLANK)
			{
				return false;
			}
		}
	return true;
	}		
        
}

symbol tBoard::winner()
//Returns who won X or O
{
	
    if(gameboard[0] == gameboard[1] && gameboard[0] == gameboard[2] && gameboard[0] != BLANK)
    {       
	return gameboard[0];
    }
    else if(gameboard[3] == gameboard[4] && gameboard[3] == gameboard[5] && gameboard[3] != BLANK)
    {        
	return gameboard[3];
    }
    else if(gameboard[6] == gameboard[7] && gameboard[6] == gameboard[8] && gameboard[6] != BLANK)
    {        
	return gameboard[6];
    }
    else if(gameboard[0] == gameboard[3] && gameboard[0] == gameboard[6] && gameboard[0] != BLANK)
    {        
	return gameboard[0];
    }
    else if(gameboard[1] == gameboard[4] && gameboard[1] == gameboard[7] && gameboard[1] != BLANK)
    {        
	return gameboard[1];
    }
    else if(gameboard[2] == gameboard[5] && gameboard[2] == gameboard[8] && gameboard[2] != BLANK)
    {       
	return gameboard[2];
    }
    else if(gameboard[0] == gameboard[4] && gameboard[0] == gameboard[8] && gameboard[0]!= BLANK)
    {        
	return gameboard[0];
    }
    else if(gameboard[2] == gameboard[4] && gameboard[2] == gameboard[6] && gameboard[2] != BLANK)
    {        
	return gameboard[2];
    }   
    else
	{
		return BLANK;
//If the game was a tie, returns  BLANK
	}
}


void tBoard::toBoard(ostream& os) const
//For formatting the assigned Tic-Toc-Toe Board
{

	os << " " << "|" <<  "  0  " << "|" << "  1  " << "|" << "  2  " << "|" <<endl;
        os << " +-----------------+ "<<endl;
        os << "0" <<"|"<< "  "<< gameboard[0] <<"  "<< "|" << "  "<< gameboard[1] << "  " << "|" << "  "<< gameboard[2] << "  " <<"|"<< endl;
        os << " +-----------------+ "<<endl;
        os << "1" <<"|"<< "  "<< gameboard[3] <<"  "<< "|" << "  "<<gameboard[4] << "  " << "|" << "  "<< gameboard[5] << "  " <<"|"<< endl;
        os << " +-----------------+ "<<endl;
        os << "2" <<"|"<< "  "<< gameboard[6] <<"  "<< "|" << "  "<<gameboard[7] << "  " << "|" << "  "<< gameboard[8] << "  " <<"|"<<endl;
        os << " +-----------------+ "<<endl <<endl;

} 

ostream & operator<<(ostream& os, const tBoard& myTable)
//Overloads the output operator
{	  
	myTable.toBoard(os);
	return os;	
}		

































  	
