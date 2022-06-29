/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef OHOS_DM_HIDUMPER_H
#define OHOS_DM_HIDUMPER_H

#include <cstdint>
#include <set>
#include <string>
#include <vector>

#include "dm_constants.h"
#include "dm_dfx_constants.h"
#include "single_instance.h"
#include "dm_log.h"
#include "dm_device_info.h"

namespace OHOS {
namespace DistributedHardware {
class HidumpHelper {
DECLARE_SINGLE_INSTANCE(HidumpHelper);
public:
    int32_t HiDump(const std::vector<std::string>& args, std::string &result);
    int32_t GetArgsType(const std::vector<std::string>& args, std::vector<HidumperFlag> &Flag);
    void SetNodeInfo(const DmDeviceInfo& deviceInfo, const bool deviceStates);

private:
    int32_t ProcessDump(const HidumperFlag &flag, std::string &result);
    int32_t ShowAllLoadTrustedList(std::string &result);
    int32_t ShowHelp(std::string &result);
    int32_t ShowIllealInfomation(std::string &result);

private:
    std::vector<DmDeviceInfo> nodeInfos_;
    std::vector<std::string> deviceState_;
};
} // namespace DistributedHardware
} // namespace OHOS
#endif // OHOS_DM_HIDUMPER_H
