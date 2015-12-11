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


#ifndef DICOMCONNECTOR_H
#define DICOMCONNECTOR_H

#include <ActionExtension.h>

class DicomConnector : public camitk::ActionExtension {
    Q_OBJECT
    Q_INTERFACES(camitk::ActionExtension);

public:
    /// Constructor
    DicomConnector() : ActionExtension() {};

    /// Destructor
    virtual ~DicomConnector() {};

    /// Method returning the action extension name
    virtual QString getName() {
        return "DicomConnector";
    };

    /// Method returning the action extension descrption
    virtual QString getDescription() {
        return "Establish a connection to a Dicom Modality";
    };

    /// initialize all the actions
    virtual void init();

};

#endif // DICOMCONNECTOR_H


