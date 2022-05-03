/* antimicrox Gamepad to KB+M event mapper
 * Copyright (C) 2022 Max Maisel <max.maisel@posteo.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <QObject>

#include "joysensortype.h"

class SetJoystick;

/**
 * @brief Represents one sensor in a SetJoystick and its connections to
 *  other parts of the application.
 *  Receives hardware input events from InputDaemon, processes them and
 *  generates GUI as well as Mouse+Keyboard events.
 */
class JoySensor : public QObject
{
    Q_OBJECT

  public:
    explicit JoySensor(QObject *parent);
    ~JoySensor();

    void queuePendingEvent(float *values, bool ignoresets = false);

    bool inDeadZone(float *values) const;
};
