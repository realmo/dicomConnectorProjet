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

#include <QObject>

#include<ComponentExtension.h>

class DicomConnector : public camitk::ComponentExtension {
    Q_OBJECT
    Q_INTERFACES(camitk::ComponentExtension);

public:
    /// Constructor
    DicomConnector() : ComponentExtension() {};

    /// Method returning the component extension name
    virtual QString getName() const {
        return "DicomConnector";
    };

    /// Method returning the component extension descrption
    virtual QString getDescription() const {
        return "Dicom connection management";
    };


    /** Get the list of managed extensions
     * (each file with an extension in the list can be loaded by this extension)
     */
    virtual QStringList getFileExtensions() const;

    /** Get a new instance from data stored in a file
     *  (this is the most important method to redefine in your subclass)
     */
    virtual camitk::Component * open(const QString &) throw (camitk::AbortException);

    /** Save a given Component (does not have to be top-level)
     *  into one of the currently managed format.
     *  @return false if the operation was not performed properly or not performed at all.
     */
    virtual bool save(camitk::Component *) const;

protected:
    /// Destructor
    virtual ~DicomConnector() {};

};

#endif // DICOMCONNECTOR

