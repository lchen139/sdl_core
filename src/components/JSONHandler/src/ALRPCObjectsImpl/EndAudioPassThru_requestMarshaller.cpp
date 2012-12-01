#include "../include/JSONHandler/ALRPCObjects/EndAudioPassThru_request.h"


#include "EndAudioPassThru_requestMarshaller.h"


/*
  interface	Ford Sync RAPI
  version	1.2 / 2.0O
  date		2011-05-17 / 2012-11-02
  generated at	Thu Nov 29 14:49:08 2012
  source stamp	Thu Nov 29 06:50:10 2012
  author	robok0der
*/

using namespace NsAppLinkRPC;


bool EndAudioPassThru_requestMarshaller::checkIntegrity(EndAudioPassThru_request& s)
{
  return checkIntegrityConst(s);
}


bool EndAudioPassThru_requestMarshaller::fromString(const std::string& s,EndAudioPassThru_request& e)
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


const std::string EndAudioPassThru_requestMarshaller::toString(const EndAudioPassThru_request& e)
{
  Json::FastWriter writer;
  return checkIntegrityConst(e) ? writer.write(toJSON(e)) : "";
}


bool EndAudioPassThru_requestMarshaller::checkIntegrityConst(const EndAudioPassThru_request& s)
{
  return true;
}

Json::Value EndAudioPassThru_requestMarshaller::toJSON(const EndAudioPassThru_request& e)
{
  Json::Value json(Json::objectValue);
  if(!checkIntegrityConst(e))
    return Json::Value(Json::nullValue);

  json["request"]=Json::Value(Json::objectValue);
  json["request"]["name"]=Json::Value("EndAudioPassThru");
  json["request"]["correlationID"]=Json::Value(e.getCorrelationID());

  Json::Value j=Json::Value(Json::objectValue);

  json["request"]["parameters"]=j;
  return json;
}


bool EndAudioPassThru_requestMarshaller::fromJSON(const Json::Value& js,EndAudioPassThru_request& c)
{
  try
  {
    if(!js.isObject())  return false;

    if(!js.isMember("request"))  return false;

    if(!js["request"].isObject())  return false;
    const Json::Value& j2=js["request"];

    if(!j2.isMember("name") || !j2["name"].isString() || j2["name"].asString().compare("EndAudioPassThru"))  return false;
    if(!j2.isMember("correlationID") || !j2["correlationID"].isInt())  return false;
    c.setCorrelationID(j2["correlationID"].asInt());

    if(!j2.isMember("parameters"))  return false;
    const Json::Value& json=j2["parameters"];
    if(!json.isObject())  return false;

  }
  catch(...)
  {
    return false;
  }
  return checkIntegrity(c);
}

