/**
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (C) 2019-2021 Xilinx, Inc. All rights reserved.
 */

#ifndef _XRT_VERSION_H_
#define _XRT_VERSION_H_

static const char xrt_build_version[] = "2.12.0";

static const char xrt_build_version_branch[] = "2021.2";

static const char xrt_build_version_hash[] = "2719b6027e185000fc49783171631db03fc0ef79";

static const char xrt_build_version_hash_date[] = "Fri, 8 Oct 2021 21:14:02 -0700";

static const char xrt_build_version_date_rfc[] = "Thu, 14 Oct 2021 09:10:18 +0000";

static const char xrt_build_version_date[] = "2021-10-09 04:14:02";

static const char xrt_modified_files[] = "";

#define XRT_DRIVER_VERSION "2.12.0,2719b6027e185000fc49783171631db03fc0ef79"

#define XRT_VERSION(major, minor) ((major << 16) + (minor))
#define XRT_VERSION_CODE XRT_VERSION(2, 12)
#define XRT_MAJOR(code) ((code >> 16))
#define XRT_MINOR(code) (code - ((code >> 16) << 16))

# ifdef __cplusplus
#include <iostream>
#include <string>

namespace xrt {

class version {
 public:
  static void print(std::ostream & output)
  {
     output << "       XRT Build Version: " << xrt_build_version << std::endl;
     output << "    Build Version Branch: " << xrt_build_version_branch << std::endl;
     output << "      Build Version Hash: " << xrt_build_version_hash << std::endl;
     output << " Build Version Hash Date: " << xrt_build_version_hash_date << std::endl;
     output << "      Build Version Date: " << xrt_build_version_date_rfc << std::endl;

     std::string modifiedFiles(xrt_modified_files);
     if ( !modifiedFiles.empty() ) {
        const std::string& delimiters = ",";      // Our delimiter
        std::string::size_type lastPos = 0;
        int runningIndex = 1;
        while(lastPos < modifiedFiles.length() + 1) {
          if (runningIndex == 1) {
             output << "  Current Modified Files: ";
          } else {
             output << "                          ";
          }
          output << runningIndex++ << ") ";

          std::string::size_type pos = modifiedFiles.find_first_of(delimiters, lastPos);

          if (pos == std::string::npos) {
            pos = modifiedFiles.length();
          }

          output << modifiedFiles.substr(lastPos, pos-lastPos) << std::endl;

          lastPos = pos + 1;
        }
     }
  }
};
}
#endif

#endif
