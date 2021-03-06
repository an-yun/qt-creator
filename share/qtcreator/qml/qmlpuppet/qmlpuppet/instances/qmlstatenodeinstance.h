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

#ifndef QMLSTATENODEINSTANCE_H
#define QMLSTATENODEINSTANCE_H

#include "objectnodeinstance.h"

QT_BEGIN_NAMESPACE
class QDeclarativeState;
class QDeclarativeStateGroup;
QT_END_NAMESPACE

namespace QmlDesigner {

namespace Internal {

class QmlStateNodeInstance : public ObjectNodeInstance
{
public:
    typedef QSharedPointer<QmlStateNodeInstance> Pointer;
    typedef QWeakPointer<QmlStateNodeInstance> WeakPointer;

    static Pointer create(QObject *objectToBeWrapped);

    void setPropertyVariant(const PropertyName &name, const QVariant &value);
    void setPropertyBinding(const PropertyName &name, const QString &expression);

    void activateState();
    void deactivateState();

    bool updateStateVariant(const ObjectNodeInstance::Pointer &target, const PropertyName &propertyName, const QVariant &value);
    bool updateStateBinding(const ObjectNodeInstance::Pointer &target, const PropertyName &propertyName, const QString &expression);
    bool resetStateProperty(const ObjectNodeInstance::Pointer &target, const PropertyName &propertyName, const QVariant &resetValue);


protected:

    QmlStateNodeInstance(QDeclarativeState *object);

    bool isStateActive() const;

    QDeclarativeState *stateObject() const;
    QDeclarativeStateGroup *stateGroup() const;
};

} // namespace Internal
} // namespace QmlDesigner

#endif // QMLSTATENODEINSTANCE_H
