/*
 * Copyright (c) 2014, Ford Motor Company
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following
 * disclaimer in the documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of the Ford Motor Company nor the names of its contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SRC_COMPONENTS_TRANSPORT_MANAGER_INCLUDE_TRANSPORT_MANAGER_MME_IAP_CONNECTION_H_
#define SRC_COMPONENTS_TRANSPORT_MANAGER_INCLUDE_TRANSPORT_MANAGER_MME_IAP_CONNECTION_H_

#include <ipod/ipod.h>

#include "utils/threads/thread.h"
#include "utils/threads/pulse_thread_delegate.h"

#include "transport_manager/transport_adapter/connection.h"
#include "transport_manager/transport_adapter/transport_adapter_controller.h"

namespace transport_manager {
namespace transport_adapter {

class IAPConnection : public Connection {
 public:
  IAPConnection(const DeviceUID& device_uid,
    const ApplicationHandle& app_handle,
    TransportAdapterController* controller,
    const char* device_path);

  ~IAPConnection();

  bool Init();

 protected:
  virtual TransportAdapter::Error SendData(RawMessageSptr message);
  virtual TransportAdapter::Error Disconnect();

 private:
  void OnDataReceived(RawMessageSptr message);
  void OnReceiveFailed();
  void OnSessionOpened(int session_id);
  void OnSessionClosed();

  DeviceUID device_uid_;
  ApplicationHandle app_handle_;
  TransportAdapterController* controller_;
  std::string device_path_;

  ipod_hdl_t* ipod_hdl_;
  int session_id_;

  utils::SharedPtr<threads::Thread> receiver_thread_;

  class ReceiverThreadDelegate : public threads::PulseThreadDelegate {
   public:
    ReceiverThreadDelegate(ipod_hdl_t* ipod_hdl, IAPConnection* parent);

   protected:
    virtual bool ArmEvent(struct sigevent* event);
    virtual void OnPulse();

   private:
    static const size_t kBufferSize = 1024;
    static const size_t kEventsBufferSize = 32;
    static const int kProtocolNameSize = 256;

    void ParseEvents();
    void AcceptSession(uint32_t protocol_id);
    void CloseSession(uint32_t session_id);
    void ReceiveData(uint32_t session_id);
    void OpenSession(uint32_t protocol_id);

    IAPConnection* parent_;
    ipod_hdl_t* ipod_hdl_;
    int session_id_;
    uint8_t buffer_[kBufferSize];
    ipod_eaf_event_t events_[kEventsBufferSize];
    char protocol_name_[kProtocolNameSize];
  };
};

}  // namespace transport_adapter
}  // namespace transport_manager

#endif  //  SRC_COMPONENTS_TRANSPORT_MANAGER_INCLUDE_TRANSPORT_MANAGER_MME_IAP_CONNECTION_H_