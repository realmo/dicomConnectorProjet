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

#include <iostream>

// CamiTK includes
#include "DoConnection.h"
#include <Property.h>
#include <Application.h>

// Qt includes
#include <QString>
#include <QMessageBox>
#include <QTextStream>

// GDCM includes
//#include <getopt.h>
#include "gdcmVersion.h"
#include "gdcmGlobal.h"
#include "gdcmSystem.h"
#include "gdcmDirectory.h"
#include "gdcmDataSet.h"
#include "gdcmFileMetaInformation.h"
#include "gdcmUIDGenerator.h"

#include "gdcmBaseRootQuery.h"
#include "gdcmQueryFactory.h"
#include "gdcmPrinter.h"

using namespace camitk;


// --------------- Constructor -------------------
DoConnection::DoConnection(ActionExtension * extension) : Action(extension) {
    // Setting name, description and input component
    setName("doConnection");
    setDescription("Perform connection to a DICOM Modality");
    setComponent("ImageComponent");

    // Setting classification family and tags
    setFamily("Dicom Connector");
    // Tags allow the user to search the actions trhough themes
    // You can add tags here with the method addTag("tagName");

    // Setting the action's parameters
    addParameter(new Property(tr("AETitle"), "camitk-pacs", tr("Calling AE Title"), ""));
    addParameter(new Property(tr("port"), 104, tr("Port used for incoming association"), ""));
    addParameter(new Property(tr("hostname"), "AE Hostname", tr("Write a description about your parameter"), ""));

}

// --------------- destructor -------------------
DoConnection::~DoConnection() {
    // Do not do anything yet.
    // Delete stuff if you create stuff
    // (except if you use smart pointers of course !!)
}

// --------------- apply -------------------
Action::ApplyStatus DoConnection::apply() {

    foreach (Component *comp, getTargets()) {
        ImageComponent * input = dynamic_cast<ImageComponent *> ( comp );
        process(input);
    }

    return SUCCESS;
}

void DoConnection::process(ImageComponent * comp) {
    // Get the parameters
    QString AETitle = property("AETitle").value<QString>();
    int port = property("port").toInt();
    QString hostname = property("hostname").value<QString>();

    // For this example, the action just pops up a message.
    QString msg;
    QTextStream in(&msg);
    in << "Action doConnection called on " << comp->getName()  << endl;
    in << "With parameters: " << endl;
    in << "AETitle: " << AETitle << endl;
    in << "port: " << port << endl;
    in << "hostname: " << hostname << endl;
    
    Application::refresh();
    QTextStream(stdout) << msg << endl;

}


