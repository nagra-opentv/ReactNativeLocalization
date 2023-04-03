/*
 * Copyright (C) 1994-2022 OpenTV, Inc. and Nagravision S.A.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <unicode/uloc.h>

#include "ReactSkia/utils/RnsLog.h"
#include <cxxreact/JsArgumentHelpers.h>

#include "ReactLocalizationModule.h"

namespace facebook {
namespace xplat {

ReactLocalizationModule::ReactLocalizationModule() { }

auto ReactLocalizationModule::getConstants() -> std::map<std::string, folly::dynamic> {
  return {
    {"language", getCurrentLanguage()}
  };
}

std::string ReactLocalizationModule::getName() {
  return "ReactLocalization";
}

auto ReactLocalizationModule::getMethods() -> std::vector<Method> {
  return {
    Method(
      "getLanguage",
      [this](folly::dynamic args, Callback cb) {
        cb({nullptr, getCurrentLanguage()});
      }
    ),
  };
}

std::string ReactLocalizationModule::getCurrentLanguage() {
  std::string language(uloc_getDefault());
  RNS_LOG_TRACE("The Current ICU Language IS : " << language);
  return language;
}

#ifdef __cplusplus
extern "C" {
#endif
RNS_EXPORT_MODULE(ReactLocalization)
#ifdef __cplusplus
}
#endif

} // xplat
} // facebook
