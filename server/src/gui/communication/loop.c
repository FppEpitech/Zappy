/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** loop
*/

#include "gui/communication.h"

enum e_command_label {
    CL_MSZ,
    CL_BCT,
    CL_MCT,
    CL_TNA,
    CL_PPO,
    CL_PLV,
    CL_PIN,
    CL_SGT,
    CL_SST,
    CL_LEN,
};

static const char *command_label[CL_LEN + 1] = {
    [CL_MSZ] = "msz\r",
    [CL_BCT] = "bct\r",
    [CL_MCT] = "mct\r",
    [CL_TNA] = "tna\r",
    [CL_PPO] = "ppo\r",
    [CL_PLV] = "plv\r",
    [CL_PIN] = "pin\r",
    [CL_SGT] = "sgt\r",
    [CL_SST] = "sst\r",
    [CL_LEN] = NULL
};

static void (*command_func[CL_LEN + 1])(gui_t *gui, app_t *app, char *line) = {
    [CL_MSZ] = &msz_response,
    [CL_BCT] = &bct_response,
    [CL_MCT] = &mct_response,
    [CL_TNA] = &tna_response,
    [CL_PPO] = &ppo_response,
    [CL_PLV] = &plv_response,
    [CL_PIN] = &pin_response,
    [CL_SGT] = &sgt_response,
    [CL_SST] = &sst_response,
    [CL_LEN] = NULL
};

void handle_command_gui(gui_t *gui, app_t *app, char *line)
{
    for (int i = 0; i < CL_LEN; i++) {
        if (strncmp(line, command_label[i], 3) == 0
            && command_func[i] != NULL) {
            command_func[i](gui, app, line);
            return;
        }
    }
    suc_command(gui);
}
