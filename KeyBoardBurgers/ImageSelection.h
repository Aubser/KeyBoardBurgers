#pragma once
#include <cstddef>
#include <vcclr.h>
#include <string>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

//---------------------------------------------------------------------
// Name:    Adrian A., Aubrey S., Alex B., Noah N.
// Project: KeyBoardBurgers
// Purpose: This code is responsible for grabbing the correct image
//          for the ingredient
//---------------------------------------------------------------------
class ImageSelection
{
public:
   Bitmap^ getImage(std::string ingredient);
};