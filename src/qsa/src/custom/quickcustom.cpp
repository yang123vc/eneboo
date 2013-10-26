/****************************************************************************
** $Id: quickcustom.cpp  1.1.5   edited 2006-02-23T15:39:57$
**
** Copyright (C) 2001-2006 Trolltech AS.  All rights reserved.
**
** This file is part of the Qt Script for Applications framework (QSA).
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** Licensees holding a valid QSA Beta Evaluation Version license may use
** this file in accordance with the QSA Beta Evaluation Version License
** Agreement provided with the Software.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.trolltech.com/pricing.html or email sales@trolltech.com for
**   information about QSA Commercial License Agreements.
** See http://www.trolltech.com/gpl/ for GPL licensing information.
**
** Contact info@trolltech.com if any conditions of this licensing are
** not clear to you.
**
*****************************************************************************/

#include "quickcustom.h"
#include "quickpaintwidget.h"
#include "quickcolorbutton.h"

static const char *pixlabel_pixmap[] = {
    "22 22 156 2",
    "   c #000008084a4a",
    ".  c #000000004a4a",
    "X  c #000000004242",
    "o  c #4a4a4a4a8484",
    "O  c #84848484adad",
    "+  c #7b7b7b7ba5a5",
    "@  c #73737373a5a5",
    "#  c #84848484a5a5",
    "$  c #84847b7ba5a5",
    "%  c #7b7b8484a5a5",
    "&  c #52525a5a8484",
    "*  c #d6d6d6d6e7e7",
    "=  c #c6c6c6c6dede",
    "-  c #c6c6bdbddede",
    ";  c #cecececedede",
    ":  c #d6d6cecedede",
    ">  c #cecec6c6dede",
    ",  c #deded6d6dede",
    "<  c Gray87",
    "1  c #d6d6d6d6dede",
    "2  c #b5b5b5b5dede",
    "3  c #bdbdbdbdcece",
    "4  c #b5b5adadd6d6",
    "5  c #adadadadd6d6",
    "6  c #bdbdb5b5d6d6",
    "7  c #c6c6c6c6cece",
    "8  c #c6c6c6c6d6d6",
    "9  c #d6d6ceced6d6",
    "0  c #cecececed6d6",
    "q  c #a5a5a5a5d6d6",
    "w  c #bdbdbdbdd6d6",
    "e  c #c6c6bdbdd6d6",
    "r  c #cecec6c6d6d6",
    "t  c #cecebdbdd6d6",
    "y  c #d6d6c6c6d6d6",
    "u  c #adada5a5d6d6",
    "i  c #b5b5b5b5d6d6",
    "p  c #efefcecedede",
    "a  c #f7f7d6d6dede",
    "s  c #e7e7d6d6d6d6",
    "d  c #ffffefefefef",
    "f  c #ffffdedee7e7",
    "g  c #dedececedede",
    "h  c #7b7b7b7badad",
    "j  c Gray100",
    "k  c #ffffefeff7f7",
    "l  c #d6d6c6c6adad",
    "z  c #a5a5adad8484",
    "x  c Gray74",
    "c  c #bdbdadadc6c6",
    "v  c #a5a5adad9c9c",
    "b  c #a5a5adadadad",
    "n  c #a5a5b5b59494",
    "m  c #5a5a63636363",
    "M  c #73737b7ba5a5",
    "N  c #fffffffff7f7",
    "B  c #efefc6c68484",
    "V  c #949484843131",
    "C  c #6b6b7b7b2929",
    "Z  c #737384843939",
    "A  c #6b6b7b7b3939",
    "S  c #5a5a73732121",
    "D  c #63637b7b2929",
    "F  c #636384842121",
    "G  c #39394a4a3131",
    "H  c #000000005252",
    "J  c #cecebdbddede",
    "K  c #efefd6d6efef",
    "L  c #f7f7d6d68c8c",
    "P  c #bdbd8c8c3131",
    "I  c #7b7b7b7b2929",
    "U  c #636373733131",
    "Y  c #636373732929",
    "T  c #52526b6b2121",
    "R  c #52526b6b2929",
    "E  c #5a5a73732929",
    "W  c #424252523939",
    "Q  c #adadadaddede",
    "!  c #94949c9c9494",
    "~  c #d6d6bdbdbdbd",
    "^  c #a5a584843939",
    "/  c #848473732929",
    "(  c #6b6b6b6b2929",
    ")  c #63636b6b2929",
    "_  c #5a5a6b6b2929",
    "`  c #39394a4a3939",
    "'  c #a5a5adadbdbd",
    "]  c #737384845252",
    "[  c #5a5a7b7b2121",
    "{  c #73738c8c3131",
    "}  c #84849c9c4a4a",
    "|  c #7b7b94943939",
    " . c #73736b6b2929",
    ".. c #63636b6b3131",
    "X. c #4a4a52524a4a",
    "o. c #63637b7b3131",
    "O. c #6b6b84843131",
    "+. c #7b7b84843131",
    "@. c #393942423131",
    "#. c #4a4a63631818",
    "$. c #4a4a63632121",
    "%. c #7b7b94943131",
    "&. c #292931314242",
    "*. c #4a4a5a5a2929",
    "=. c #4a4a5a5a2121",
    "-. c #52525a5a3131",
    ";. c #42424a4a2929",
    ":. c #393942422121",
    ">. c #393942421818",
    ",. c #39394a4a2121",
    "<. c #393952522121",
    "1. c #000008085252",
    "2. c #424242423131",
    "3. c #42424a4a3131",
    "4. c #424252523131",
    "5. c #4a4a52523939",
    "6. c #52525a5a3939",
    "7. c #5a5a63633939",
    "8. c #4a4a52523131",
    "9. c #292931312121",
    "0. c #212129291818",
    "q. c #181821211818",
    "w. c #292931311818",
    "e. c #212129293131",
    "r. c #4a4a52524242",
    "t. c #393942422929",
    "y. c #313139392121",
    "u. c #101018182929",
    "i. c #393942425252",
    "p. c #52525a5a4242",
    "a. c #4a4a5a5a4242",
    "s. c #424242422929",
    "d. c #212129291010",
    "f. c #181821212929",
    "g. c #5a5a6b6b4a4a",
    "h. c #5a5a63634a4a",
    "j. c #4a4a52522929",
    "k. c #292929291818",
    "l. c #181821211010",
    "z. c #101010101010",
    "x. c #42424a4a2121",
    "c. c #42424a4a5252",
    "v. c #636373735252",
    "b. c #5a5a6b6b4242",
    "n. c #63636b6b4242",
    "m. c #39394a4a1818",
    "M. c #6b6b8c8c2929",
    "N. c #42425a5a3131",
    "B. c #39394a4a4a4a",
    "V. c #393942424a4a",
    "C. c #313139394242",
    "Z. c #313139394a4a",
    "A. c #393942424242",
    "S. c #42424a4a4a4a",
    "D. c #313139393939",
    "F. c #292931313939",
    "  . X X X X X X X X X X X X X X X X X X .   ",
    ". o O + + @ # # # + # $ % # @ @ + # + O & . ",
    "X % * = = - ; ; ; - : : > , : : < 1 2 * O X ",
    "X # = 3 3 3 4 5 6 7 8 9 7 0 7 8 7 3 q 8 + X ",
    "X + ; w w w 3 e r 6 t 9 9 y e w u i 5 = + X ",
    "X + 9 3 3 w q 3 y t p a s y 6 i 5 3 3 = # X ",
    "X + ; 8 8 7 e e y p d d f p g 9 0 ; > * h X ",
    "X @ i i 3 e r r 9 f j j k l z x c v b n m . ",
    "X M = 7 w 3 0 9 s d j N B V C Z A S D F G H ",
    "X @ 2 3 e - 4 t J K j L P I U Y T R E D W H ",
    "X @ 2 Q 3 ! b e c ~ ~ ^ / ( ) _ _ _ _ D ` H ",
    "X + 7 ' ] [ { } | {  .( ..) _ _ E D E D W H ",
    ". X.o._ S o.O.{ | +.U ( O.O.Y E E U E D ` H ",
    "H @.#.$.R E O.O.{ | %.{ { ) _ _ R _ E D ` H ",
    ". &.*.=.=.R E Y o.U ....-.;.:.>.,.<.$.D G H ",
    "1.&.2.` 3.;.3.4.4.5.6.7.8.;.9.9.0.q.0.w.e.1.",
    "H &.5.r.r.W @.@.5.6.7.7.-.;.t.y.9.w.0.0.u.1.",
    ". i.p.a.5.` @.@.s.8.8.8.4.t.y.w.0.9.0.d.f.1.",
    ". i.g.h.r.5.5.5.3.8.8.j.s.;.t.k.q.l.z.x.W H ",
    ". c.v.h.h.g.b.b.n.7.-.j.8.j.;.w.k.d.m.M.N.H ",
    "1.&.B.V.C.Z.C.A.S.B.D.D.A.D.D.F.e.F.W W &.1.",
    "  H H H H   H H . H H H H H H H 1.H H H 1.  "
};

