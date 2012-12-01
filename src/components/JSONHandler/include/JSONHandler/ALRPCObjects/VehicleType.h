#ifndef NSAPPLINKRPC_VEHICLETYPE_INCLUDE
#define NSAPPLINKRPC_VEHICLETYPE_INCLUDE

#include <string>



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

  class VehicleType
  {
  public:
  
    VehicleType(const VehicleType& c);
    VehicleType(void);
  
    bool checkIntegrity(void);
  
    ~VehicleType(void);
    VehicleType& operator =(const VehicleType&);

// getters

    const std::string* get_make(void) const;
    const std::string* get_model(void) const;
    const std::string* get_modelYear(void) const;
    const std::string* get_trim(void) const;

// setters

    void reset_make(void);
    bool set_make(const std::string& make_);
    void reset_model(void);
    bool set_model(const std::string& model_);
    void reset_modelYear(void);
    bool set_modelYear(const std::string& modelYear_);
    void reset_trim(void);
    bool set_trim(const std::string& trim_);

  private:

    friend class VehicleTypeMarshaller;


/**
     Make of the vehicle
     e.g. Ford
*/
      std::string* make;	//!< (500)

/**
     Model of the vehicle
     e.g. Fiesta
*/
      std::string* model;	//!< (500)

/**
     Model Year of the vehicle
     e.g. 2013
*/
      std::string* modelYear;	//!< (500)

/**
     Trim of the vehicle
     e.g. SE
*/
      std::string* trim;	//!< (500)
  };

}

#endif
