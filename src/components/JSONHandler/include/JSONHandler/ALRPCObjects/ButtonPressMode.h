#ifndef NSAPPLINKRPC_BUTTONPRESSMODE_INCLUDE
#define NSAPPLINKRPC_BUTTONPRESSMODE_INCLUDE


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

  class ButtonPressMode
  {
  public:
    enum ButtonPressModeInternal
    {
      INVALID_ENUM=-1,

/**
     A button was released, after it was pressed for a long time
     Actual timing is defined by Sync and may vary
*/
      LONG=0,

/**
     A button was released, after it was pressed for a short time
     Actual timing is defined by Sync and may vary
*/
      SHORT=1
    };
  
    ButtonPressMode() : mInternal(INVALID_ENUM)				{}
    ButtonPressMode(ButtonPressModeInternal e) : mInternal(e)		{}
  
    ButtonPressModeInternal get(void) const	{ return mInternal; }
    void set(ButtonPressModeInternal e)		{ mInternal=e; }
  
  private:
    ButtonPressModeInternal mInternal;
    friend class ButtonPressModeMarshaller;
  };
  
}

#endif
