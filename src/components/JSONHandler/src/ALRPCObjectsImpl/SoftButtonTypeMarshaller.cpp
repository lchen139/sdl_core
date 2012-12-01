#include <cstring>
#include "../include/JSONHandler/ALRPCObjects/SoftButtonType.h"
#include "SoftButtonTypeMarshaller.h"
#include "SoftButtonTypeMarshaller.inc"


/*
  interface	Ford Sync RAPI
  version	1.2 / 2.0O
  date		2011-05-17 / 2012-11-02
  generated at	Thu Nov 29 14:49:08 2012
  source stamp	Thu Nov 29 06:50:10 2012
  author	robok0der
*/

using namespace NsAppLinkRPC;


const SoftButtonType::SoftButtonTypeInternal SoftButtonTypeMarshaller::getIndex(const char* s)
{
  if(!s)
    return SoftButtonType::INVALID_ENUM;
  const struct PerfectHashTable* p=SoftButtonType_intHash::getPointer(s,strlen(s));
  return p ? static_cast<SoftButtonType::SoftButtonTypeInternal>(p->idx) : SoftButtonType::INVALID_ENUM;
}


bool SoftButtonTypeMarshaller::fromJSON(const Json::Value& s,SoftButtonType& e)
{
  e.mInternal=SoftButtonType::INVALID_ENUM;
  if(!s.isString())
    return false;

  e.mInternal=getIndex(s.asString().c_str());
  return (e.mInternal!=SoftButtonType::INVALID_ENUM);
}


Json::Value SoftButtonTypeMarshaller::toJSON(const SoftButtonType& e)
{
  if(e.mInternal==SoftButtonType::INVALID_ENUM) 
    return Json::Value(Json::nullValue);
  const char* s=getName(e.mInternal);
  return s ? Json::Value(s) : Json::Value(Json::nullValue);
}


bool SoftButtonTypeMarshaller::fromString(const std::string& s,SoftButtonType& e)
{
  e.mInternal=SoftButtonType::INVALID_ENUM;
  try
  {
    Json::Reader reader;
    Json::Value json;
    if(!reader.parse(s,json,false))  return false;
    if(fromJSON(json,e))  return true;
  }
  catch(...)
  {
    return false;
  }
  return false;
}

const std::string SoftButtonTypeMarshaller::toString(const SoftButtonType& e)
{
  Json::FastWriter writer;
  return e.mInternal==SoftButtonType::INVALID_ENUM ? "" : writer.write(toJSON(e));

}

const PerfectHashTable SoftButtonTypeMarshaller::mHashTable[3]=
{
  {"TEXT",0},
  {"IMAGE",1},
  {"BOTH",2}
};
