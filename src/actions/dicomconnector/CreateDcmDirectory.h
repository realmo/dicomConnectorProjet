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


#ifndef CREATEDCMDIRECTORY_H
#define CREATEDCMDIRECTORY_H

#include <Action.h>

#include <ImageComponent.h>

class CreateDcmDirectory : public camitk::Action {

public: 

    /// Default Constructor 
    CreateDcmDirectory(camitk::ActionExtension *);

    /// Default Destructor
    virtual ~CreateDcmDirectory();

public slots:
    /** this method is automatically called when the action is triggered.
      * Call getTargets() method to get the list of components to use.
      * \note getTargets() is automatically filtered so that it only contains compatible components, 
      * i.e., instances of CreateDcmDirectory (or a subclass).
      */
    virtual ApplyStatus apply();

private: 
    /// helper method to simplify the target component processing
    virtual void process(camitk::ImageComponent *);
	

}; 

#endif // CREATEDCMDIRECTORY_H

