// SPDX-License-Identifier: Apache-2.0
// Copyright (C) 2021 Xilinx, Inc. All rights reserved.

#ifndef XRT_DETAIL_ABI_H
#define XRT_DETAIL_ABI_H

#include "version.h"

#ifdef __cplusplus

namespace xrt { namespace detail {

// Capture version of XRT at compile time.
//
// An object of this struct can be passed to implementation code by
// inline APIs. The implementation code will continue to see the
// version of XRT used when the binary was compiled even with later
// versions of XRT installed.
//
// The struct is used to guarantee schema compability between old
// version of XRT and new version.
struct abi {
  const unsigned int major {XRT_MAJOR(XRT_VERSION_CODE)};
  const unsigned int minor {XRT_MINOR(XRT_VERSION_CODE)};
  const unsigned int code  {XRT_VERSION_CODE};
};

}} // detail, xrt

#endif

#endif
