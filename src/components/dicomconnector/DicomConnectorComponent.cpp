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

// CamiTK includes
#include "DicomConnectorComponent.h"
#include <Property.h>

#include <QFileInfo>


using namespace camitk;

// --------------- Constructor -------------------
DicomConnectorComponent::DicomConnectorComponent(const QString & file) throw(AbortException)
:
Component(file, QFileInfo(file).baseName())
{
    // Read the input file...

    // If you want to add properties to your component, you can add them
    // using properties
    // addProperty(new Property(tr("Property name"), "Property value", tr("Property description"), "Property unit"));

    // Add sub-components using the following code lines
    // Create a component (can be a component of your Component extension:
    // Component * subComp = new .....
    // add it as sub-component:
    // addChild(subComp);

}

// --------------- destructor -------------------
DicomConnectorComponent::~DicomConnectorComponent() {

}

