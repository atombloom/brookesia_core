/*
 * SPDX-FileCopyrightText: 2024-2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include "systems/phone/widgets/recents_screen/esp_brookesia_recents_screen.hpp"
#include "systems/phone/assets/esp_brookesia_phone_assets.h"

namespace esp_brookesia::systems::phone {

// 466 圆形屏幕样式：最近任务卡片快照配置
// 注意：主区域和标题/图片高度之和必须不超过父容器高度（当前为 338），否则会触发校准报错
constexpr RecentsScreenSnapshot::Data STYLESHEET_466_CIRCLE_DARK_RECENTS_SCREEN_SNAPSHOT_DATA = {
    // 主卡片区域：宽度保持 300，高度收缩到 338 以内以适配 466 圆形屏幕可用区域（338）
    .main_size = gui::StyleSize::RECT(300, 338),
    .title = {
        // 标题高度保持 52 像素
        .main_size = gui::StyleSize::RECT(300, 52),
        .main_layout_column_pad = 10,
        .icon_size = gui::StyleSize::SQUARE(36),
        .text_font = gui::StyleFont::SIZE(22),
        .text_color = gui::StyleColor::COLOR(0xFFFFFF),
    },
    .image = {
        // 图片高度从 300 调整为 280，使标题高度 + 图片高度 = 332 <= 338（主区域高度）
        .main_size = gui::StyleSize::RECT(300, 280),
        .radius = 20,
    },
};

// 466 圆形屏幕样式：最近任务整体布局配置
constexpr RecentsScreen::Data STYLESHEET_466_CIRCLE_DARK_RECENTS_SCREEN_DATA = {
    .main = {
        .size = gui::StyleSize::RECT_PERCENT(100, 100),
        .layout_row_pad = 10,
        .layout_top_pad = 0,
        .layout_bottom_pad = 20,
        .background_color = gui::StyleColor::COLOR(0x1A1A1A),
    },
    .memory = {
        .main_size = gui::StyleSize::RECT_W_PERCENT(100, 20),
        .main_layout_x_right_offset = 10,
        .label_text_font = gui::StyleFont::SIZE(16),
        .label_text_color = gui::StyleColor::COLOR(0xFFFFFF),
        .label_unit_text = "KB",
    },
    .snapshot_table = {
        .main_size = gui::StyleSize::RECT_PERCENT(100, 100),
        .main_layout_column_pad = 40,
        .snapshot = STYLESHEET_466_CIRCLE_DARK_RECENTS_SCREEN_SNAPSHOT_DATA,
    },
    .trash_icon = {
        .default_size = gui::StyleSize::SQUARE(48),
        .press_size = gui::StyleSize::SQUARE(43),
        .image = gui::StyleImage::IMAGE(&esp_brookesia_image_middle_recents_screen_trash_48_48),
    },
    .flags = {
        .enable_memory = 1,
        .enable_table_height_flex = 1,
        .enable_table_snapshot_use_icon_image = 0,
    },
};

} // namespace esp_brookesia::systems::phone
