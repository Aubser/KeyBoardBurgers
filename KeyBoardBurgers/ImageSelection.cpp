#include "ImageSelection.h"
// ----------------------------------------------------------------
// Draws the correct image onto the bitmap based upon the sent string
// ----------------------------------------------------------------
Bitmap^ ImageSelection::getImage(std::string ingredient)
{
   gcroot<Drawing::Bitmap^> image;

   if (ingredient == "Ketchup")
   {
      image = gcnew System::Drawing::Bitmap("Ketchup.png");
      image->MakeTransparent(image->GetPixel(1, 1));
   }
   else if (ingredient == "Bottom bun")
   {
      image = gcnew System::Drawing::Bitmap("BottomBun.png");
      image->MakeTransparent(image->GetPixel(1, 1));
   }
   else if (ingredient == "Lettuce")
   {
      image = gcnew System::Drawing::Bitmap("Lettuce.png");
      image->MakeTransparent(image->GetPixel(1, 1));
   }
   else if (ingredient == "Tomato")
   {
      image = gcnew System::Drawing::Bitmap("Tomato.png");
      image->MakeTransparent(image->GetPixel(1, 1));
   }
   else if (ingredient == "Cheese")
   {
      image = gcnew System::Drawing::Bitmap("Cheese.png");
      image->MakeTransparent(image->GetPixel(1, 1));
   }
   else if (ingredient == "Top bun")
   {
      image = gcnew System::Drawing::Bitmap("TopBun.png");
      image->MakeTransparent(image->GetPixel(1, 1));
   }
   else if (ingredient == "Patty")
   {
      image = gcnew System::Drawing::Bitmap("Patty.png");
      image->MakeTransparent(image->GetPixel(1, 1));
   }
   else if (ingredient == "Mustard")
   {
      image = gcnew System::Drawing::Bitmap("Mustard.png");
      image->MakeTransparent(image->GetPixel(1, 1));
   }
   else if (ingredient == "Drink")
   {
      image = gcnew System::Drawing::Bitmap("Soda.png");
      image->MakeTransparent(image->GetPixel(1, 1));
   }
   else if (ingredient == "Fries")
   {
      image = gcnew System::Drawing::Bitmap("Fries.png");
      image->MakeTransparent(image->GetPixel(1, 1));
   }
   else
   {
      image = nullptr;
   }

   return image;
}