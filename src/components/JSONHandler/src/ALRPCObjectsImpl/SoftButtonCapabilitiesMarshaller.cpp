#include "../include/JSONHandler/ALRPCObjects/SoftButtonCapabilities.h"


#include "SoftButtonCapabilitiesMarshaller.h"


/*
  interface	Ford Sync RAPI
  version	1.2 / 2.0O
  date		2011-05-17 / 2012-11-02
  generated at	Thu Nov 29 14:49:08 2012
  source stamp	Thu Nov 29 06:50:10 2012
  author	robok0der
*/

using namespace NsAppLinkRPC;


bool SoftButtonCapabilitiesMarshaller::checkIntegrity(SoftButtonCapabilities& s)
{
  return checkIntegrityConst(s);
}


bool SoftButtonCapabilitiesMarshaller::fromString(const std::string& s,SoftButtonCapabilities& e)
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


const std::string SoftButtonCapabilitiesMarshaller::toString(const SoftButtonCapabilities& e)
{
  Json::FastWriter writer;
  return checkIntegrityConst(e) ? writer.write(toJSON(e)) : "";
}


bool SoftButtonCapabilitiesMarshaller::checkIntegrityConst(const SoftButtonCapabilities& s)
{
  return true;
}

Json::Value SoftButtonCapabilitiesMarshaller::toJSON(const SoftButtonCapabilities& e)
{
  Json::Value json(Json::objectValue);
  if(!checkIntegrityConst(e))
    return Json::Value(Json::nullValue);

  json["imageSupported"]=Json::Value(e.imageSupported);

  json["longPressAvailable"]=Json::Value(e.longPressAvailable);

  json["shortPressAvailable"]=Json::Value(e.shortPressAvailable);

  json["upDownAvailable"]=Json::Value(e.upDownAvailable);


  return json;
}


bool SoftButtonCapabilitiesMarshaller::fromJSON(const Json::Value& json,SoftButtonCapabilities& c)
{
  try
  {
    if(!json.isObject())  return false;

    if(!json.isMember("imageSupported"))  return false;
    {
      const Json::Value& j=json["imageSupported"];
      if(!j.isBool())  return false;
      c.imageSupported=j.asBool();
    }
    if(!json.isMember("longPressAvailable"))  return false;
    {
      const Json::Value& j=json["longPressAvailable"];
      if(!j.isBool())  return false;
      c.longPressAvailable=j.asBool();
    }
    if(!json.isMember("shortPressAvailable"))  return false;
    {
      const Json::Value& j=json["shortPressAvailable"];
      if(!j.isBool())  return false;
      c.shortPressAvailable=j.asBool();
    }
    if(!json.isMember("upDownAvailable"))  return false;
    {
      const Json::Value& j=json["upDownAvailable"];
      if(!j.isBool())  return false;
      c.upDownAvailable=j.asBool();
    }

  }
  catch(...)
  {
    return false;
  }
  return checkIntegrity(c);
}

