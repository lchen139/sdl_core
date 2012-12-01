#ifndef NSAPPLINKRPC_DELETEFILE_RESPONSE_INCLUDE
#define NSAPPLINKRPC_DELETEFILE_RESPONSE_INCLUDE

#include <string>

#include "Result_v2.h"
#include "JSONHandler/ALRPCResponse.h"


/*
  interface	Ford Sync RAPI
  version	1.2 / 2.0O
  date		2011-05-17 / 2012-11-02
  generated at	Thu Nov 29 14:49:08 2012
  source stamp	Thu Nov 29 06:50:10 2012
  author	robok0der
*/

namespace NsAppLinkRPC
{

/**
     Response is sent, when the file data was deleted (success case). Or when an error occured.
     Not supported on First generation SYNC vehicles. 
*/

  class DeleteFile_response : public ALRPCResponse
  {
  public:
  
    DeleteFile_response(const DeleteFile_response& c);
    DeleteFile_response(void);
    
    virtual ~DeleteFile_response(void);
  
    DeleteFile_response& operator =(const DeleteFile_response&);
  
    bool checkIntegrity(void);

    bool get_success(void) const;
    const Result_v2& get_resultCode(void) const;
    unsigned int get_spaceAvailable(void) const;
    const std::string* get_info(void) const;

    bool set_success(bool success_);
    bool set_resultCode(const Result_v2& resultCode_);
    bool set_spaceAvailable(unsigned int spaceAvailable_);
    void reset_info(void);
    bool set_info(const std::string& info_);

  private:
  
    friend class DeleteFile_responseMarshaller;


/**
     true, if successful
     false, if failed
*/
      bool success;

///  See Result
      Result_v2 resultCode;

///  Provides the total local space available on SYNC for the registered app.
      unsigned int spaceAvailable;	//!<  (0,2000000000)

///  Provides additional human readable info regarding the result.
      std::string* info;	//!< (1000)
  };

}

#endif
