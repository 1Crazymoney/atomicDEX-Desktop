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

#include <QObject> //! QObject

//! Project include
#include "atomic.dex.qt.wallet.manager.hpp"

namespace atomic_dex
{
    class addressbook_contents final : public QObject
    {
        Q_OBJECT
      public:
        explicit addressbook_contents(QObject* parent = nullptr) noexcept;
        ~addressbook_contents() noexcept final;
    };

    class addressbook_model final : public QObject
    {
        Q_OBJECT
      public:
        Q_PROPERTY(QList<QObject*> contents READ get_contents NOTIFY contentsChanged)
        explicit addressbook_model(atomic_dex::qt_wallet_manager& wallet_manager_, QObject* parent = nullptr) noexcept;
        ~addressbook_model() noexcept final;

      public:
        QList<QObject*> get_contents() const noexcept;
        
      signals:
        void contentsChanged();

      private:
        atomic_dex::qt_wallet_manager& m_wallet_manager;
        QObjectList                    m_contents;
    };
} // namespace atomic_dex