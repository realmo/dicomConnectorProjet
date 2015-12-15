/*****************************************************************************
 * $CAMITK_LICENCE_BEGIN$
 *
 * CamiTK - Computer Assisted Medical Intervention ToolKit
 * (c) 2001-2014 UJF-Grenoble 1, CNRS, TIMC-IMAG UMR 5525 (GMCAO)
 *
 * Visit http://camitk.imag.fr for more information
 *
 * This file is part of CamiTK.
 *
 * CamiTK is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License version 3
 * only, as published by the Free Software Foundation.
 *
 * CamiTK is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License version 3 for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * version 3 along with CamiTK.  If not, see <http://www.gnu.org/licenses/>.
 *
 * $CAMITK_LICENCE_END$
 ****************************************************************************/


#ifndef DOCONNECTIONEXTENSION_H
#define DOCONNECTIONEXTENSION_H

#include <ActionExtension.h>

class DoConnectionExtension : public camitk::ActionExtension {
    Q_OBJECT
    Q_INTERFACES(camitk::ActionExtension);

public:
    /// Constructor
    DoConnectionExtension() : ActionExtension() {};

    /// Destructor
    virtual ~DoConnectionExtension() {};

    /// Method returning the action extension name
    virtual QString getName() {
        return "doConnectionExtension";
    };

    /// Method returning the action extension descrption
    virtual QString getDescription() {
        return "Extension for doConnection action";
    };

    /// initialize all the actions
    virtual void init();

};

#endif // DOCONNECTIONEXTENSION_H