static const char *pushbutton_pixmap[] = {
    "22 22 32 1",
	"  c Gray100",
	". c Gray94",
	"X c #e1e1e1",
	"o c Gray81",
	"O c #bebebe",
	"+ c Gray68",
	"@ c Gray61",
	"# c Gray54",
	"$ c #797979",
	"% c #686868",
	"& c #565656",
	"* c Gray27",
	"= c #323232",
	"- c Gray10",
	"; c #111111",
	": c Gray0",
	"> c None",
	", c Gray0",
	"< c Gray0",
	"1 c Gray0",
	"2 c Gray0",
	"3 c Gray0",
	"4 c Gray0",
	"5 c Gray0",
	"6 c Gray0",
	"7 c Gray0",
	"8 c Gray0",
	"9 c Gray0",
	"0 c Gray0",
	"q c Gray0",
	"w c Gray0",
	"e c Gray0",
	">>>>>>>>>>>>>>>>>>>>>>",
	">>>>>>>>>>>>>>>>>>>>>>",
	">XXXXX.X...XXXXXoooOX>",
	"X                 .o#o",
	"O          ...XXoOO+#&",
	"O.XoOooOoOO+OO+++O@@$-",
	"+ooOo%::;@O+;%+O#:%@#-",
	"+oOO*::;::@+:=o@::#@$-",
	"+oo@:=oO@:;O:=O::@+#$;",
	"+oo=:++@O=:+:*-:#+@#$-",
	"+Oo;:++++%:#::::O@@#$-",
	"+oo::++@+%:#::::$+##%-",
	"@Oo-:+@@O*:@::O::+@#$;",
	"@OO#:=oO+::+:=O$:=+#%;",
	"+O+O=:;=::#+:;++::%@$;",
	"@O+@+=:::$+@:*@@#:-@%;",
	"@++@@+@#@@@#@@##@###%;",
	"@+@@##@###$#########*=",
	"o&%%%&%&&&&&&&&&&&&*:O",
	">O*-:::::::::::::;;*@>",
	">>>>>>>>>>>>>>>>>>>>>>",
	">>>>>>>>>>>>>>>>>>>>>>"
	};

