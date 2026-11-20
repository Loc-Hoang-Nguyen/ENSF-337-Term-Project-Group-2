#include "Airline_utility.h"

#include <iostream>

void clearInputBuffer()
{
    //cin.clear() is needed since if user try something like inputing letter to int
    //it will spontanously explode
    std::cin.clear();
    char c;
    do{
        c = std::cin.get();
    }while(c!='\n' && c!=EOF);
    return;
}