/*
* Copyright 2023 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef __CUSTOM_H_
#define __CUSTOM_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "gui_guider.h"

typedef enum {
  PHASE_POWER_ON_STARTING = 0,
  PHASE_POWER_ON_WIFI_CONNECTING,
  PHASE_POWER_ON_TIME_SYNCING,
  PHASE_POWER_ON_DONE,
}phase_power_on_e;

typedef struct _event_params_power_on
{
  phase_power_on_e phase;
  int32_t progress_val;
  const char* msg;
}event_params_power_on_t;

typedef struct _init_phase
{
  phase_power_on_e phase;
  int32_t progress_val;
  const char* msg;
  void (*exec)(void);
}init_phase_t;


extern uint32_t MY_EVENT_POWER_ON;

void custom_init(lv_ui *ui);
void trigger_power_on_progress(phase_power_on_e);

#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
