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


#include "DicomConnector.h"


// include generated components headers
#include "DicomConnectorComponent.h"

using namespace camitk;

// --------------- Extension Declaration -------------------
Q_EXPORT_PLUGIN2(dicomconnector, DicomConnector);

// --------------- GetFileExtensions -------------------
QStringList DicomConnector::getFileExtensions() const { 
    QStringList ext;
    ext << "dcm";
    
    return ext;
}

// --------------- Open -------------------
Component * DicomConnector::open(const QString & fileName) throw (AbortException) {
    return new DicomConnectorComponent(fileName);}

// --------------- Save --------------------
bool DicomConnector::save(Component * component) const { 
    // depending on the components managed by DicomConnector, use
    // component->getPointSet() (for a MeshComponent derived class)
    // or component->getImageData() (for a ImageComponent derived class)
    // and save the data in the managed format in the file component->getFileName()

    return false;
}

