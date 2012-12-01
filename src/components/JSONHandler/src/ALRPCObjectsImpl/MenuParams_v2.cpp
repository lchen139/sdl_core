#include "../include/JSONHandler/ALRPCObjects/MenuParams_v2.h"
#include "MenuParams_v2Marshaller.h"

/*
  interface	Ford Sync RAPI
  version	1.2 / 2.0O
  date		2011-05-17 / 2012-11-02
  generated at	Thu Nov 29 14:49:08 2012
  source stamp	Thu Nov 29 06:50:10 2012
  author	robok0der
*/



using namespace NsAppLinkRPC;

MenuParams_v2& MenuParams_v2::operator =(const MenuParams_v2& c)
{
  menuName=c.menuName;
  parentID=c.parentID ? new unsigned int(c.parentID[0]) : 0;
  position=c.position ? new unsigned int(c.position[0]) : 0;

  return *this;
}


MenuParams_v2::~MenuParams_v2(void)
{
  if(parentID)
    delete parentID;
  if(position)
    delete position;
}


MenuParams_v2::MenuParams_v2(const MenuParams_v2& c)
{
  *this=c;
}


bool MenuParams_v2::checkIntegrity(void)
{
  return MenuParams_v2Marshaller::checkIntegrity(*this);
}


MenuParams_v2::MenuParams_v2(void) :
    parentID(0),
    position(0)
{
}



bool MenuParams_v2::set_menuName(const std::string& menuName_)
{
  if(menuName_.length()>500)  return false;
  menuName=menuName_;
  return true;
}

bool MenuParams_v2::set_parentID(unsigned int parentID_)
{
  if(parentID_>2000000000)  return false;
  delete parentID;
  parentID=0;

  parentID=new unsigned int(parentID_);
  return true;
}

void MenuParams_v2::reset_parentID(void)
{
  if(parentID)
    delete parentID;
  parentID=0;
}

bool MenuParams_v2::set_position(unsigned int position_)
{
  if(position_>1000)  return false;
  delete position;
  position=0;

  position=new unsigned int(position_);
  return true;
}

void MenuParams_v2::reset_position(void)
{
  if(position)
    delete position;
  position=0;
}




const std::string& MenuParams_v2::get_menuName(void) const 
{
  return menuName;
}


const unsigned int* MenuParams_v2::get_parentID(void) const 
{
  return parentID;
}


const unsigned int* MenuParams_v2::get_position(void) const 
{
  return position;
}