QuickCustomWidgetInterface::QuickCustomWidgetInterface()
{
}

QStringList QuickCustomWidgetInterface::keys() const
{
    QStringList list;
    list << "PaintWidget" << "ColorButton";
    return list;
}

QWidget* QuickCustomWidgetInterface::create( const QString &feature, QWidget* parent, const char* name )
{
    QWidget* w = 0;

    if ( feature == "PaintWidget" )
	w = new PaintWidget( parent, name );
    else if ( feature == "ColorButton" )
	w = new ColorButton( parent, name );

    return w;
}

QString QuickCustomWidgetInterface::group( const QString& feature ) const
{
    if ( feature == "PaintWidget" )
	return "Input";
    else if ( feature == "ColorButton" )
	return "Buttons";
    return QString::null;
}

QIconSet QuickCustomWidgetInterface::iconSet( const QString &feature ) const
{
    if ( feature == "PaintWidget" )
	return QIconSet( QPixmap( pixlabel_pixmap ) );
    else if ( feature == "ColorButton" )
	return QIconSet( QPixmap( pushbutton_pixmap ) );
    return QIconSet();
}

QString QuickCustomWidgetInterface::includeFile( const QString& feature ) const
{
    if ( feature == "PaintWidget" )
	return "quickpaintwidget.h";
    else if ( feature == "ColorButton" )
	return "quickcolorbutton.h";
    return QString::null;
}

QString QuickCustomWidgetInterface::toolTip( const QString& feature ) const
{
    if ( feature == "PaintWidget" )
	return "Optimized Painter Widget";
    else if ( feature == "ColorButton" )
	return "Color Chooser Button";
    return QString::null;
}

QString QuickCustomWidgetInterface::whatsThis( const QString& feature ) const
{
    if ( feature == "PaintWidget" )
	return "A widget which offers basic paint operations and handles that optized";
    else if ( feature == "ColorButton" )
	return "Color Chooser Button";
    return QString::null;
}

bool QuickCustomWidgetInterface::isContainer( const QString& ) const
{
    return FALSE;
}

Q_EXPORT_PLUGIN( QuickCustomWidgetInterface );