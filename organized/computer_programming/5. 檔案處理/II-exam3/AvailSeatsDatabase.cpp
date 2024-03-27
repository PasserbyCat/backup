#include <iostream>
#include <fstream>
using namespace::std;

#include "AvailSeatsDatabase.h"

AvailSeatsDatabase::AvailSeatsDatabase()
{

}

AvailSeatsDatabase::~AvailSeatsDatabase()
{
   storeAvailSeats();
}

void AvailSeatsDatabase::decreaseAvailSeats( Date date, int timeCode, int requiredSeats )
{

}

bool AvailSeatsDatabase::availableTimes( Date date, int requiredSeats )
{

}

bool AvailSeatsDatabase::availableTimes( Date date, int timeCode, int requiredSeats )
{

}

vector< AvailSeats >::iterator AvailSeatsDatabase::searchAvailSeats( Date date )
{

}

void AvailSeatsDatabase::loadAvailSeats()
{

}

void AvailSeatsDatabase::storeAvailSeats()
{

}