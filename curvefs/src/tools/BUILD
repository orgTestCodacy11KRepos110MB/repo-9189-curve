#
#  Copyright (c) 2020 NetEase Inc.
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
    "GCC_TEST_FLAGS"
)

cc_library(
        name = "curvefs_topology_tool_lib",
        srcs = ["curvefs_topology_tool.cpp",
                "curvefs_topology_tool.h"],
        visibility = ["//visibility:public"],
        deps = ["//curvefs/proto:curvefs_topology_cc_proto",
                "//curvefs/src/mds/common:fs_mds_common",
                "//external:gflags",
                "//external:json",
                "//src/common:curve_common",
                "//external:glog",
                "//external:brpc"]
)

cc_binary(
        name = "curvefs_topology_tool",
        srcs = glob(["main.cpp"]),
        copts = GCC_FLAGS,
        visibility = ["//visibility:public"],
        deps = [
                "//curvefs/src/tools:curvefs_topology_tool_lib",
        ],
)