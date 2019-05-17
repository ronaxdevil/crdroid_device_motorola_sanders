/*
 * Copyright (c) 2018, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * *    * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of The Linux Foundation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __POWER_HELPER_H__
#define __POWER_HELPER_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    POWER_FEATURE_DOUBLE_TAP_TO_WAKE = 0x00000001
} feature_t;

enum stats_type {
    //Platform Stats
    RPM_MODE_XO = 0,
    RPM_MODE_VMIN,
    RPM_MODE_MAX,
    XO_VOTERS_START = RPM_MODE_MAX,
    VOTER_APSS = XO_VOTERS_START,
    VOTER_MPSS,
    VOTER_ADSP,
    VOTER_SLPI,
    MAX_PLATFORM_STATS,

#ifndef NO_WLAN_STATS
    //WLAN Stats
    WLAN_POWER_DEBUG_STATS = 0,
    MAX_WLAN_STATS,
#endif
};

#ifndef NO_WLAN_STATS
enum subsystem_type {
    SUBSYSTEM_WLAN = 0,

    //Don't add any lines after this line
    SUBSYSTEM_COUNT
};

enum wlan_sleep_states {
    WLAN_STATE_ACTIVE = 0,
    WLAN_STATE_DEEP_SLEEP,

    //Don't add any lines after this line
    WLAN_STATES_COUNT
};

void power_init(void);
void power_hint(power_hint_t hint, void *data);
void set_interactive(int on);
void set_feature(feature_t feature, int state);

#ifdef __cplusplus
}
#endif

#endif //__POWER_HELPER_H__
