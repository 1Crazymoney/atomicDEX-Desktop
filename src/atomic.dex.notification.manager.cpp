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

#include "atomic.dex.notification.manager.hpp"

namespace atomic_dex
{
    notification_manager::notification_manager(entt::dispatcher& dispatcher, QObject* parent) noexcept : QObject(parent), m_dispatcher(dispatcher)
    {
        spdlog::trace("{} l{} f[{}]", __FUNCTION__, __LINE__, fs::path(__FILE__).filename().string());
        spdlog::trace("notification manager created");
    }

    notification_manager::~notification_manager() noexcept
    {
        spdlog::trace("{} l{} f[{}]", __FUNCTION__, __LINE__, fs::path(__FILE__).filename().string());
        spdlog::trace("notification manager destroyed");
    }

    void
    notification_manager::on_swap_status_notification(const atomic_dex::swap_status_notification& evt)
    {
        emit updateSwapStatus(QString::fromStdString(evt.prev_status), QString::fromStdString(evt.new_status), QString::fromStdString(evt.uuid));
    }

    void
    notification_manager::connect_signals() noexcept
    {
        m_dispatcher.sink<swap_status_notification>().connect<&notification_manager::on_swap_status_notification>(*this);
    }

    void
    notification_manager::disconnect_signals() noexcept
    {
        m_dispatcher.sink<swap_status_notification>().disconnect<&notification_manager::on_swap_status_notification>(*this);
    }
} // namespace atomic_dex