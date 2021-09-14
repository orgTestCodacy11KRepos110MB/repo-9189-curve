/*
 *  Copyright (c) 2021 NetEase Inc.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

/*
 * Project: curve
 * Created Date: 2021-05-19
 * Author: chenwei
 */

#ifndef CURVEFS_SRC_METASERVER_METASERVER_H_
#define CURVEFS_SRC_METASERVER_METASERVER_H_

#include <brpc/server.h>

#include <memory>
#include <string>

#include "curvefs/src/metaserver/copyset/apply_queue.h"
#include "curvefs/src/metaserver/copyset/config.h"
#include "curvefs/src/metaserver/copyset/copyset_node_manager.h"
#include "curvefs/src/metaserver/copyset/copyset_service.h"
#include "curvefs/src/metaserver/copyset/trash.h"
#include "curvefs/src/metaserver/inflight_throttle.h"
#include "curvefs/src/metaserver/metaserver_service.h"
#include "src/common/configuration.h"
#include "src/fs/local_filesystem.h"

namespace curvefs {
namespace metaserver {

using ::curve::common::Configuration;
using ::curvefs::metaserver::copyset::ApplyQueue;
using ::curvefs::metaserver::copyset::CopysetNodeManager;
using ::curvefs::metaserver::copyset::CopysetNodeOptions;
using ::curvefs::metaserver::copyset::CopysetServiceImpl;
using ::curvefs::metaserver::copyset::CopysetTrash;

struct MetaserverOptions {
    std::string ip;
    int port;
    int bthreadWorkerCount = -1;
};

class Metaserver {
 public:
    void InitOptions(std::shared_ptr<Configuration> conf);
    void Init();
    void Run();
    void Stop();

 private:
    void InitCopysetNodeOptions();
    void InitCopysetNodeManager();
    void InitCopysetTrash();
    void InitLocalFileSystem();
    void InitInflightThrottle();

 private:
    // metaserver configuration items
    std::shared_ptr<Configuration> conf_;
    // initialized or not
    bool inited_ = false;
    // running as the main MDS or not
    bool running_ = false;

    std::shared_ptr<S3ClientAdaptor>  s3Adaptor_;
    std::shared_ptr<Trash> trash_;

    MetaserverOptions options_;

    std::unique_ptr<brpc::Server> server_;
    std::unique_ptr<MetaServerServiceImpl> metaService_;
    std::unique_ptr<CopysetServiceImpl> copysetService_;

    CopysetNodeOptions copysetNodeOptions_;
    CopysetNodeManager* copysetNodeManager_;

    std::unique_ptr<InflightThrottle> inflightThrottle_;
    std::unique_ptr<CopysetTrash> copysetTrash_;
    std::shared_ptr<curve::fs::LocalFileSystem> localFileSystem_;
};
}  // namespace metaserver
}  // namespace curvefs

#endif  // CURVEFS_SRC_METASERVER_METASERVER_H_