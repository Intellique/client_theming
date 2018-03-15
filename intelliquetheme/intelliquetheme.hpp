/****************************************************************************\
*         ____     __      _____                 ________                    *
*        /  _/__  / /____ / / (_)__ ___ _____   /_  __/ /  ___ __ _  ___     *
*       _/ // _ \/ __/ -_) / / / _ `/ // / -_)   / / / _ \/ -_)  ' \/ -_)    *
*      /___/_//_/\__/\__/_/_/_/\_, /\_,_/\__/   /_/ /_//_/\__/_/_/_/\__/     *
*                               /_/                                          *
*                                                                            *
*  ------------------------------------------------------------------------  *
*  This file is a part of Intellique Theme                                   *
*                                                                            *
*  Intellique Theme is free software; you can redistribute it and/or modify  *
*  it under the terms of the GNU Affero General Public License               *
*  as published by the Free Software Foundation; either version 3            *
*  of the License, or (at your option) any later version.                    *
*                                                                            *
*  This program is distributed in the hope that it will be useful,           *
*  but WITHOUT ANY WARRANTY; without even the implied warranty of            *
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
*  GNU Affero General Public License for more details.                       *
*                                                                            *
*  You should have received a copy of the GNU Affero General Public License  *
*  along with this program.  If not, see <http://www.gnu.org/licenses/>.     *
*                                                                            *
*  ------------------------------------------------------------------------  *
*  Copyright (C) 2018, Guillaume Clercin <gclercin@intellique.com>           *
\****************************************************************************/

#ifndef INTELLIQUE_THEME_H
#define INTELLIQUE_THEME_H

#include "theme.h"

#include <QApplication>
#include <QIcon>
#include <QPixmap>
#include <QString>

#include "config.h"
#include "version.h"


namespace OCC {

/**
 * @brief The IntelliqueTheme class
 * @ingroup libsync
 */
class IntelliqueTheme : public Theme
{

public:
    IntelliqueTheme() {};

    QString configFileName() const  {
        return QLatin1String("intellique.cfg");
    }

    QIcon trayFolderIcon( const QString& ) const  {
        return themeIcon( QLatin1String("intellique-icon") );
    }

    QIcon applicationIcon() const  {
        return themeIcon( QLatin1String("intellique-icon") );
    }

    QString updateCheckUrl() const {
        return QLatin1String("https://updates.nextcloud.org/client/");
    }

    QString helpUrl() const {
        return QString::fromLatin1("https://docs.nextcloud.com/desktop/2.2/").arg(MIRALL_VERSION_MAJOR).arg(MIRALL_VERSION_MINOR);
    }

#ifndef TOKEN_AUTH_ONLY
    QColor wizardHeaderBackgroundColor() const {
		return QColor("#ea6746");
    }

    QColor wizardHeaderTitleColor() const {
        return QColor("#ffffff");
    }

    QPixmap wizardHeaderLogo() const {
        return QPixmap(hidpiFileName(":/client/theme/colored/wizard_logo.png"));
    }
#endif

    QString about() const {
        QString re;
        re = tr("<p>Version %1. For more information please visit <a href='%2'>%3</a>.</p>")
                .arg(MIRALL_VERSION_STRING).arg("http://" MIRALL_STRINGIFY(APPLICATION_DOMAIN))
                .arg(MIRALL_STRINGIFY(APPLICATION_DOMAIN));

        re += trUtf8("<p><small>By Klaas Freitag, Daniel Molkentin, Jan-Christoph Borchardt, "
                     "Olivier Goffart, Markus Götz and others.</small></p>");

        re += tr("<p>This release was supplied by the Intellique<br />"
                 "Copyright 2012-2017 ownCloud GmbH</p>");

        re += tr("<p>Licensed under the GNU General Public License (GPL) Version 2.0.<br/>"
             "%2 and the %2 Logo are registered trademarks of %1 in the "
             "European Union, other countries, or both.</p>")
            .arg(APPLICATION_VENDOR).arg(APPLICATION_NAME);

        re += gitSHA1();
        return re;
}

};

}
#endif // INTELLIQUE_THEME_H
