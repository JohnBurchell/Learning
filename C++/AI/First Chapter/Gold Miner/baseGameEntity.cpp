#include "baseGameEntity.h"
#include <cassert>


int BaseGameEntity::nextValidId_ = 0;



//----------------------------- SetID -----------------------------------------
//
//  this must be called within each constructor to make sure the ID is set
//  correctly. It verifies that the value passed to the method is greater
//  or equal to the next valid ID, before setting the ID and incrementing
//  the next valid ID
//-----------------------------------------------------------------------------
void BaseGameEntity::setID(int val)
{
  //make sure the val is equal to or greater than the next available ID
  assert ( (val >= nextValidId_) && "<BaseGameEntity::SetID>: invalid ID");

  ID_ = val;
    
  nextValidId_ = ID_ + 1;
}