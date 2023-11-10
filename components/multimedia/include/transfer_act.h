// Copyright 2020-2021 Beken
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <common/bk_include.h>
#include <driver/media_types.h>
#include "frame_buffer.h"
#include "media_mailbox_list_util.h"
#include <components/video_types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
	TRS_STATE_DISABLED,
	TRS_STATE_ENABLED,
} trs_state_t;


typedef struct
{
	trs_state_t state;
	uint8_t pause : 1;
	uint8_t debug : 1;
	uint32_t param;
} transfer_info_t;

typedef struct
{
	uint8_t id;
	uint8_t eof;
	uint8_t cnt;
	uint8_t size;
	uint8_t data[];
} transfer_data_t;

typedef struct
{
	uint8_t type;
	uint32_t data;
} trs_task_msg_t;

typedef enum
{
	TRS_TRANSFER_START,
	TRS_TRANSFER_DATA,
	TRS_TRANSFER_EXIT,
} trs_task_msg_type_t;

void set_transfer_state(trs_state_t state);
trs_state_t get_transfer_state(void);
bk_err_t transfer_app_task_init(video_setup_t *config);
void transfer_major_init(void);
bk_err_t transfer_app_event_handle(media_mailbox_msg_t *msg);
bk_err_t transfer_major_event_handle(media_mailbox_msg_t *msg);


#ifdef __cplusplus
}
#endif