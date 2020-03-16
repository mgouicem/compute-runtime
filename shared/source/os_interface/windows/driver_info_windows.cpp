/*
 * Copyright (C) 2017-2020 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "shared/source/os_interface/windows/driver_info_windows.h"

#include "shared/source/os_interface/windows/debug_registry_reader.h"
#include "shared/source/os_interface/windows/os_interface.h"
#include "shared/source/os_interface/windows/wddm/wddm.h"

namespace NEO {

DriverInfoWindows::DriverInfoWindows(std::string &&fullPath) : path(DriverInfoWindows::trimRegistryKey(fullPath)) {}

DriverInfo *DriverInfo::create(OSInterface *osInterface) {
    if (osInterface) {
        auto wddm = osInterface->get()->getWddm();
        DEBUG_BREAK_IF(wddm == nullptr);

        std::string path(wddm->getDeviceRegistryPath());

        auto driverInfo = new DriverInfoWindows(std::move(path));

        driverInfo->setRegistryReader(new RegistryReader(false, driverInfo->getRegistryPath()));
        return driverInfo;
    }

    return nullptr;
};

void DriverInfoWindows::setRegistryReader(SettingsReader *reader) {
    registryReader.reset(reader);
}

std::string DriverInfoWindows::trimRegistryKey(std::string path) {
    std::string prefix("\\REGISTRY\\MACHINE\\");
    auto pos = prefix.find(prefix);
    if (pos != std::string::npos)
        path.erase(pos, prefix.length());

    return path;
}

std::string DriverInfoWindows::getDeviceName(std::string defaultName) {
    return registryReader.get()->getSetting("HardwareInformation.AdapterString", defaultName);
}

std::string DriverInfoWindows::getVersion(std::string defaultVersion) {
    return registryReader.get()->getSetting("DriverVersion", defaultVersion);
};

const std::string &DriverInfoWindows::getRegistryPath() const {
    return path;
}

} // namespace NEO