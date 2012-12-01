#include "../src/../include/JSONHandler/RPC2Objects/NsRPC2Communication/UI/CreateInteractionChoiceSetResponse.h"
#include "../src/../include/JSONHandler/RPC2Objects/Marshaller.h"

/*
  interface	NsRPC2Communication::UI
  version	1.2
  generated at	Thu Nov 29 14:32:09 2012
  source stamp	Thu Nov 29 14:32:05 2012
  author	robok0der
*/

using namespace NsRPC2Communication::UI;


CreateInteractionChoiceSetResponse& CreateInteractionChoiceSetResponse::operator =(const CreateInteractionChoiceSetResponse& c)
{
  return *this;
}


CreateInteractionChoiceSetResponse::~CreateInteractionChoiceSetResponse(void)
{
}


CreateInteractionChoiceSetResponse::CreateInteractionChoiceSetResponse(void) : 
  RPC2Response(Marshaller::METHOD_NSRPC2COMMUNICATION_UI__CREATEINTERACTIONCHOICESETRESPONSE)
{
}


CreateInteractionChoiceSetResponse::CreateInteractionChoiceSetResponse(const CreateInteractionChoiceSetResponse& c) : RPC2Response(Marshaller::METHOD_NSRPC2COMMUNICATION_UI__CREATEINTERACTIONCHOICESETRESPONSE,c.getId(),c.getResult())
{
  *this=c;
}


bool CreateInteractionChoiceSetResponse::checkIntegrity(void)
{
  return CreateInteractionChoiceSetResponseMarshaller::checkIntegrity(*this);
}
