/**
 * Copyright (C) 2020 Xilinx, Inc
 *
 * Licensed under the Apache License, Version 2.0 (the "License"). You may
 * not use this file except in compliance with the License. A copy of the
 * License is located at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

#ifndef _XDP_PROFILE_DEVICE_BASE_TRACE_LOGGER_H
#define _XDP_PROFILE_DEVICE_BASE_TRACE_LOGGER_H

#include "core/include/xclperf.h"
#include <vector>

namespace xdp {

// Interface class
class DeviceTraceLogger
{
public:
  DeviceTraceLogger() {}
  virtual ~DeviceTraceLogger() {}

  virtual void processTraceData(std::vector<xclTraceResults>& traceVector) = 0;
  virtual void endProcessTraceData(std::vector<xclTraceResults>& traceVector) = 0;
};

}
#endif
