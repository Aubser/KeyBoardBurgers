#pragma once
#include "GameController.h"
#include "NewCurrentLevel.h"
#include "LevelController.h"
#include "PlayerBurger.h"
#include "Ingredients.h"
#include "ImageSelection.h"
#include "Invoker.h"
#include "Command.h"
#include "AddIngredientCommand.h"
#include "TrashBurgerCommand.h"
#include "AddDrinkCommand.h"
#include "AddFriesCommand.h"
#include "IngredientsSimpleFactory.h"
#include <string>

namespace KeyBoardBurgers {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->MainScreen->BackgroundImage = gcnew System::Drawing::Bitmap("MainScreen.png");
			this->StoreScreen->BackgroundImage = gcnew System::Drawing::Bitmap("MainScreen.png");
			this->LevelSelect->BackgroundImage = gcnew System::Drawing::Bitmap("LevelSelectScreen.png");
			this->BurgerPanel->BackgroundImage = gcnew System::Drawing::Bitmap("Tray.png");
			gameController = nullptr;
			playerBurger = nullptr;
			imageSelector = new ImageSelection();
			invoker = new Invoker();
			itemCount = 0;
			trashCount = 0;
			orderTimeCounter = 15;
			winEndTime = 5;
			loseEndTime = 5;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			if (gameController != nullptr)
			{
				/*delete game;
				delete newPlayerBurger;
				delete playerBurger;
				delete imageSelector;*/
			}
		}
	private: GameController* gameController;			//pointer so we can make multiple??; instantiate in select level button(s)?
	private: PlayerActionController* playerActionController;
	private: LevelController* levelController;
	private: PlayerBurger* playerBurger;
	private: ImageSelection* imageSelector;
	private: Invoker* invoker;
	private: int itemCount;
	private: int trashCount;
	private: int orderTimeCounter;
	private: int winEndTime;
	private: int loseEndTime;
	private: int currLevel;

	// Main Screen
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Panel^ MainScreen;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ ExitGame;
	private: System::Windows::Forms::Button^ ShowLevels;
	private: System::Windows::Forms::Button^ ShowStore;
	private: System::Windows::Forms::Button^ ShowInstructions;

	// Store Screen
	private: System::Windows::Forms::Panel^ StoreScreen;
	private: System::Windows::Forms::Label^ StoreLabel;
	private: System::Windows::Forms::Button^ StoreBackBut;

	// Level Select Screen
	private: System::Windows::Forms::Panel^ LevelSelect;
	private: System::Windows::Forms::Label^ LevelLabel;
	private: System::Windows::Forms::Button^ Home;
	private: System::Windows::Forms::Button^ Level1;
	private: System::Windows::Forms::Button^ Level2;
	private: System::Windows::Forms::Button^ Level3;
	private: System::Windows::Forms::Button^ Level4;
	private: System::Windows::Forms::Button^ Level5;
	private: System::Windows::Forms::Button^ Level6;
	private: System::Windows::Forms::Button^ Level7;
	private: System::Windows::Forms::Button^ Level8;
	private: System::Windows::Forms::Button^ Level9;
	private: System::Windows::Forms::Button^ Level10;

	// Game Screen
	private: System::Windows::Forms::Panel^ GameScreen;
	private: System::Windows::Forms::Button^ exitLvlBtn;

	private: System::Windows::Forms::Button^ gameInstructionsBtn;
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;


	private: System::Windows::Forms::Panel^ BurgerPanel;
	private: System::Windows::Forms::Panel^ Instructions;
	private: System::Windows::Forms::RichTextBox^ instructionsText;
	private: System::Windows::Forms::Button^ instructBack;
	private: System::Windows::Forms::Timer^ orderTimer;
	private: System::Windows::Forms::Label^ timeLeftLabel;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ scoreNumLabel;
	private: System::Windows::Forms::Panel^ exitLvlPop;
	private: System::Windows::Forms::Label^ exitLabel;
	private: System::Windows::Forms::Button^ exitLvlNo;
	private: System::Windows::Forms::Button^ exitLvlYes;
	private: System::Windows::Forms::Label^ lvlNumber;
	private: System::Windows::Forms::Label^ highScoreNumLabel;
	private: System::Windows::Forms::Panel^ winLvlPop;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ winButton;
	private: System::Windows::Forms::Panel^ loseLvlPop;
	private: System::Windows::Forms::Button^ loseLvlBut;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Timer^ winLevelTimer;
	private: System::Windows::Forms::Timer^ loseLevelTimer;
	private: System::Windows::Forms::Label^ loseCountDownTime;
	private: System::Windows::Forms::Label^ LoseLvlText;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ winCountDownLvl;




	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->MainScreen = (gcnew System::Windows::Forms::Panel());
			this->ShowStore = (gcnew System::Windows::Forms::Button());
			this->ShowInstructions = (gcnew System::Windows::Forms::Button());
			this->ShowLevels = (gcnew System::Windows::Forms::Button());
			this->ExitGame = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->StoreScreen = (gcnew System::Windows::Forms::Panel());
			this->StoreLabel = (gcnew System::Windows::Forms::Label());
			this->StoreBackBut = (gcnew System::Windows::Forms::Button());
			this->LevelSelect = (gcnew System::Windows::Forms::Panel());
			this->Home = (gcnew System::Windows::Forms::Button());
			this->LevelLabel = (gcnew System::Windows::Forms::Label());
			this->Level1 = (gcnew System::Windows::Forms::Button());
			this->Level2 = (gcnew System::Windows::Forms::Button());
			this->Level3 = (gcnew System::Windows::Forms::Button());
			this->Level4 = (gcnew System::Windows::Forms::Button());
			this->Level5 = (gcnew System::Windows::Forms::Button());
			this->Level6 = (gcnew System::Windows::Forms::Button());
			this->Level7 = (gcnew System::Windows::Forms::Button());
			this->Level8 = (gcnew System::Windows::Forms::Button());
			this->Level9 = (gcnew System::Windows::Forms::Button());
			this->Level10 = (gcnew System::Windows::Forms::Button());
			this->GameScreen = (gcnew System::Windows::Forms::Panel());
			this->highScoreNumLabel = (gcnew System::Windows::Forms::Label());
			this->lvlNumber = (gcnew System::Windows::Forms::Label());
			this->scoreNumLabel = (gcnew System::Windows::Forms::Label());
			this->timeLeftLabel = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->BurgerPanel = (gcnew System::Windows::Forms::Panel());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->exitLvlBtn = (gcnew System::Windows::Forms::Button());
			this->gameInstructionsBtn = (gcnew System::Windows::Forms::Button());
			this->winLvlPop = (gcnew System::Windows::Forms::Panel());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->winCountDownLvl = (gcnew System::Windows::Forms::Label());
			this->winButton = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->loseLvlPop = (gcnew System::Windows::Forms::Panel());
			this->loseCountDownTime = (gcnew System::Windows::Forms::Label());
			this->LoseLvlText = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->loseLvlBut = (gcnew System::Windows::Forms::Button());
			this->exitLvlPop = (gcnew System::Windows::Forms::Panel());
			this->exitLvlNo = (gcnew System::Windows::Forms::Button());
			this->exitLvlYes = (gcnew System::Windows::Forms::Button());
			this->exitLabel = (gcnew System::Windows::Forms::Label());
			this->Instructions = (gcnew System::Windows::Forms::Panel());
			this->instructBack = (gcnew System::Windows::Forms::Button());
			this->instructionsText = (gcnew System::Windows::Forms::RichTextBox());
			this->orderTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->winLevelTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->loseLevelTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->MainScreen->SuspendLayout();
			this->StoreScreen->SuspendLayout();
			this->LevelSelect->SuspendLayout();
			this->GameScreen->SuspendLayout();
			this->winLvlPop->SuspendLayout();
			this->loseLvlPop->SuspendLayout();
			this->exitLvlPop->SuspendLayout();
			this->Instructions->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MainScreen
			// 
			this->MainScreen->BackColor = System::Drawing::Color::DarkOrange;
			this->MainScreen->Controls->Add(this->ShowStore);
			this->MainScreen->Controls->Add(this->ShowInstructions);
			this->MainScreen->Controls->Add(this->ShowLevels);
			this->MainScreen->Controls->Add(this->ExitGame);
			this->MainScreen->Controls->Add(this->label1);
			this->MainScreen->Location = System::Drawing::Point(12, 12);
			this->MainScreen->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MainScreen->Name = L"MainScreen";
			this->MainScreen->Size = System::Drawing::Size(1280, 720);
			this->MainScreen->TabIndex = 0;
			// 
			// ShowStore
			// 
			this->ShowStore->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->ShowStore->FlatAppearance->BorderSize = 5;
			this->ShowStore->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ShowStore->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ShowStore->Location = System::Drawing::Point(517, 412);
			this->ShowStore->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ShowStore->Name = L"ShowStore";
			this->ShowStore->Size = System::Drawing::Size(245, 66);
			this->ShowStore->TabIndex = 5;
			this->ShowStore->Text = L"Store";
			this->ShowStore->UseVisualStyleBackColor = true;
			this->ShowStore->Click += gcnew System::EventHandler(this, &MyForm::ShowStore_Click);
			// 
			// ShowInstructions
			// 
			this->ShowInstructions->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->ShowInstructions->FlatAppearance->BorderSize = 5;
			this->ShowInstructions->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ShowInstructions->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ShowInstructions->Location = System::Drawing::Point(517, 314);
			this->ShowInstructions->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ShowInstructions->Name = L"ShowInstructions";
			this->ShowInstructions->Size = System::Drawing::Size(244, 66);
			this->ShowInstructions->TabIndex = 4;
			this->ShowInstructions->Text = L"Instructions";
			this->ShowInstructions->UseVisualStyleBackColor = true;
			this->ShowInstructions->Click += gcnew System::EventHandler(this, &MyForm::ShowInstructions_Click);
			// 
			// ShowLevels
			// 
			this->ShowLevels->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->ShowLevels->FlatAppearance->BorderSize = 5;
			this->ShowLevels->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ShowLevels->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ShowLevels->Location = System::Drawing::Point(517, 215);
			this->ShowLevels->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ShowLevels->Name = L"ShowLevels";
			this->ShowLevels->Size = System::Drawing::Size(244, 66);
			this->ShowLevels->TabIndex = 3;
			this->ShowLevels->Text = L"Level Select";
			this->ShowLevels->UseVisualStyleBackColor = true;
			this->ShowLevels->Click += gcnew System::EventHandler(this, &MyForm::ShowLevels_Click);
			// 
			// ExitGame
			// 
			this->ExitGame->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->ExitGame->FlatAppearance->BorderSize = 5;
			this->ExitGame->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ExitGame->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ExitGame->Location = System::Drawing::Point(517, 511);
			this->ExitGame->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ExitGame->Name = L"ExitGame";
			this->ExitGame->Size = System::Drawing::Size(244, 66);
			this->ExitGame->TabIndex = 2;
			this->ExitGame->Text = L"Exit";
			this->ExitGame->UseVisualStyleBackColor = true;
			this->ExitGame->Click += gcnew System::EventHandler(this, &MyForm::ExitGame_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(415, 80);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(408, 46);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Keyboard Burgers";
			// 
			// StoreScreen
			// 
			this->StoreScreen->Controls->Add(this->StoreLabel);
			this->StoreScreen->Controls->Add(this->StoreBackBut);
			this->StoreScreen->Location = System::Drawing::Point(12, 12);
			this->StoreScreen->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->StoreScreen->Name = L"StoreScreen";
			this->StoreScreen->Size = System::Drawing::Size(1280, 720);
			this->StoreScreen->TabIndex = 6;
			this->StoreScreen->Visible = false;
			// 
			// StoreLabel
			// 
			this->StoreLabel->AutoSize = true;
			this->StoreLabel->BackColor = System::Drawing::Color::Transparent;
			this->StoreLabel->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 35.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StoreLabel->Location = System::Drawing::Point(413, 246);
			this->StoreLabel->Name = L"StoreLabel";
			this->StoreLabel->Size = System::Drawing::Size(421, 74);
			this->StoreLabel->TabIndex = 0;
			this->StoreLabel->Text = L"Coming Soon";
			// 
			// StoreBackBut
			// 
			this->StoreBackBut->BackColor = System::Drawing::Color::DarkOrange;
			this->StoreBackBut->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->StoreBackBut->FlatAppearance->BorderSize = 5;
			this->StoreBackBut->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->StoreBackBut->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StoreBackBut->ForeColor = System::Drawing::Color::Black;
			this->StoreBackBut->Location = System::Drawing::Point(516, 400);
			this->StoreBackBut->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->StoreBackBut->Name = L"StoreBackBut";
			this->StoreBackBut->Size = System::Drawing::Size(244, 94);
			this->StoreBackBut->TabIndex = 0;
			this->StoreBackBut->Text = L"Back To Main Menu";
			this->StoreBackBut->UseVisualStyleBackColor = false;
			this->StoreBackBut->Click += gcnew System::EventHandler(this, &MyForm::StoreBackBut_Click);
			// 
			// LevelSelect
			// 
			this->LevelSelect->BackColor = System::Drawing::Color::DarkOrange;
			this->LevelSelect->Controls->Add(this->Home);
			this->LevelSelect->Controls->Add(this->LevelLabel);
			this->LevelSelect->Controls->Add(this->Level1);
			this->LevelSelect->Controls->Add(this->Level2);
			this->LevelSelect->Controls->Add(this->Level3);
			this->LevelSelect->Controls->Add(this->Level4);
			this->LevelSelect->Controls->Add(this->Level5);
			this->LevelSelect->Controls->Add(this->Level6);
			this->LevelSelect->Controls->Add(this->Level7);
			this->LevelSelect->Controls->Add(this->Level8);
			this->LevelSelect->Controls->Add(this->Level9);
			this->LevelSelect->Controls->Add(this->Level10);
			this->LevelSelect->Location = System::Drawing::Point(12, 12);
			this->LevelSelect->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->LevelSelect->Name = L"LevelSelect";
			this->LevelSelect->Size = System::Drawing::Size(1280, 720);
			this->LevelSelect->TabIndex = 0;
			this->LevelSelect->Visible = false;
			// 
			// Home
			// 
			this->Home->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->Home->FlatAppearance->BorderSize = 5;
			this->Home->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Home->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Home->Location = System::Drawing::Point(1055, 50);
			this->Home->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Home->Name = L"Home";
			this->Home->Size = System::Drawing::Size(125, 75);
			this->Home->TabIndex = 2;
			this->Home->Text = L"Home";
			this->Home->UseVisualStyleBackColor = true;
			this->Home->Click += gcnew System::EventHandler(this, &MyForm::Home_Click);
			// 
			// LevelLabel
			// 
			this->LevelLabel->AutoSize = true;
			this->LevelLabel->BackColor = System::Drawing::Color::Transparent;
			this->LevelLabel->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LevelLabel->Location = System::Drawing::Point(491, 75);
			this->LevelLabel->Name = L"LevelLabel";
			this->LevelLabel->Size = System::Drawing::Size(271, 46);
			this->LevelLabel->TabIndex = 0;
			this->LevelLabel->Text = L"Level Select";
			// 
			// Level1
			// 
			this->Level1->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->Level1->FlatAppearance->BorderSize = 5;
			this->Level1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Level1->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 50.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Level1->Location = System::Drawing::Point(60, 199);
			this->Level1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Level1->Name = L"Level1";
			this->Level1->Size = System::Drawing::Size(200, 199);
			this->Level1->TabIndex = 5;
			this->Level1->Text = L"1";
			this->Level1->UseVisualStyleBackColor = true;
			this->Level1->Click += gcnew System::EventHandler(this, &MyForm::Level1_Click);
			// 
			// Level2
			// 
			this->Level2->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->Level2->FlatAppearance->BorderSize = 5;
			this->Level2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Level2->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 50.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Level2->Location = System::Drawing::Point(300, 199);
			this->Level2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Level2->Name = L"Level2";
			this->Level2->Size = System::Drawing::Size(200, 199);
			this->Level2->TabIndex = 5;
			this->Level2->Text = L"2";
			this->Level2->UseVisualStyleBackColor = true;
			this->Level2->Click += gcnew System::EventHandler(this, &MyForm::Level2_Click);
			// 
			// Level3
			// 
			this->Level3->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->Level3->FlatAppearance->BorderSize = 5;
			this->Level3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Level3->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 50.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Level3->Location = System::Drawing::Point(540, 199);
			this->Level3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Level3->Name = L"Level3";
			this->Level3->Size = System::Drawing::Size(200, 199);
			this->Level3->TabIndex = 5;
			this->Level3->Text = L"3";
			this->Level3->UseVisualStyleBackColor = true;
			this->Level3->Click += gcnew System::EventHandler(this, &MyForm::Level3_Click);
			// 
			// Level4
			// 
			this->Level4->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->Level4->FlatAppearance->BorderSize = 5;
			this->Level4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Level4->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 50.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Level4->Location = System::Drawing::Point(780, 199);
			this->Level4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Level4->Name = L"Level4";
			this->Level4->Size = System::Drawing::Size(200, 199);
			this->Level4->TabIndex = 5;
			this->Level4->Text = L"4";
			this->Level4->UseVisualStyleBackColor = true;
			this->Level4->Click += gcnew System::EventHandler(this, &MyForm::Level4_Click);
			// 
			// Level5
			// 
			this->Level5->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->Level5->FlatAppearance->BorderSize = 5;
			this->Level5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Level5->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 50.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Level5->Location = System::Drawing::Point(1020, 199);
			this->Level5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Level5->Name = L"Level5";
			this->Level5->Size = System::Drawing::Size(200, 199);
			this->Level5->TabIndex = 5;
			this->Level5->Text = L"5";
			this->Level5->UseVisualStyleBackColor = true;
			this->Level5->Click += gcnew System::EventHandler(this, &MyForm::Level5_Click);
			// 
			// Level6
			// 
			this->Level6->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->Level6->FlatAppearance->BorderSize = 5;
			this->Level6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Level6->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 50.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Level6->Location = System::Drawing::Point(60, 441);
			this->Level6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Level6->Name = L"Level6";
			this->Level6->Size = System::Drawing::Size(200, 199);
			this->Level6->TabIndex = 5;
			this->Level6->Text = L"6";
			this->Level6->UseVisualStyleBackColor = true;
			this->Level6->Click += gcnew System::EventHandler(this, &MyForm::Level6_Click);
			// 
			// Level7
			// 
			this->Level7->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->Level7->FlatAppearance->BorderSize = 5;
			this->Level7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Level7->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 50.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Level7->Location = System::Drawing::Point(300, 441);
			this->Level7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Level7->Name = L"Level7";
			this->Level7->Size = System::Drawing::Size(200, 199);
			this->Level7->TabIndex = 5;
			this->Level7->Text = L"7";
			this->Level7->UseVisualStyleBackColor = true;
			this->Level7->Click += gcnew System::EventHandler(this, &MyForm::Level7_Click);
			// 
			// Level8
			// 
			this->Level8->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->Level8->FlatAppearance->BorderSize = 5;
			this->Level8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Level8->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 50.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Level8->Location = System::Drawing::Point(540, 441);
			this->Level8->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Level8->Name = L"Level8";
			this->Level8->Size = System::Drawing::Size(200, 199);
			this->Level8->TabIndex = 5;
			this->Level8->Text = L"8";
			this->Level8->UseVisualStyleBackColor = true;
			this->Level8->Click += gcnew System::EventHandler(this, &MyForm::Level8_Click);
			// 
			// Level9
			// 
			this->Level9->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->Level9->FlatAppearance->BorderSize = 5;
			this->Level9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Level9->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 50.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Level9->Location = System::Drawing::Point(780, 441);
			this->Level9->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Level9->Name = L"Level9";
			this->Level9->Size = System::Drawing::Size(200, 199);
			this->Level9->TabIndex = 5;
			this->Level9->Text = L"9";
			this->Level9->UseVisualStyleBackColor = true;
			this->Level9->Click += gcnew System::EventHandler(this, &MyForm::Level9_Click);
			// 
			// Level10
			// 
			this->Level10->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->Level10->FlatAppearance->BorderSize = 5;
			this->Level10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Level10->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 50.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Level10->Location = System::Drawing::Point(1020, 441);
			this->Level10->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Level10->Name = L"Level10";
			this->Level10->Size = System::Drawing::Size(200, 199);
			this->Level10->TabIndex = 5;
			this->Level10->Text = L"10";
			this->Level10->UseVisualStyleBackColor = true;
			this->Level10->Click += gcnew System::EventHandler(this, &MyForm::Level10_Click);
			// 
			// GameScreen
			// 
			this->GameScreen->BackColor = System::Drawing::Color::DarkOrange;
			this->GameScreen->Controls->Add(this->highScoreNumLabel);
			this->GameScreen->Controls->Add(this->lvlNumber);
			this->GameScreen->Controls->Add(this->scoreNumLabel);
			this->GameScreen->Controls->Add(this->timeLeftLabel);
			this->GameScreen->Controls->Add(this->label6);
			this->GameScreen->Controls->Add(this->BurgerPanel);
			this->GameScreen->Controls->Add(this->richTextBox2);
			this->GameScreen->Controls->Add(this->richTextBox1);
			this->GameScreen->Controls->Add(this->label5);
			this->GameScreen->Controls->Add(this->label4);
			this->GameScreen->Controls->Add(this->label3);
			this->GameScreen->Controls->Add(this->label2);
			this->GameScreen->Controls->Add(this->exitLvlBtn);
			this->GameScreen->Controls->Add(this->gameInstructionsBtn);
			this->GameScreen->Location = System::Drawing::Point(1, 12);
			this->GameScreen->Margin = System::Windows::Forms::Padding(4);
			this->GameScreen->Name = L"GameScreen";
			this->GameScreen->Size = System::Drawing::Size(1291, 720);
			this->GameScreen->TabIndex = 6;
			this->GameScreen->Visible = false;

			// 
			// highScoreNumLabel
			// 
			this->highScoreNumLabel->AutoSize = true;
			this->highScoreNumLabel->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->highScoreNumLabel->Location = System::Drawing::Point(804, 21);
			this->highScoreNumLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->highScoreNumLabel->Name = L"highScoreNumLabel";
			this->highScoreNumLabel->Size = System::Drawing::Size(20, 31);
			this->highScoreNumLabel->TabIndex = 16;
			this->highScoreNumLabel->Text = L" ";

			// 
			// lvlNumber
			// 
			this->lvlNumber->AutoSize = true;
			this->lvlNumber->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lvlNumber->Location = System::Drawing::Point(130, 21);
			this->lvlNumber->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lvlNumber->Name = L"lvlNumber";
			this->lvlNumber->Size = System::Drawing::Size(30, 31);
			this->lvlNumber->TabIndex = 15;
			this->lvlNumber->Text = L"0";
			// 
			// scoreNumLabel
			// 
			this->scoreNumLabel->AutoSize = true;
			this->scoreNumLabel->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->scoreNumLabel->Location = System::Drawing::Point(387, 21);
			this->scoreNumLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->scoreNumLabel->Name = L"scoreNumLabel";
			this->scoreNumLabel->Size = System::Drawing::Size(30, 31);
			this->scoreNumLabel->TabIndex = 14;
			this->scoreNumLabel->Text = L"0";
			// 
			// timeLeftLabel
			// 
			this->timeLeftLabel->AutoSize = true;
			this->timeLeftLabel->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->timeLeftLabel->Location = System::Drawing::Point(1228, 21);
			this->timeLeftLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->timeLeftLabel->Name = L"timeLeftLabel";
			this->timeLeftLabel->Size = System::Drawing::Size(20, 31);
			this->timeLeftLabel->TabIndex = 13;
			this->timeLeftLabel->Text = L" ";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(1065, 21);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(155, 31);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Time Left:";
			// 
			// BurgerPanel
			// 
			this->BurgerPanel->Location = System::Drawing::Point(29, 75);
			this->BurgerPanel->Margin = System::Windows::Forms::Padding(4);
			this->BurgerPanel->Name = L"BurgerPanel";
			this->BurgerPanel->Size = System::Drawing::Size(879, 470);
			this->BurgerPanel->TabIndex = 11;
			// 
			// richTextBox2
			// 
			this->richTextBox2->BackColor = System::Drawing::Color::White;
			this->richTextBox2->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox2->Location = System::Drawing::Point(941, 75);
			this->richTextBox2->Margin = System::Windows::Forms::Padding(4);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ReadOnly = true;
			this->richTextBox2->Size = System::Drawing::Size(321, 469);
			this->richTextBox2->TabIndex = 10;
			this->richTextBox2->Text = L"";
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::White;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(227, 559);
			this->richTextBox1->Margin = System::Windows::Forms::Padding(4);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(1040, 152);
			this->richTextBox1->TabIndex = 9;
			this->richTextBox1->Text = L"";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(898, 21);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(127, 31);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Orders:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(620, 21);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(174, 31);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Highscore:";

			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(273, 21);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(106, 31);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Score:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(23, 21);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(99, 31);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Level:";
			// 
			// exitLvlBtn
			// 
			this->exitLvlBtn->BackColor = System::Drawing::Color::Red;
			this->exitLvlBtn->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->exitLvlBtn->FlatAppearance->BorderSize = 6;
			this->exitLvlBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exitLvlBtn->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exitLvlBtn->Location = System::Drawing::Point(28, 641);
			this->exitLvlBtn->Margin = System::Windows::Forms::Padding(4);
			this->exitLvlBtn->Name = L"exitLvlBtn";
			this->exitLvlBtn->Size = System::Drawing::Size(189, 70);
			this->exitLvlBtn->TabIndex = 2;
			this->exitLvlBtn->Text = L"Return to Level Select";
			this->exitLvlBtn->UseVisualStyleBackColor = false;
			this->exitLvlBtn->Click += gcnew System::EventHandler(this, &MyForm::exitLvlBtn_Click);
			// 
			// gameInstructionsBtn
			// 
			this->gameInstructionsBtn->BackColor = System::Drawing::Color::White;
			this->gameInstructionsBtn->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->gameInstructionsBtn->FlatAppearance->BorderSize = 6;
			this->gameInstructionsBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->gameInstructionsBtn->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gameInstructionsBtn->Location = System::Drawing::Point(28, 559);
			this->gameInstructionsBtn->Margin = System::Windows::Forms::Padding(4);
			this->gameInstructionsBtn->Name = L"gameInstructionsBtn";
			this->gameInstructionsBtn->Size = System::Drawing::Size(189, 70);
			this->gameInstructionsBtn->TabIndex = 0;
			this->gameInstructionsBtn->Text = L"Instructions";
			this->gameInstructionsBtn->UseVisualStyleBackColor = false;
			this->gameInstructionsBtn->Click += gcnew System::EventHandler(this, &MyForm::gameInstructionsBtn_Click);
			// 
			// winLvlPop
			// 
			this->winLvlPop->BackColor = System::Drawing::Color::White;
			this->winLvlPop->Controls->Add(this->label10);
			this->winLvlPop->Controls->Add(this->winCountDownLvl);
			this->winLvlPop->Controls->Add(this->winButton);
			this->winLvlPop->Controls->Add(this->label7);
			this->winLvlPop->Location = System::Drawing::Point(344, 124);
			this->winLvlPop->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->winLvlPop->Name = L"winLvlPop";
			this->winLvlPop->Size = System::Drawing::Size(511, 326);
			this->winLvlPop->TabIndex = 0;
			this->winLvlPop->Visible = false;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(89, 175);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(318, 26);
			this->label10->TabIndex = 3;
			this->label10->Text = L"- Or Return To Main Menu -";
			// 
			// winCountDownLvl
			// 
			this->winCountDownLvl->AutoSize = true;
			this->winCountDownLvl->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->winCountDownLvl->ForeColor = System::Drawing::Color::Red;
			this->winCountDownLvl->Location = System::Drawing::Point(222, 100);
			this->winCountDownLvl->Name = L"winCountDownLvl";
			this->winCountDownLvl->Size = System::Drawing::Size(40, 46);
			this->winCountDownLvl->TabIndex = 2;
			this->winCountDownLvl->Text = L"5";
			// 
			// winButton
			// 
			this->winButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->winButton->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->winButton->FlatAppearance->BorderSize = 6;
			this->winButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->winButton->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->winButton->Location = System::Drawing::Point(143, 229);
			this->winButton->Margin = System::Windows::Forms::Padding(4);
			this->winButton->Name = L"winButton";
			this->winButton->Size = System::Drawing::Size(191, 75);
			this->winButton->TabIndex = 1;
			this->winButton->Text = L"Return To Main Menu";
			this->winButton->UseVisualStyleBackColor = false;
			this->winButton->Click += gcnew System::EventHandler(this, &MyForm::winButton_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(35, 37);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(385, 58);
			this->label7->TabIndex = 0;
			this->label7->Text = L"Congrats! You beat the level!\r\nAdvancing to next level in:";
			this->label7->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// loseLvlPop
			// 
			this->loseLvlPop->BackColor = System::Drawing::Color::White;
			this->loseLvlPop->Controls->Add(this->loseCountDownTime);
			this->loseLvlPop->Controls->Add(this->LoseLvlText);
			this->loseLvlPop->Controls->Add(this->label8);
			this->loseLvlPop->Controls->Add(this->loseLvlBut);
			this->loseLvlPop->Location = System::Drawing::Point(344, 124);
			this->loseLvlPop->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->loseLvlPop->Name = L"loseLvlPop";
			this->loseLvlPop->Size = System::Drawing::Size(511, 326);
			this->loseLvlPop->TabIndex = 0;
			this->loseLvlPop->Visible = false;
			// 
			// loseCountDownTime
			// 
			this->loseCountDownTime->AutoSize = true;
			this->loseCountDownTime->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loseCountDownTime->ForeColor = System::Drawing::Color::Red;
			this->loseCountDownTime->Location = System::Drawing::Point(223, 100);
			this->loseCountDownTime->Name = L"loseCountDownTime";
			this->loseCountDownTime->Size = System::Drawing::Size(40, 46);
			this->loseCountDownTime->TabIndex = 3;
			this->loseCountDownTime->Text = L"5";
			// 
			// LoseLvlText
			// 
			this->LoseLvlText->AutoSize = true;
			this->LoseLvlText->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LoseLvlText->Location = System::Drawing::Point(57, 171);
			this->LoseLvlText->Name = L"LoseLvlText";
			this->LoseLvlText->Size = System::Drawing::Size(359, 29);
			this->LoseLvlText->TabIndex = 2;
			this->LoseLvlText->Text = L"- Or return to Main Menu -";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(28, 31);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(413, 58);
			this->label8->TabIndex = 0;
			this->label8->Text = L"You failed the level! \r\nRestarting the current level in:";
			this->label8->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// loseLvlBut
			// 
			this->loseLvlBut->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->loseLvlBut->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->loseLvlBut->FlatAppearance->BorderSize = 6;
			this->loseLvlBut->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->loseLvlBut->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loseLvlBut->Location = System::Drawing::Point(160, 227);
			this->loseLvlBut->Margin = System::Windows::Forms::Padding(4);
			this->loseLvlBut->Name = L"loseLvlBut";
			this->loseLvlBut->Size = System::Drawing::Size(175, 79);
			this->loseLvlBut->TabIndex = 1;
			this->loseLvlBut->Text = L"Return To Main Menu";
			this->loseLvlBut->UseVisualStyleBackColor = false;
			this->loseLvlBut->Click += gcnew System::EventHandler(this, &MyForm::loseLvlBut_Click);
			// 
			// exitLvlPop
			// 
			this->exitLvlPop->BackColor = System::Drawing::Color::White;
			this->exitLvlPop->Controls->Add(this->exitLvlNo);
			this->exitLvlPop->Controls->Add(this->exitLvlYes);
			this->exitLvlPop->Controls->Add(this->exitLabel);
			this->exitLvlPop->Location = System::Drawing::Point(344, 124);
			this->exitLvlPop->Margin = System::Windows::Forms::Padding(4);
			this->exitLvlPop->Name = L"exitLvlPop";
			this->exitLvlPop->Size = System::Drawing::Size(511, 326);
			this->exitLvlPop->TabIndex = 0;
			this->exitLvlPop->Visible = false;
			// 
			// exitLvlNo
			// 
			this->exitLvlNo->BackColor = System::Drawing::Color::Red;
			this->exitLvlNo->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->exitLvlNo->FlatAppearance->BorderSize = 6;
			this->exitLvlNo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exitLvlNo->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exitLvlNo->Location = System::Drawing::Point(359, 251);
			this->exitLvlNo->Margin = System::Windows::Forms::Padding(4);
			this->exitLvlNo->Name = L"exitLvlNo";
			this->exitLvlNo->Size = System::Drawing::Size(133, 54);
			this->exitLvlNo->TabIndex = 2;
			this->exitLvlNo->Text = L"No";
			this->exitLvlNo->UseVisualStyleBackColor = false;
			this->exitLvlNo->Click += gcnew System::EventHandler(this, &MyForm::exitLvlNo_Click);
			// 
			// exitLvlYes
			// 
			this->exitLvlYes->BackColor = System::Drawing::Color::Green;
			this->exitLvlYes->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->exitLvlYes->FlatAppearance->BorderSize = 6;
			this->exitLvlYes->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exitLvlYes->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exitLvlYes->Location = System::Drawing::Point(20, 251);
			this->exitLvlYes->Margin = System::Windows::Forms::Padding(4);
			this->exitLvlYes->Name = L"exitLvlYes";
			this->exitLvlYes->Size = System::Drawing::Size(133, 54);
			this->exitLvlYes->TabIndex = 1;
			this->exitLvlYes->Text = L"Yes";
			this->exitLvlYes->UseVisualStyleBackColor = false;
			this->exitLvlYes->Click += gcnew System::EventHandler(this, &MyForm::exitLvlYes_Click);
			// 
			// exitLabel
			// 
			this->exitLabel->AutoSize = true;
			this->exitLabel->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exitLabel->ForeColor = System::Drawing::Color::Black;
			this->exitLabel->Location = System::Drawing::Point(24, 70);
			this->exitLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->exitLabel->Name = L"exitLabel";
			this->exitLabel->Size = System::Drawing::Size(438, 42);
			this->exitLabel->TabIndex = 0;
			this->exitLabel->Text = L"Your progress for this level will not be saved.\r\nAre you sure you want to exit\?\r\n"
				L"";
			this->exitLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Instructions
			// 
			this->Instructions->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Instructions.BackgroundImage")));
			this->Instructions->Controls->Add(this->instructBack);
			this->Instructions->Controls->Add(this->instructionsText);
			this->Instructions->Location = System::Drawing::Point(12, 12);
			this->Instructions->Margin = System::Windows::Forms::Padding(4);
			this->Instructions->Name = L"Instructions";
			this->Instructions->Size = System::Drawing::Size(1280, 720);
			this->Instructions->TabIndex = 12;
			this->Instructions->Visible = false;
			// 
			// instructBack
			// 
			this->instructBack->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->instructBack->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->instructBack->FlatAppearance->BorderSize = 5;
			this->instructBack->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->instructBack->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->instructBack->Location = System::Drawing::Point(507, 559);
			this->instructBack->Margin = System::Windows::Forms::Padding(4);
			this->instructBack->Name = L"instructBack";
			this->instructBack->Size = System::Drawing::Size(288, 68);
			this->instructBack->TabIndex = 1;
			this->instructBack->Text = L"Back to Main Menu";
			this->instructBack->UseVisualStyleBackColor = false;
			this->instructBack->Click += gcnew System::EventHandler(this, &MyForm::instructBack_Click);
			// 
			// instructionsText
			// 
			this->instructionsText->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->instructionsText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->instructionsText->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->instructionsText->Location = System::Drawing::Point(373, 161);
			this->instructionsText->Margin = System::Windows::Forms::Padding(4);
			this->instructionsText->Name = L"instructionsText";
			this->instructionsText->Size = System::Drawing::Size(537, 318);
			this->instructionsText->TabIndex = 0;
			this->instructionsText->Text = L"Use the keyboard to make burgers.\nMake each burger successfully to earn level poi"
				L"nts.\nEach order has 30 seconds to complete.\nUnlock the next level by getting a h"
				L"igh enough score.\n";
			// 
			// orderTimer
			// 
			this->orderTimer->Interval = 1000;
			this->orderTimer->Tick += gcnew System::EventHandler(this, &MyForm::orderTimer_Tick);
			// 
			// winLevelTimer
			// 
			this->winLevelTimer->Interval = 1000;
			this->winLevelTimer->Tick += gcnew System::EventHandler(this, &MyForm::winLevelTimer_Tick);
			// 
			// loseLevelTimer
			// 
			this->loseLevelTimer->Interval = 1000;
			this->loseLevelTimer->Tick += gcnew System::EventHandler(this, &MyForm::loseLevelTimer_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1292, 732);
			this->Controls->Add(this->GameScreen);
			this->Controls->Add(this->LevelSelect);
			this->Controls->Add(this->MainScreen);
			this->Controls->Add(this->StoreScreen);
			this->Controls->Add(this->loseLvlPop);
			this->Controls->Add(this->winLvlPop);
			this->Controls->Add(this->Instructions);
			this->Controls->Add(this->exitLvlPop);
			this->DoubleBuffered = true;
			this->KeyPreview = true;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MyForm";
			this->Text = L"z";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->MainScreen->ResumeLayout(false);
			this->MainScreen->PerformLayout();
			this->StoreScreen->ResumeLayout(false);
			this->StoreScreen->PerformLayout();
			this->LevelSelect->ResumeLayout(false);
			this->LevelSelect->PerformLayout();
			this->GameScreen->ResumeLayout(false);
			this->GameScreen->PerformLayout();
			this->winLvlPop->ResumeLayout(false);
			this->winLvlPop->PerformLayout();
			this->loseLvlPop->ResumeLayout(false);
			this->loseLvlPop->PerformLayout();
			this->exitLvlPop->ResumeLayout(false);
			this->exitLvlPop->PerformLayout();
			this->Instructions->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	//---------------------------------------------------------------------
	// Checks the key that was inputted by the player
	//---------------------------------------------------------------------
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (loseEndTime == 5 && winEndTime == 5)
		{
			if (e->KeyCode == Keys::W)		//W for waste
			{
				//make the command
				Command* trashingBurger = new TrashBurgerCommand(playerActionController);
				String^ trashOutput = ("The trash is full! Please take out the trash. \n\n");
				//if the trash is full notify the user and don't trash the burger
				if (trashCount >= 3)
				{
					richTextBox1->Text = trashOutput;
				}
				else
				{
					//add the trash command to the invoker
					invoker->doCommand(trashingBurger);
					BurgerPanel->Refresh();
					this->Invalidate();
					trashCount++;
				}

			}
			else if (e->KeyCode == Keys::E)	//E for empty
			{
				//empty trash can
				trashCount = 0;
				String^ trashEmptiedOutput = ("The trash has been emptied! \n\n");
				richTextBox1->Text = trashEmptiedOutput;
			}
			else if (e->KeyCode == Keys::U)	//U for undo
			{
				invoker->undo();
				BurgerPanel->Refresh();
				this->Invalidate();
			}
			else if (e->KeyCode == Keys::R)	//R for redo
			{
				invoker->redo();
				BurgerPanel->Refresh();
				this->Invalidate();
			}
			else if (e->KeyCode == Keys::Space)	//Space for submit
			{
				//compare burgers
				if (gameController->compareOrders(playerActionController, levelController->getCurrentOrder()))
				{
					levelController->incrementScore();
				}
				else
				{
					levelController->decrementScore();
				}

				// Resets everything for next order
				scoreNumLabel->Text = levelController->getScore().ToString();
				orderTimeCounter = 0;
				for (int i = 0; i < itemCount; i++)
				{
					playerBurger->ClearBurger();
				}
				playerActionController->getSides()->reset();
				BurgerPanel->Controls->Clear();
				BurgerPanel->Invalidate();
				this->Invalidate();
			}
			else if (e->KeyCode == Keys::D)
			{
				//make command and add it to the invoker
				Command* tempCommand = new AddDrinkCommand(playerActionController);
				invoker->doCommand(tempCommand);
				this->Invalidate();
			}
			else if (e->KeyCode == Keys::F)
			{
				//make command and add it to the invoker
				Command* tempCommand = new AddFriesCommand(playerActionController);
				invoker->doCommand(tempCommand);
				this->Invalidate();
			}
			else
			{
				if (playerBurger->sizeOfBurger() < 15)
				{
					//make ingredient
					char input = Convert::ToChar(e->KeyCode);
					IngredientsSimpleFactory* factory = new IngredientsSimpleFactory();
					Ingredients* newIngredient = factory->makeIngredient(input);
					//make command

					if (newIngredient != nullptr)
					{
						Command* addNewIngredient = new AddIngredientCommand(playerActionController, newIngredient);
						//do the command
						invoker->doCommand(addNewIngredient);
						this->Invalidate();
						itemCount++;
					}
				}
				else
					richTextBox1->Text = "You cannot add more ingredients to the burger. Submit or Trash Order.";
			}
		}
	}
	//---------------------------------------------------------------------
	// Goes to the LevelSelect screen
	//---------------------------------------------------------------------
	private: System::Void ShowLevels_Click(System::Object^ sender, System::EventArgs^ e) {
		MainScreen->Visible = false;
		LevelSelect->Visible = true;
		gameController = new GameController();
		playerActionController = new PlayerActionController();
		levelController = new LevelController();
		playerBurger = playerActionController->getPlayerBurger();
		disableLevelButtons();
	}
	//---------------------------------------------------------------------
	//Disable correct buttons
	//---------------------------------------------------------------------
	private: void disableLevelButtons()
	{
		Level2->Enabled = true;
		Level3->Enabled = true;
		Level4->Enabled = true;
		Level5->Enabled = true;
		Level6->Enabled = true;
		Level7->Enabled = true;
		Level8->Enabled = true;
		Level9->Enabled = true;
		Level10->Enabled = true;

		//check each level and disable the button if appropriate
		levelController->setCurrentLevelNum(2);
		if (levelController->checkStatus())
		{
			Level2->Enabled = false;
		}
		levelController->setCurrentLevelNum(3);
		if (levelController->checkStatus())
		{
			Level3->Enabled = false;
		}
		levelController->setCurrentLevelNum(4);
		if (levelController->checkStatus())
		{
			Level4->Enabled = false;
		}
		levelController->setCurrentLevelNum(5);
		if (levelController->checkStatus())
		{
			Level5->Enabled = false;
		}
		levelController->setCurrentLevelNum(6);
		if (levelController->checkStatus())
		{
			Level6->Enabled = false;
		}
		levelController->setCurrentLevelNum(7);
		if (levelController->checkStatus())
		{
			Level7->Enabled = false;
		}
		levelController->setCurrentLevelNum(8);
		if (levelController->checkStatus())
		{
			Level8->Enabled = false;
		}
		levelController->setCurrentLevelNum(9);
		if (levelController->checkStatus())
		{
			Level9->Enabled = false;
		}
		levelController->setCurrentLevelNum(10);
		if (levelController->checkStatus())
		{
			Level10->Enabled = false;
		}
	}
	//---------------------------------------------------------------------
	// Exits the game
	//---------------------------------------------------------------------
	private: System::Void ExitGame_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	//---------------------------------------------------------------------
	// Goes to the Store Screen
	//---------------------------------------------------------------------
	private: System::Void ShowStore_Click(System::Object^ sender, System::EventArgs^ e) {
		//makes main panel non-visible, and makes store visible
		MainScreen->Visible = false;
		StoreScreen->Visible = true;
	}
	//---------------------------------------------------------------------
	// Goes back to the MainScreen from Store
	//---------------------------------------------------------------------
	private: System::Void StoreBackBut_Click(System::Object^ sender, System::EventArgs^ e) {
		StoreScreen->Visible = false;
		MainScreen->Visible = true;
	}
	//---------------------------------------------------------------------
	// Goes to the Instructions screen
	//---------------------------------------------------------------------
	private: System::Void ShowInstructions_Click(System::Object^ sender, System::EventArgs^ e) {
		MainScreen->Visible = false;
		Instructions->Visible = true;
	}
	//--------------------------------------------------------------------- 
	// Goes back to the HomeScreen from the LevelSelect screen
	//---------------------------------------------------------------------
	private: System::Void Home_Click(System::Object^ sender, System::EventArgs^ e) {
		LevelSelect->Visible = false;
		MainScreen->Visible = true;
	}
	//---------------------------------------------------------------------
	// Starts level 1
	//---------------------------------------------------------------------
	private: System::Void Level1_Click(System::Object^ sender, System::EventArgs^ e) {
		levelController->setCurrentLevelNum(1);
		levelController->populateCurrentLevel();
		LevelSelect->Visible = false;
		GameScreen->Visible = true;
		BurgerPanel->Visible = true;
		highScoreNumLabel->Text = levelController->getHighScore().ToString();
		lvlNumber->Text = "1";
		this->Select();
		displayOrder();
		orderTimer->Start();
		scoreNumLabel->Text = "0";
		currLevel = 1;
	}
	//---------------------------------------------------------------------
	// Checks and starts level 2
	//---------------------------------------------------------------------
	private: System::Void Level2_Click(System::Object^ sender, System::EventArgs^ e) {
		levelController->setCurrentLevelNum(2);
		if (!levelController->checkStatus()) {
			levelController->populateCurrentLevel();
			LevelSelect->Visible = false;
			GameScreen->Visible = true;
			BurgerPanel->Visible = true;
			GameScreen->BackColor = System::Drawing::Color::Turquoise;
			highScoreNumLabel->Text = levelController->getHighScore().ToString();
			lvlNumber->Text = "2";
			this->Select();
			displayOrder();
			orderTimer->Start();
			scoreNumLabel->Text = "0";
			currLevel = 2;
		}
	}
	//---------------------------------------------------------------------
	// Checks and starts level 3
	//---------------------------------------------------------------------
	private: System::Void Level3_Click(System::Object^ sender, System::EventArgs^ e) {
		levelController->setCurrentLevelNum(3);
		if (!levelController->checkStatus()) {
			levelController->populateCurrentLevel();
			LevelSelect->Visible = false;
			GameScreen->Visible = true;
			BurgerPanel->Visible = true;
			GameScreen->BackColor = System::Drawing::Color::Gold;
			highScoreNumLabel->Text = levelController->getHighScore().ToString();
			lvlNumber->Text = "3";
			this->Select();
			displayOrder();
			orderTimer->Start();
			scoreNumLabel->Text = "0";
			currLevel = 3;
		}
	}
	//---------------------------------------------------------------------
	// Checks and starts level 4
	//---------------------------------------------------------------------
	private: System::Void Level4_Click(System::Object^ sender, System::EventArgs^ e) {
		levelController->setCurrentLevelNum(4);
		if (!levelController->checkStatus()) {
			levelController->populateCurrentLevel();
			LevelSelect->Visible = false;
			GameScreen->Visible = true;
			BurgerPanel->Visible = true;
			GameScreen->BackColor = System::Drawing::Color::Brown;
			highScoreNumLabel->Text = levelController->getHighScore().ToString();
			lvlNumber->Text = "4";
			this->Select();
			displayOrder();
			orderTimer->Start();
			scoreNumLabel->Text = "0";
			currLevel = 4;
		}
	}
	//---------------------------------------------------------------------
	// Checks and starts level 5
	//---------------------------------------------------------------------
	private: System::Void Level5_Click(System::Object^ sender, System::EventArgs^ e) {
		levelController->setCurrentLevelNum(5);
		if (!levelController->checkStatus()) {
			levelController->populateCurrentLevel();
			LevelSelect->Visible = false;
			GameScreen->Visible = true;
			BurgerPanel->Visible = true;
			GameScreen->BackColor = System::Drawing::Color::Violet;
			highScoreNumLabel->Text = levelController->getHighScore().ToString();
			lvlNumber->Text = "5";
			this->Select();
			displayOrder();
			orderTimer->Start();
			scoreNumLabel->Text = "0";
			currLevel = 5;
		}
	}
	//---------------------------------------------------------------------
	// Checks and starts level 6
	//---------------------------------------------------------------------
	private: System::Void Level6_Click(System::Object^ sender, System::EventArgs^ e) {
		levelController->setCurrentLevelNum(6);
		if (!levelController->checkStatus()) {
			levelController->populateCurrentLevel();
			LevelSelect->Visible = false;
			GameScreen->Visible = true;
			BurgerPanel->Visible = true;
			GameScreen->BackColor = System::Drawing::Color::Coral;
			highScoreNumLabel->Text = levelController->getHighScore().ToString();
			lvlNumber->Text = "6";
			this->Select();
			displayOrder();
			orderTimer->Start();
			scoreNumLabel->Text = "0";
			currLevel = 6;
		}
	}
	//---------------------------------------------------------------------
	// Checks and starts level 7
	//---------------------------------------------------------------------
	private: System::Void Level7_Click(System::Object^ sender, System::EventArgs^ e) {
		levelController->setCurrentLevelNum(7);
		if (!levelController->checkStatus()) {
			levelController->populateCurrentLevel();
			LevelSelect->Visible = false;
			GameScreen->Visible = true;
			BurgerPanel->Visible = true;
			GameScreen->BackColor = System::Drawing::Color::MediumSeaGreen;
			highScoreNumLabel->Text = levelController->getHighScore().ToString();
			lvlNumber->Text = "7";
			this->Select();
			displayOrder();
			orderTimer->Start();
			scoreNumLabel->Text = "0";
			currLevel = 7;
		}
	}
	//---------------------------------------------------------------------
	// Checks and starts level 8
	//---------------------------------------------------------------------
	private: System::Void Level8_Click(System::Object^ sender, System::EventArgs^ e) {
		levelController->setCurrentLevelNum(8);
		if (!levelController->checkStatus()) {
			levelController->populateCurrentLevel();
			LevelSelect->Visible = false;
			GameScreen->Visible = true;
			BurgerPanel->Visible = true;
			GameScreen->BackColor = System::Drawing::Color::Orchid;
			highScoreNumLabel->Text = levelController->getHighScore().ToString();
			lvlNumber->Text = "8";
			this->Select();
			displayOrder();
			orderTimer->Start();
			scoreNumLabel->Text = "0";
			currLevel = 8;
		}
	}
	//---------------------------------------------------------------------
	// Checks and starts level 9
	//---------------------------------------------------------------------
	private: System::Void Level9_Click(System::Object^ sender, System::EventArgs^ e) {
		levelController->setCurrentLevelNum(9);
		if (!levelController->checkStatus()) {
			levelController->populateCurrentLevel();
			LevelSelect->Visible = false;
			GameScreen->Visible = true;
			BurgerPanel->Visible = true;
			GameScreen->BackColor = System::Drawing::Color::CornflowerBlue;
			highScoreNumLabel->Text = levelController->getHighScore().ToString();
			lvlNumber->Text = "9";
			this->Select();
			displayOrder();
			orderTimer->Start();
			scoreNumLabel->Text = "0";
			currLevel = 9;
		}
	}
	//---------------------------------------------------------------------
	// Checks and starts level 10
	//---------------------------------------------------------------------
	private: System::Void Level10_Click(System::Object^ sender, System::EventArgs^ e) {
		levelController->setCurrentLevelNum(10);
		if (!levelController->checkStatus()) {
			levelController->populateCurrentLevel();
			LevelSelect->Visible = false;
			GameScreen->Visible = true;
			BurgerPanel->Visible = true;
			GameScreen->BackColor = System::Drawing::Color::Teal;
			highScoreNumLabel->Text = levelController->getHighScore().ToString();
			lvlNumber->Text = "10";
			this->Select();
			displayOrder();
			orderTimer->Start();
			scoreNumLabel->Text = "0";
			currLevel = 10;
		}
	}
	//---------------------------------------------------------------------
	// Brings up the exit level pop up
	//---------------------------------------------------------------------
	private: System::Void exitLvlBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		orderTimer->Stop();
		exitLvlPop->BringToFront();
		exitLvlPop->Visible = true;
	}
	//---------------------------------------------------------------------
	// Checks the PlayerBurger for display purposes
	//---------------------------------------------------------------------
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (playerBurger != nullptr)
		{
			this->Invalidate();
		}
	}
	//---------------------------------------------------------------------
	// Draws the burger and sides
	//---------------------------------------------------------------------
	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (gameController != nullptr && playerBurger != nullptr)
		{
			playerBurger = playerActionController->getPlayerBurger();
			Graphics^ g = BurgerPanel->CreateGraphics();
			Ingredients* tempIngredient;
			Bitmap^ image;
			std::string ingredient;

			//draw the sides if appropriate
			Sides* tempSides = playerActionController->getSides();
			if (tempSides->getAddedDrink())
			{
				image = imageSelector->getImage("Drink");
				g->DrawImageUnscaled(image, 0, 100);
			}
			if (tempSides->getAddedFries())
			{
				image = imageSelector->getImage("Fries");
				g->DrawImageUnscaled(image, 325, 125);
			}

			//draw the burger
			int startX = 200;
			int startY = 200;
			for (int i = 0; i < playerBurger->sizeOfBurger(); i++)
			{
				tempIngredient = playerBurger->getIngredient(i);
				ingredient = tempIngredient->getName();
				image = imageSelector->getImage(ingredient);
				g->DrawImageUnscaled(image, startX, startY);
				startY = startY - 25;
			}
		}
	}
	//---------------------------------------------------------------------
	// Displays the instuctions in game
	//---------------------------------------------------------------------
	private: System::Void gameInstructionsBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		richTextBox1->Text = "G = Top Bun\tB = Bottom Bun\t\tC = Cheese\tD = Drink\tF = Fries\n\nK = Ketchup\tL = Lettuce\t\tM = Mustard\tP = Patty\tT = Tomato\n\nW = Trash Burger\tE = Empty Trash Can\t\tSpacebar = Submit Order";
	}
	//---------------------------------------------------------------------
	// Goes back to the MainScreen from Instructions
	//---------------------------------------------------------------------
	private: System::Void instructBack_Click(System::Object^ sender, System::EventArgs^ e) {
		Instructions->Visible = false;
		MainScreen->Visible = true;
	}
	//---------------------------------------------------------------------
	// Checks to see if the player has either won or lost the level
	//---------------------------------------------------------------------
	private: System::Void orderTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (orderTimeCounter <= 0)
		{
			// Checks if there is another order
			if (levelController->hasNextOrder())
			{
				displayOrder();
			}
			// There are no other orders so level is over
			else
			{
				orderTimer->Stop();
				// The player beat the level
				if (levelController->isBeat())
				{
					levelController->unlockNextLevel();
					levelController->setIfHighScore();
					levelController->reset();
					playerActionController->resetPlayerBurger();
					disableLevelButtons();

					winLvlPop->Visible = true;
					winLvlPop->BringToFront();
					winEndTime = 5;
					winLevelTimer->Start();
				}
				// The player lost the level
				else
				{
					levelController->reset();
					playerActionController->resetPlayerBurger();
					loseLvlPop->Visible = true;
					loseLvlPop->BringToFront();
					loseEndTime = 5;
					loseLevelTimer->Start();
					disableLevelButtons();
				}
			}
		}
		else
		{
			orderTimeCounter--;
			timeLeftLabel->Text = orderTimeCounter.ToString();
		}
	}
	//---------------------------------------------------------------------
	// Starts the countdown to restart the level if the user lost
	//---------------------------------------------------------------------
	private: System::Void loseLevelTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (loseEndTime <= 0) {
			loseLevelTimer->Stop();

			levelController->reset();
			playerActionController->resetPlayerBurger();
			
			levelController->setCurrentLevelNum(currLevel);
			levelController->populateCurrentLevel();
			loseLvlPop->Visible = false;
			highScoreNumLabel->Text = levelController->getHighScore().ToString();
			lvlNumber->Text = currLevel.ToString();
			this->Select();
			displayOrder();
			orderTimer->Start();
			loseEndTime = 5;
			scoreNumLabel->Text = "0";
			loseCountDownTime->Text = "5";
		}
		else {
			loseEndTime--;
			loseCountDownTime->Text = loseEndTime.ToString();
		}
	}
	//---------------------------------------------------------------------
	// Starts the countdown to go to the next level if the user won
	//---------------------------------------------------------------------
	private: System::Void winLevelTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (winEndTime <= 0) {
			winLevelTimer->Stop();
			currLevel++;

			levelController->reset();
			playerActionController->resetPlayerBurger();
			levelController->setCurrentLevelNum(currLevel);
			
			if (currLevel == 1)
				GameScreen->BackColor = System::Drawing::Color::DarkOrange;
			else if (currLevel == 2)
				GameScreen->BackColor = System::Drawing::Color::Turquoise;
			else if (currLevel == 3)
				GameScreen->BackColor = System::Drawing::Color::Gold;
			else if (currLevel == 4)
				GameScreen->BackColor = System::Drawing::Color::Brown;
			else if (currLevel == 5)
				GameScreen->BackColor = System::Drawing::Color::Violet;
			else if (currLevel == 6)
				GameScreen->BackColor = System::Drawing::Color::Coral;
			else if (currLevel == 7)
				GameScreen->BackColor = System::Drawing::Color::MediumSeaGreen;
			else if (currLevel == 8)
				GameScreen->BackColor = System::Drawing::Color::Orchid;
			else if (currLevel == 9)
				GameScreen->BackColor = System::Drawing::Color::CornflowerBlue;
			else if (currLevel == 10)
				GameScreen->BackColor = System::Drawing::Color::Teal;
			
			levelController->populateCurrentLevel();
			winLvlPop->Visible = false;
			highScoreNumLabel->Text = levelController->getHighScore().ToString();
			lvlNumber->Text = currLevel.ToString();
			this->Select();
			winEndTime = 5;
			orderTimer->Start();
			scoreNumLabel->Text = "0";
			winCountDownLvl->Text = "5";
		}
		else {
			winEndTime--;
			winCountDownLvl->Text = winEndTime.ToString();
		}
	}
	//---------------------------------------------------------------------
	// Displays the orders
	//---------------------------------------------------------------------
	private: void displayOrder() {
		Order* tempOrder = levelController->nextOrder();
		String^ listOfIngredients = "Order: \n\n";
		Ingredients* tempIngredient;

		//output each ingredient and if it has a drink and a side, output those
		while (tempOrder->hasNextIngredient())
		{
			tempIngredient = tempOrder->nextIngredient();
			listOfIngredients += gcnew String(tempIngredient->getName().data()) + "\n";
		}

		listOfIngredients += "\n" + "Sides: \n\n";
		if (tempOrder->getHasDrink())
		{
			listOfIngredients += "Drink \n";
		}
		if (tempOrder->getHasFries())
		{
			listOfIngredients += "Fries \n";
		}

		//set the text box to the ingredients
		richTextBox2->ResetText();
		richTextBox2->Text = listOfIngredients;

		//reset the order counter
		orderTimeCounter = 15;
	}
	//---------------------------------------------------------------------
	// Brings up the pop up for exiting a level
	//---------------------------------------------------------------------
	private: System::Void exitLvlYes_Click(System::Object^ sender, System::EventArgs^ e) {
		exitLvlPop->Visible = false;
		GameScreen->Visible = false;
		LevelSelect->Visible = true;
		richTextBox1->Text = "";
		levelController->reset();
		playerActionController->resetPlayerBurger();
		disableLevelButtons();
	}
	//---------------------------------------------------------------------
	// Resumes the level
	//---------------------------------------------------------------------
	private: System::Void exitLvlNo_Click(System::Object^ sender, System::EventArgs^ e) {
		exitLvlPop->Visible = false;
		orderTimer->Start();
	}
	//---------------------------------------------------------------------
	// Sends the player back to the level select screen after winning
	//---------------------------------------------------------------------
	private: System::Void winButton_Click(System::Object^ sender, System::EventArgs^ e) {
		winLvlPop->Visible = false;
		GameScreen->Visible = false;
		LevelSelect->Visible = true;
		winLevelTimer->Stop();
		disableLevelButtons();
		winEndTime = 5;
		richTextBox1->Text = "";
	}
	//---------------------------------------------------------------------
	// Sends the player back to the level select screen after losing
	//---------------------------------------------------------------------
	private: System::Void loseLvlBut_Click(System::Object^ sender, System::EventArgs^ e) {
		loseLvlPop->Visible = false;
		GameScreen->Visible = false;
		MainScreen->Visible = true;
		loseLevelTimer->Stop();
		disableLevelButtons();
		loseEndTime = 5;
		richTextBox1->Text = "";
	}
};
}