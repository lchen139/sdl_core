#ifndef NSRPC2COMMUNICATION_UI_ONDEVICELISTUPDATEDMARSHALLER_INCLUDE
#define NSRPC2COMMUNICATION_UI_ONDEVICELISTUPDATEDMARSHALLER_INCLUDE

#include <string>
#include <json/json.h>

#include "../src/../include/JSONHandler/RPC2Objects/NsRPC2Communication/UI/OnDeviceListUpdated.h"

namespace NsRPC2Communication
{
  namespace UI
  {

    struct OnDeviceListUpdatedMarshaller
    {
      static bool checkIntegrity(OnDeviceListUpdated& e);
      static bool checkIntegrityConst(const OnDeviceListUpdated& e);
    
      static bool fromString(const std::string& s,OnDeviceListUpdated& e);
      static const std::string toString(const OnDeviceListUpdated& e);
    
      static bool fromJSON(const Json::Value& s,OnDeviceListUpdated& e);
      static Json::Value toJSON(const OnDeviceListUpdated& e);
    };
  }
}

#endif
