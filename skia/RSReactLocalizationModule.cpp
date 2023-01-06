/*
 * Copyright (C) 1994-2022 OpenTV, Inc. and Nagravision S.A.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <unicode/uloc.h>

#include "ReactSkia/utils/RnsLog.h"
#include <cxxreact/JsArgumentHelpers.h>

#include "RSReactLocalizationModule.h"

using namespace folly;
namespace facebook {
namespace xplat {

RSReactLocalizationModule::RSReactLocalizationModule() { }

auto RSReactLocalizationModule::getConstants() -> std::map<std::string, folly::dynamic> {
  return {
    {"language", getCurrentLanguage()}
  };
}

std::string RSReactLocalizationModule::getName() {
  return "ReactLocalization";
}

auto RSReactLocalizationModule::getMethods() -> std::vector<Method> {
  return {
    Method(
      "getLanguage",
      [this](dynamic args, Callback cb) {
        cb({nullptr, getCurrentLanguage()});
      }
    ),
  };
}

std::string RSReactLocalizationModule::getCurrentLanguage() {
  std::string language(uloc_getDefault());
  RNS_LOG_TRACE("The Current ICU Language IS : " << language);
  return language;
}

#ifdef __cplusplus
extern "C" {
#endif
RNS_EXPORT_MODULE(RSReactLocalizationModule)
#ifdef __cplusplus
}
#endif

} // xplat
} // facebook
