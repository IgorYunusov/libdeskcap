//*****************************************************************************
// Libdeskcap: A high-performance desktop capture library
//
// Copyright (C) 2014 Lucas Murray <lmurray@undefinedfire.com>
// All rights reserved.
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 2 of the License, or (at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// more details.
//*****************************************************************************

#ifndef CAPTUREOBJECT_H
#define CAPTUREOBJECT_H

#include "libdeskcap.h"
#include <QtCore/QObject>

class Texture;

//=============================================================================
class LDC_EXPORT CaptureObject : public QObject
{
	Q_OBJECT

protected: // Constructor/destructor ------------------------------------------
	CaptureObject();
public:
	virtual ~CaptureObject();

public: // Interface ----------------------------------------------------------
	virtual CptrType	getType() const = 0;
	virtual WinId		getWinId() const = 0;
	virtual MonitorId	getMonitorId() const = 0;
	virtual void		release() = 0;
	virtual void		setMethod(CptrMethod method) = 0;
	virtual CptrMethod	getMethod() const = 0;
	virtual QSize		getSize() const = 0;
	virtual Texture *	getTexture() const = 0;
	virtual bool		isTextureValid() const = 0;
	virtual bool		isFlipped() const = 0;
	virtual QPoint		mapScreenPosToLocal(const QPoint &pos) const = 0;
};
//=============================================================================

#endif // CAPTUREOBJECT_H