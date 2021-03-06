/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company.  For licensing terms and
** conditions see http://www.qt.io/terms-conditions.  For further information
** use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file.  Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, The Qt Company gives you certain additional
** rights.  These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
****************************************************************************/

#include "childrenchangedcommand.h"

#include <QDebug>

namespace QmlDesigner {

ChildrenChangedCommand::ChildrenChangedCommand()
    : m_parentInstanceId(-1)
{
}

ChildrenChangedCommand::ChildrenChangedCommand(qint32 parentInstanceId, const QVector<qint32> &children, const QVector<InformationContainer> &informationVector)
    : m_parentInstanceId(parentInstanceId),
      m_childrenVector(children),
      m_informationVector(informationVector)
{
}

QVector<qint32> ChildrenChangedCommand::childrenInstances() const
{
    return m_childrenVector;
}

qint32 ChildrenChangedCommand::parentInstanceId() const
{
    return m_parentInstanceId;
}

QVector<InformationContainer> ChildrenChangedCommand::informations() const
{
    return m_informationVector;
}

void ChildrenChangedCommand::sort()
{
    qSort(m_childrenVector);
    qSort(m_informationVector);
}

QDataStream &operator<<(QDataStream &out, const ChildrenChangedCommand &command)
{
    out << command.parentInstanceId();
    out << command.childrenInstances();
    out << command.informations();
    return out;
}

QDataStream &operator>>(QDataStream &in, ChildrenChangedCommand &command)
{
    in >> command.m_parentInstanceId;
    in >> command.m_childrenVector;
    in >> command.m_informationVector;

    return in;
}

bool operator ==(const ChildrenChangedCommand &first, const ChildrenChangedCommand &second)
{
    return first.m_parentInstanceId == second.m_parentInstanceId
            && first.m_childrenVector == second.m_childrenVector
            && first.m_informationVector == second.m_informationVector;
}

QDebug operator <<(QDebug debug, const ChildrenChangedCommand &command)
{
    return debug.nospace() << "ChildrenChangedCommand("
                           << "parentInstanceId: " << command.parentInstanceId() << ", "
                           << "children: " << command.childrenInstances() << ", "
                           << "informations: " << command.informations() << ")";
}

} // namespace QmlDesigner
