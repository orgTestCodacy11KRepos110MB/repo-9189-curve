#
#  Copyright (c) 2021 NetEase Inc.
#
#  Licensed under the Apache License, Version 2.0 (the "License");
#  you may not use this file except in compliance with the License.
#  You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.
#

load(
    "//:copts.bzl",
    "GCC_FLAGS",
    "GCC_TEST_FLAGS",
)

cc_library(
    name = "rpcclient",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.h"]),
    copts = GCC_FLAGS,
    deps = [
        "//external:brpc",
        "//external:glog",
        "//external:gflags",
        "//curvefs/proto:mds_cc_proto",
        "//curvefs/proto:metaserver_cc_proto",
        "//curvefs/proto:space_cc_proto",
        "//curvefs/proto:cli2_cc_proto",
        "//curvefs/proto:curvefs_topology_cc_proto",
        "//curvefs/src/client/common:common",
        "//src/client:curve_client",
    ],
    visibility = ["//visibility:public"],
)