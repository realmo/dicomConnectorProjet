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
#include "CreateDcmDirectory.h"
#include <Property.h>
#include <Application.h>

// Qt includes
#include <QString>
#include <QMessageBox>
#include <QTextStream>


using namespace camitk;


// --------------- Constructor -------------------
CreateDcmDirectory::CreateDcmDirectory(ActionExtension * extension) : Action(extension) {
    // Setting name, description and input component
    setName("CreateDcmDirectory");
    setDescription("Create the directory where files will be written");
    setComponent("ImageComponent");

    // Setting classification family and tags
    setFamily("DicomConnector");
    addTag("Dicom");
    addTag("Directory");

    // Setting the action's parameters
    // If you want to add parameters to your action, you can add them
    // using properties
    // addParameter(new Property(tr("Property name"), "Property value", tr("Property description"), "Property unit"));

}

// --------------- destructor -------------------
CreateDcmDirectory::~CreateDcmDirectory() {
    // Do not do anything yet.
    // Delete stuff if you create stuff
    // (except if you use smart pointers of course !!)
}

// --------------- apply -------------------
Action::ApplyStatus CreateDcmDirectory::apply() {

    foreach (Component *comp, getTargets()) {
        ImageComponent * input = dynamic_cast<ImageComponent *> ( comp );
        process(input);
    }

    return SUCCESS;
}

void CreateDcmDirectory::process(ImageComponent * comp) {

    // For this example, the action just pops up a message.
    QString msg;
    QTextStream in(&msg);
    in << "Action CreateDcmDirectory called on " << comp->getName()  << endl;
    QMessageBox::warning(NULL, "Action Called", msg);

    // Getting the input image
    vtkSmartPointer<vtkImageData> inputImage  = comp->getImageData();
    int dims[3];
    int numberOfScalarComponents = inputImage->GetNumberOfScalarComponents();
    inputImage->GetDimensions(dims);

    // Creating the output image
    vtkSmartPointer<vtkImageData> outputImage = vtkSmartPointer<vtkImageData>::New();
    outputImage->SetDimensions(dims);
    outputImage->SetScalarType(inputImage->GetScalarType());
    outputImage->SetNumberOfScalarComponents(numberOfScalarComponents);

    // Here, we arbitrarily fill the output image with the exact same data as the input image.
    // Thus this action just copy the input image (an example of stupid action...).
    for (int z = 0; z < dims[2]; z++) {
        for (int y=0; y<dims[1]; y++) {
            for (int x=0; x<dims[0]; x++) {
                for (int color = 0; color < numberOfScalarComponents; color++) {
                    double val = inputImage->GetScalarComponentAsDouble(x, y, z, color);
                    outputImage->SetScalarComponentFromDouble(x,y,z,color,val);
                }
            }
        }
    }

    // Create The output Component
    QString newName;
    QTextStream(&newName) << comp->getName() << "_processed";
    new ImageComponent(outputImage, newName);
    Application::refresh();

}


