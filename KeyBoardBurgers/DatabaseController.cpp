#include "DatabaseController.h"

// DatabaseConroller constructor
DatabaseController::DatabaseController()
{
}

//Reads in all the order information for the levels
std::vector<Order*> DatabaseController::defineOrders(int levelNum)
{
   std::vector<Order*> orders;
   String^ levelsFilename = "levels_data.xml";
   String^ ordersFilename = "orders_data.xml";
   XmlTextReader^ levelReader = gcnew XmlTextReader(levelsFilename);
   XmlTextReader^ orderReader = gcnew XmlTextReader(ordersFilename);
   levelReader->WhitespaceHandling = WhitespaceHandling::None;
   orderReader->WhitespaceHandling = WhitespaceHandling::None;

   String^ orderNum;
   IngredientsSimpleFactory factory = IngredientsSimpleFactory();

   //read through the entire level list
   while (levelReader->Read())
   {
      //if it is a level tag
      if (levelReader->Name == "lvl")
      {
         levelReader->Read();
         //see if it's the selected level
         if (int::Parse(levelReader->Value) == levelNum)
         {
            levelReader->Skip();
            levelReader->Read();
            //while still reading orders
            while (levelReader->Name != "ord")
            {
               levelReader->Skip();
            }
            while (levelReader->Name == "ord")
            {
               Order* newOrder = new Order();
               levelReader->Read();
               //select the current order
               orderNum = levelReader->Value;
               while (orderReader->Read())
               {
                  //if it is an order id tag
                  if (orderReader->Name == "id")
                  {
                     orderReader->Read();
                     //see if it's the right order
                     if (orderReader->Value == orderNum)
                     {
                        orderReader->Skip();
                        orderReader->Read();
                        //while there are still ingredients
                        while (orderReader->Name == "ingredient")
                        {
                           orderReader->Read();
                           String^ newIngredientChar = orderReader->Value;
                           //make an ingredient and add it to the order
                           Ingredients* newIngredient = factory.makeIngredient(newIngredientChar[0]);
                           newOrder->addIngredient(newIngredient);
                           orderReader->Skip();
                           orderReader->Read();
                        }
                        if (orderReader->Name == "drink")
                        {
                           orderReader->Read();
                           newOrder->setHasDrink(bool::Parse(orderReader->Value));
                           orderReader->Skip();
                           orderReader->Read();
                        }
                        if (orderReader->Name == "fries")
                        {
                           orderReader->Read();
                           newOrder->setHasFries(bool::Parse(orderReader->Value));
                           orderReader->Skip();
                           orderReader->Read();
                        }
                        orderReader->Read();
                        break;
                     }
                     orderReader->Read();
                  }
               }
               //add the new order to the level's orders
               orders.push_back(newOrder);
               levelReader->Skip();
               levelReader->Read();
            }
            break;
         }
         levelReader->Skip();
      }
   }
   levelReader->Close();
   orderReader->Close();
   return orders;
}

// Reads if the level is unlocked or not
bool DatabaseController::isUnlocked(int levelNum)
{
   String^ levelsFilename = "levels_data.xml";
   XmlTextReader^ levelReader = gcnew XmlTextReader(levelsFilename);
   levelReader->WhitespaceHandling = WhitespaceHandling::None;
   bool locked;

   //while there are things to read
   while (levelReader->Read())
   {
      //if it is a lvl num
      if (levelReader->Name == "lvl")
      {
         //read to the value
         levelReader->Read();
         //if it is the correct level
         if (int::Parse(levelReader->Value) == levelNum)
         {
            levelReader->Skip();
            //read until you find the locked section
            while (levelReader->Name != "locked" && levelReader->Read())
            {
               //do nothing
            }
            //then read to the value and return that value
            levelReader->Read();
            locked = bool::Parse(levelReader->Value);
            break;
         }
         else
            levelReader->Skip();
      }
   }
   levelReader->Close();
   return locked;
}

