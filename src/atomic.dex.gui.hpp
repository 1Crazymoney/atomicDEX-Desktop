/******************************************************************************
 * Copyright © 2013-2019 The Komodo Platform Developers.                      *
 *                                                                            *
 * See the AUTHORS, DEVELOPER-AGREEMENT and LICENSE files at                  *
 * the top-level directory of this distribution for the individual copyright  *
 * holder information and the developer policies on copyright and licensing.  *
 *                                                                            *
 * Unless otherwise agreed in a custom licensing agreement, no part of the    *
 * Komodo Platform software, including this file may be copied, modified,     *
 * propagated or distributed except according to the terms contained in the   *
 * LICENSE file                                                               *
 *                                                                            *
 * Removal or modification of this copyright notice is prohibited.            *
 *                                                                            *
 ******************************************************************************/

#pragma once

#if defined(__APPLE__) || defined(__linux__)

#include <jet/live/Live.hpp>

#endif

#include <antara/gaming/ecs/system.hpp>

namespace atomic_dex {
    namespace ag = antara::gaming;

    class gui final : public ag::ecs::post_update_system<gui> {
        void reload_code();

#if defined(__APPLE__) || defined(__linux__)
        jet::Live live_;
#endif
    public:
        void on_key_pressed(const ag::event::key_pressed &evt) noexcept;

        explicit gui(entt::registry &registry) noexcept;

        void update() noexcept final;

        void init_live_coding();

        void update_live_coding();
    };
}

REFL_AUTO(type(atomic_dex::gui))