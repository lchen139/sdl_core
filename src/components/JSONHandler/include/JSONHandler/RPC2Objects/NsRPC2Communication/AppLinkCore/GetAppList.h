#ifndef NSRPC2COMMUNICATION_APPLINKCORE_GETAPPLIST_INCLUDE
#define NSRPC2COMMUNICATION_APPLINKCORE_GETAPPLIST_INCLUDE

#include "JSONHandler/RPC2Request.h"


/*
  interface	NsRPC2Communication::AppLinkCore
  version	1.2
  generated at	Thu Nov 29 14:32:09 2012
  source stamp	Thu Nov 29 14:32:05 2012
  author	robok0der
*/

namespace NsRPC2Communication
{
  namespace AppLinkCore
  {

    class GetAppList : public ::NsRPC2Communication::RPC2Request
    {
    public:
    
      GetAppList(const GetAppList& c);
      GetAppList(void);
    
      GetAppList& operator =(const GetAppList&);
    
      virtual ~GetAppList(void);
    
      bool checkIntegrity(void);
    

    private:

      friend class GetAppListMarshaller;


    };
  }
}

#endif
