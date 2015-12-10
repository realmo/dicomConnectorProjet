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


#ifndef DICOMCONNECTORCOMPONENT_H
#define DICOMCONNECTORCOMPONENT_H

#include <QObject>

#include <Component.h>

class DicomConnectorComponent : public camitk::Component {

    Q_OBJECT

public:
    /// Default Constructor
    DicomConnectorComponent(const QString & file) throw(camitk::AbortException);

    /// Default Destructor
    virtual ~DicomConnectorComponent();

    /// do nothing to init the representation, as all representation are done in the sub-component
    virtual void initRepresentation() {};

};

#endif // DICOMCONNECTORCOMPONENT_H

