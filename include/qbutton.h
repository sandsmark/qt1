/****************************************************************************
** $Id: qbutton.h,v 2.18.2.2 1998/08/21 19:13:24 hanord Exp $
**
** Definition of QButton widget class
**
** Created : 940206
**
** Copyright (C) 1992-1999 Troll Tech AS.  All rights reserved.
**
** This file is part of Qt Free Edition, version 1.45.
**
** See the file LICENSE included in the distribution for the usage
** and distribution terms, or http://www.troll.no/free-license.html.
**
** IMPORTANT NOTE: You may NOT copy this file or any part of it into
** your own programs or libraries.
**
** Please see http://www.troll.no/pricing.html for information about 
** Qt Professional Edition, which is this same library but with a
** license which allows creation of commercial/proprietary software.
**
*****************************************************************************/

#ifndef QBUTTON_H
#define QBUTTON_H

#ifndef QT_H
#include "qwidget.h"
#endif // QT_H


class QButtonGroup;				// button group (qbuttongroup.h)
struct QButtonData;


class Q_EXPORT QButton : public QWidget			// button class
{
    Q_OBJECT
public:
    QButton( QWidget *parent=0, const char *name=0 );
   ~QButton();

    const char *text() const;
    void	setText( const char * );
    const QPixmap *pixmap() const;
    void	setPixmap( const QPixmap & );

    int		accel()	const;
    void	setAccel( int );

    bool	isToggleButton() const;

    void	setDown( bool );
    bool	isDown() const;

    bool	isOn() const;

    bool	autoResize() const;
    void	setAutoResize( bool );

    bool	autoRepeat() const;
    void	setAutoRepeat( bool );

public slots:
    void	animateClick();
    void	toggle();

signals:
    void	pressed();
    void	released();
    void	clicked();
    void	toggled( bool );

protected:
    void	setToggleButton( bool );
    void	setOn( bool );

    virtual bool hitButton( const QPoint &pos ) const;
    virtual void drawButton( QPainter * );
    virtual void drawButtonLabel( QPainter * );

    void	keyPressEvent( QKeyEvent *);
    void	mousePressEvent( QMouseEvent * );
    void	mouseReleaseEvent( QMouseEvent * );
    void	mouseMoveEvent( QMouseEvent * );
    void	paintEvent( QPaintEvent * );
    void	focusInEvent( QFocusEvent * );
    void	focusOutEvent( QFocusEvent * );

    void	enabledChange( bool );

private slots:
    void	animateTimeout();
    void	autoRepeatTimeout();

private:
    QString	btext;
    QPixmap    *bpixmap;
    uint	toggleBt	: 1;
    uint	buttonDown	: 1;
    uint	buttonOn	: 1;
    uint	mlbDown		: 1;
    uint	autoresize	: 1;
    uint	animation	: 1;
    uint	repeat		: 1;
    QButtonData *d;

    friend class QButtonGroup;
    void          ensureData();
    QButtonGroup *group() const;
    void	  setGroup( QButtonGroup* );
    QTimer	 *timer();
private:	// Disabled copy constructor and operator=
#if defined(Q_DISABLE_COPY)
    QButton( const QButton & );
    QButton &operator=( const QButton & );
#endif
};


inline const char *QButton::text() const
{
    return btext;
}

inline const QPixmap *QButton::pixmap() const
{
    return bpixmap;
}

inline bool QButton::isToggleButton() const
{
    return toggleBt;
}

inline  bool QButton::isDown() const
{
    return buttonDown;
}

inline bool QButton::isOn() const
{
    return buttonOn;
}

inline bool QButton::autoResize() const
{
    return autoresize;
}

inline bool QButton::autoRepeat() const
{
    return repeat;
}


#endif // QBUTTON_H
