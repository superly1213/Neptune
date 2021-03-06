// Copyright (c) 2017 ASMlover. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
//  * Redistributions of source code must retain the above copyright
//    notice, this list ofconditions and the following disclaimer.
//
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in
//    the documentation and/or other materialsprovided with the
//    distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
// COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
// ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
#ifndef NEPTUNE_CALLBACKS_H
#define NEPTUNE_CALLBACKS_H

#include <functional>
#include <memory>
#include <Chaos/Datetime/Timestamp.h>

namespace Neptune {

class Buffer;
class TcpConnection;

using TcpConnectionPtr      = std::shared_ptr<TcpConnection>;
using TimerCallback         = std::function<void (void)>;
using ConnectionCallback    = std::function<void (const TcpConnectionPtr&)>;
using CloseCallback         = std::function<void (const TcpConnectionPtr&)>;
using WriteCompleteCallback = std::function<void (const TcpConnectionPtr&)>;
using HighWaterMarkCallback =
  std::function<void (const TcpConnectionPtr&, std::size_t)>;
using MessageCallback       =
  std::function<void (const TcpConnectionPtr&, Buffer*, Chaos::Timestamp)>;

void on_connection_default(const TcpConnectionPtr& conn);
void on_message_default(
    const TcpConnectionPtr& conn, Buffer* buff, Chaos::Timestamp recvtime);

}

#endif // NEPTUNE_CALLBACKS_H
