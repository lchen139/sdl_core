#ifndef NSAPPLINKRPC_CREATEINTERACTIONCHOICESET_V2_REQUEST_INCLUDE
#define NSAPPLINKRPC_CREATEINTERACTIONCHOICESET_V2_REQUEST_INCLUDE

#include <vector>

#include "Choice.h"
#include "JSONHandler/ALRPCRequest.h"


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

///  creates interaction choice set to be used later by performInteraction

  class CreateInteractionChoiceSet_v2_request : public ALRPCRequest
  {
  public:
  
    CreateInteractionChoiceSet_v2_request(const CreateInteractionChoiceSet_v2_request& c);
    CreateInteractionChoiceSet_v2_request(void);
    
    virtual ~CreateInteractionChoiceSet_v2_request(void);
  
    bool checkIntegrity(void);

    unsigned int get_interactionChoiceSetID(void) const;
    const std::vector<Choice>& get_choiceSet(void) const;

    bool set_interactionChoiceSetID(unsigned int interactionChoiceSetID_);
    bool set_choiceSet(const std::vector<Choice>& choiceSet_);

  private:
  
    friend class CreateInteractionChoiceSet_v2_requestMarshaller;


///  Unique ID used for this interaction choice set.
      unsigned int interactionChoiceSetID;	//!<  (0,2000000000)
      std::vector<Choice> choiceSet;	//!<   [%s..%s] 
  };

}

#endif
