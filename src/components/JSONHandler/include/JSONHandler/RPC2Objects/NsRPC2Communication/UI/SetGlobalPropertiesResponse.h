#ifndef NSRPC2COMMUNICATION_UI_SETGLOBALPROPERTIESRESPONSE_INCLUDE
#define NSRPC2COMMUNICATION_UI_SETGLOBALPROPERTIESRESPONSE_INCLUDE

#include "JSONHandler/RPC2Response.h"


/*
  interface	NsRPC2Communication::UI
  version	1.2
  generated at	Thu Nov 29 14:32:09 2012
  source stamp	Thu Nov 29 14:32:05 2012
  author	robok0der
*/

namespace NsRPC2Communication
{
  namespace UI
  {

    class SetGlobalPropertiesResponse : public ::NsRPC2Communication::RPC2Response
    {
    public:
    
      SetGlobalPropertiesResponse(const SetGlobalPropertiesResponse& c);
      SetGlobalPropertiesResponse(void);
    
      SetGlobalPropertiesResponse& operator =(const SetGlobalPropertiesResponse&);
    
      virtual ~SetGlobalPropertiesResponse(void);
    
      bool checkIntegrity(void);
    

    private:

      friend class SetGlobalPropertiesResponseMarshaller;


    };
  }
}

#endif
