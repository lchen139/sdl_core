#include "../include/JSONHandler/ALRPCObjects/DTC.h"


#include "DTCMarshaller.h"


/*
  interface	Ford Sync RAPI
  version	1.2 / 2.0O
  date		2011-05-17 / 2012-11-02
  generated at	Thu Nov 29 14:49:08 2012
  source stamp	Thu Nov 29 06:50:10 2012
  author	robok0der
*/

using namespace NsAppLinkRPC;


bool DTCMarshaller::checkIntegrity(DTC& s)
{
  return checkIntegrityConst(s);
}


bool DTCMarshaller::fromString(const std::string& s,DTC& e)
{
  try
  {
    Json::Reader reader;
    Json::Value json;
    if(!reader.parse(s,json,false))  return false;
    if(!fromJSON(json,e))  return false;
  }
  catch(...)
  {
    return false;
  }
  return true;
}


const std::string DTCMarshaller::toString(const DTC& e)
{
  Json::FastWriter writer;
  return checkIntegrityConst(e) ? writer.write(toJSON(e)) : "";
}


bool DTCMarshaller::checkIntegrityConst(const DTC& s)
{
  if(s.identifier.length()>500)  return false;
  if(s.statusByte.length()>500)  return false;
  return true;
}

Json::Value DTCMarshaller::toJSON(const DTC& e)
{
  Json::Value json(Json::objectValue);
  if(!checkIntegrityConst(e))
    return Json::Value(Json::nullValue);

  json["identifier"]=Json::Value(e.identifier);

  json["statusByte"]=Json::Value(e.statusByte);


  return json;
}


bool DTCMarshaller::fromJSON(const Json::Value& json,DTC& c)
{
  try
  {
    if(!json.isObject())  return false;

    if(!json.isMember("identifier"))  return false;
    {
      const Json::Value& j=json["identifier"];
      if(!j.isString())  return false;
      c.identifier=j.asString();
    }
    if(!json.isMember("statusByte"))  return false;
    {
      const Json::Value& j=json["statusByte"];
      if(!j.isString())  return false;
      c.statusByte=j.asString();
    }

  }
  catch(...)
  {
    return false;
  }
  return checkIntegrity(c);
}

