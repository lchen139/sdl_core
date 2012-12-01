#include "../include/JSONHandler/ALRPCObjects/ReadDID_response.h"
#include "ReadDID_responseMarshaller.h"
#include "../include/JSONHandler/ALRPCObjects/Marshaller.h"
#include "Result_v2Marshaller.h"
#include "VehicleDataResultCodeMarshaller.h"

#define PROTOCOL_VERSION	42


/*
  interface	Ford Sync RAPI
  version	1.2 / 2.0O
  date		2011-05-17 / 2012-11-02
  generated at	Thu Nov 29 14:49:08 2012
  source stamp	Thu Nov 29 06:50:10 2012
  author	robok0der
*/

using namespace NsAppLinkRPC;
ReadDID_response& ReadDID_response::operator =(const ReadDID_response& c)
{
  success= c.success;
  resultCode= c.resultCode;
  info= c.info ? new std::string(c.info[0]) : 0;
  dataResult= c.dataResult ? new std::vector<VehicleDataResultCode>(c.dataResult[0]) : 0;
  data= c.data ? new std::vector<std::string>(c.data[0]) : 0;

  return *this;}


ReadDID_response::~ReadDID_response(void)
{
  if(info)
    delete info;
  if(dataResult)
    delete dataResult;
  if(data)
    delete data;
}


ReadDID_response::ReadDID_response(const ReadDID_response& c)
{
  *this=c;
}


bool ReadDID_response::checkIntegrity(void)
{
  return ReadDID_responseMarshaller::checkIntegrity(*this);
}


ReadDID_response::ReadDID_response(void) : ALRPCResponse(PROTOCOL_VERSION,Marshaller::METHOD_READDID_RESPONSE),
      info(0),
    dataResult(0),
    data(0)
{
}



bool ReadDID_response::set_success(bool success_)
{
  success=success_;
  return true;
}

bool ReadDID_response::set_resultCode(const std::vector<Result_v2>& resultCode_)
{
  unsigned int i=resultCode_.size();
  while(i--)
  {
    if(!Result_v2Marshaller::checkIntegrityConst(resultCode_[i]))   return false;
  }
  resultCode=resultCode_;
  return true;
}

bool ReadDID_response::set_info(const std::string& info_)
{
  if(info_.length()>1000)  return false;
  delete info;
  info=0;

  info=new std::string(info_);
  return true;
}

void ReadDID_response::reset_info(void)
{
  if(info)
    delete info;
  info=0;
}

bool ReadDID_response::set_dataResult(const std::vector<VehicleDataResultCode>& dataResult_)
{
  unsigned int i=dataResult_.size();
  if(i>1000 || i<0)  return false;
  while(i--)
  {
    if(!VehicleDataResultCodeMarshaller::checkIntegrityConst(dataResult_[i]))   return false;
  }
  delete dataResult;
  dataResult=0;

  dataResult=new std::vector<VehicleDataResultCode>(dataResult_);
  return true;
}

void ReadDID_response::reset_dataResult(void)
{
  if(dataResult)
    delete dataResult;
  dataResult=0;
}

bool ReadDID_response::set_data(const std::vector<std::string>& data_)
{
  unsigned int i=data_.size();
  if(i>1000 || i<0)  return false;
  while(i--)
  {
    if(data_[i].length()>5000)  return false;
  }
  delete data;
  data=0;

  data=new std::vector<std::string>(data_);
  return true;
}

void ReadDID_response::reset_data(void)
{
  if(data)
    delete data;
  data=0;
}




bool ReadDID_response::get_success(void) const
{
  return success;
}

const std::vector<Result_v2>& ReadDID_response::get_resultCode(void) const 
{
  return resultCode;
}

const std::string* ReadDID_response::get_info(void) const 
{
  return info;
}

const std::vector<VehicleDataResultCode>* ReadDID_response::get_dataResult(void) const 
{
  return dataResult;
}

const std::vector<std::string>* ReadDID_response::get_data(void) const 
{
  return data;
}

