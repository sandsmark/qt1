/****************************************************************************
** $Id: qtabdialog.h,v 2.20.2.1 1998/08/19 16:02:27 agulbra Exp $
**
** Definition of QTabDialog class
**
** Created : 960825
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

#ifndef QTABDIALOG_H
#define QTABDIALOG_H

#ifndef QT_H
#include "qdialog.h"
#endif // QT_H


class  QTabBar;
struct QTabPrivate;
struct QTab;


class Q_EXPORT QTabDialog : public QDialog
{
    Q_OBJECT
public:
    QTabDialog( QWidget *parent=0, const char *name=0, bool modal=FALSE,
		WFlags f=0 );
   ~QTabDialog();

    void show();
    void setFont( const QFont & font );

    void addTab( QWidget *, const char * );
    void addTab( QWidget *, QTab* );
    bool isTabEnabled( const char * ) const;
    void setTabEnabled( const char *, bool );

    void showPage( QWidget * );
    const char * tabLabel( QWidget * );

    void setDefaultButton( const char *text = "Defaults" );
    bool hasDefaultButton() const;

    void setCancelButton( const char *text = "Cancel" );
    bool hasCancelButton() const;

    void setApplyButton( const char *text = "Apply" );
    bool hasApplyButton() const;

#if 1 // OBSOLETE
    void setOKButton( const char * text = "OK" );
#endif
    void setOkButton( const char * text = "OK" );
    bool hasOkButton() const;

protected:
    void paintEvent( QPaintEvent * );
    void resizeEvent( QResizeEvent * );
    void styleChange( GUIStyle );
    void setTabBar( QTabBar* );
    QTabBar* tabBar() const;

signals:
    void aboutToShow();

    void applyButtonPressed();
    void cancelButtonPressed();
    void defaultButtonPressed();

    void selected( const char * );

private slots:
    void showTab( int i );

private:
    void setSizes();
    void setUpLayout();
    QRect childRect() const;

    QTabPrivate *d;
};


#endif // QTABDIALOG_H
