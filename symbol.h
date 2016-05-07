#ifndef _TIC_SYMBOL_
#define _TIC_SYMBOL_

// CS 172 - Assignment 3 - Tic-Tac-Toe
// Symbol H File by Mark Boady
// Drexel University 2016


#include <iostream>

//Each Space is marked with a symbol or blank
enum symbol {X,O,BLANK};

//Output Operator
std::ostream & operator<<(std::ostream& os, const symbol& my_symbol);
//Prefix ++a increment
symbol& operator++(symbol& my_symbol);
//Postfix a++ increment
symbol operator++(symbol & my_symbol,int);

#endif
