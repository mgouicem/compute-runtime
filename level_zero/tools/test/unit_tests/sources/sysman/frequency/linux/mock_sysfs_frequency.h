/*
 * Copyright (C) 2020 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#pragma once
#include "level_zero/core/test/unit_tests/mock.h"
#include "level_zero/tools/source/sysman/frequency/linux/os_frequency_imp.h"

#include "sysman/frequency/frequency_imp.h"
#include "sysman/frequency/os_frequency.h"
#include "sysman/linux/fs_access.h"
#include "sysman/sysman.h"
#include "sysman/sysman_imp.h"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winconsistent-missing-override"
#endif

using ::testing::_;

namespace L0 {
namespace ult {

const std::string minFreqFile("gt_min_freq_mhz");
const std::string maxFreqFile("gt_max_freq_mhz");
const std::string requestFreqFile("gt_cur_freq_mhz");
const std::string tdpFreqFile("gt_boost_freq_mhz");
const std::string actualFreqFile("gt_act_freq_mhz");
const std::string efficientFreqFile("gt_RP1_freq_mhz");
const std::string maxValFreqFile("gt_RP0_freq_mhz");
const std::string minValFreqFile("gt_RPn_freq_mhz");

class FrequencySysfsAccess : public SysfsAccess {};

template <>
struct Mock<FrequencySysfsAccess> : public FrequencySysfsAccess {
    double mockMin = 0;
    double mockMax = 0;
    double mockRequest = 0;
    double mockTdp = 0;
    double mockActual = 0;
    double mockEfficient = 0;
    double mockMaxVal = 0;
    double mockMinVal = 0;

    MOCK_METHOD2(read, ze_result_t(const std::string file, double &val));
    MOCK_METHOD2(write, ze_result_t(const std::string file, const double val));

    ze_result_t getVal(const std::string file, double &val) {
        if (file.compare(minFreqFile) == 0) {
            val = mockMin;
        }
        if (file.compare(maxFreqFile) == 0) {
            val = mockMax;
        }
        if (file.compare(requestFreqFile) == 0) {
            val = mockRequest;
        }
        if (file.compare(tdpFreqFile) == 0) {
            val = mockTdp;
        }
        if (file.compare(actualFreqFile) == 0) {
            val = mockActual;
        }
        if (file.compare(efficientFreqFile) == 0) {
            val = mockEfficient;
        }
        if (file.compare(maxValFreqFile) == 0) {
            val = mockMaxVal;
        }
        if (file.compare(minValFreqFile) == 0) {
            val = mockMinVal;
        }
        return ZE_RESULT_SUCCESS;
    }
    ze_result_t setVal(const std::string file, const double val) {
        if (file.compare(minFreqFile) == 0) {
            mockMin = val;
        }
        if (file.compare(maxFreqFile) == 0) {
            mockMax = val;
        }
        if (file.compare(requestFreqFile) == 0) {
            mockRequest = val;
        }
        if (file.compare(tdpFreqFile) == 0) {
            mockTdp = val;
        }
        if (file.compare(actualFreqFile) == 0) {
            mockActual = val;
        }
        if (file.compare(efficientFreqFile) == 0) {
            mockEfficient = val;
        }
        if (file.compare(maxValFreqFile) == 0) {
            mockMaxVal = val;
        }
        if (file.compare(minValFreqFile) == 0) {
            mockMinVal = val;
        }
        return ZE_RESULT_SUCCESS;
    }

    Mock() = default;
    ~Mock() override = default;
};

class PublicLinuxFrequencyImp : public L0::LinuxFrequencyImp {
  public:
    using LinuxFrequencyImp::pSysfsAccess;
};

} // namespace ult
} // namespace L0

#if defined(__clang__)
#pragma clang diagnostic pop
#endif