// Sets the players highscore
bool DatabaseController::setHighScore(int levelNum, int highScore)
{
   XmlDocument^ levelDoc = gcnew XmlDocument();

   String^ levelsFileName = "levels_data.xml";
   String^ highScoreName = "highScore";
   String^ nodeListType = "/levels-data/record";

   String^ highScoreString = highScore.ToString();

   try {
      levelDoc->Load(levelsFileName);
      XmlNodeList^ nodeList = levelDoc->SelectNodes(nodeListType);
      XmlNode^ currNode;
      for (int i = 0; i < levelNum; i++)
      {
         if (i == levelNum - 1)
         {
            currNode = nodeList[i];
            break;
         }
      }
      XmlElement^ level = safe_cast<XmlElement^>(currNode[highScoreName]);
      level->InnerText = highScoreString;
      levelDoc->Save(levelsFileName);
   }
   catch (Exception^ e)
   {
      return false;
   }

   return true;
}

// Reads and gets the player's high score
int DatabaseController::getHighScore(int levelNum)
{
   String^ levelsFilename = "levels_data.xml";
   XmlTextReader^ levelReader = gcnew XmlTextReader(levelsFilename);
   levelReader->WhitespaceHandling = WhitespaceHandling::None;
   int highScore;

   //while there are things to read
   while (levelReader->Read())
   {
      //if it is a lvl num
      if (levelReader->Name == "lvl")
      {
         //read to the value
         levelReader->Read();
         //if it is the correct level
         if (int::Parse(levelReader->Value) == levelNum)
         {
            levelReader->Skip();
            //read until you find the locked section
            while (levelReader->Name != "highScore" && levelReader->Read())
            {
               //do nothing
            }
            //then read to the value and return that value
            levelReader->Read();
            highScore = int::Parse(levelReader->Value);
            break;
         }
         levelReader->Skip();
      }
   }
   levelReader->Close();
   return highScore;
}

// Gets the score needed to beat a level
int DatabaseController::getBeatScore(int levelNum)
{
   String^ levelsFilename = "levels_data.xml";
   XmlTextReader^ levelReader = gcnew XmlTextReader(levelsFilename);
   levelReader->WhitespaceHandling = WhitespaceHandling::None;
   int beatScore;

   //while there are things to read
   while (levelReader->Read())
   {
      //if it is a lvl num
      if (levelReader->Name == "lvl")
      {
         //read to the value
         levelReader->Read();
         //if it is the correct level
         if (int::Parse(levelReader->Value) == levelNum)
         {
            levelReader->Skip();
            //read until you find the beatScore section
            while (levelReader->Name != "beatScore" && levelReader->Read())
            {
               //do nothing
            }
            //then read to the value and return that value
            levelReader->Read();
            beatScore = int::Parse(levelReader->Value);
            break;
         }
         else
            levelReader->Skip();
      }
   }
   levelReader->Close();
   return beatScore;
}

// Writes to allow for the player to unlock the next level
bool DatabaseController::unlockLevel(int levelNum)
{
   XmlDocument^ levelDoc = gcnew XmlDocument();

   String^ levelsFileName = "levels_data.xml";
   String^ lockedName = "locked";
   String^ nodeListType = "/levels-data/record";

   String^ lock = "false";

   try {
      levelDoc->Load(levelsFileName);
      XmlNodeList^ nodeList = levelDoc->SelectNodes(nodeListType);
      XmlNode^ currNode;
      for (int i = 0; i < levelNum; i++)
      {
         if (i == levelNum - 1)
         {
            currNode = nodeList[i];
            break;
         }
      }
      XmlElement^ level = safe_cast<XmlElement^>(currNode[lockedName]);
      level->InnerText = lock;
      levelDoc->Save(levelsFileName);
   }
   catch (Exception^ e)
   {
      return false;
   }
  
   return true;
}