// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include_next <lv_conf.h>

#undef LV_FONT_MONTSERRAT_14
#define LV_FONT_MONTSERRAT_14 1

#undef LV_FONT_MONTSERRAT_30
#define LV_FONT_MONTSERRAT_30 1

#undef LV_FONT_MONTSERRAT_34
#define LV_FONT_MONTSERRAT_34 1

#undef LV_FONT_MONTSERRAT_38
#define LV_FONT_MONTSERRAT_38 1

#undef LV_FONT_MONTSERRAT_48
#define LV_FONT_MONTSERRAT_48 1

#undef LV_FONT_CUSTOM_DECLARE
#define LV_FONT_CUSTOM_DECLARE LV_FONT_DECLARE(HOOSKAI_FONT_36)
