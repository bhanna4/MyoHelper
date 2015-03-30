#pragma once
#include <iostream>
#include "myoguyo.h"
#include <time.h>
#include <Magick++.h>
using namespace Magick;

namespace hellomyoVisualStudio2012 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for myoNazz
	/// </summary>
	public ref class myoNazz : public System::Windows::Forms::Form
	{
	public:
		time_t start;
		double duration;
		myoNazz(void)
		{
			
			InitializeMagick("C:/Users/baile_000/Documents/myo-sdk-win-0.8.1/myo-sdk-win-0.8.1/samples");
			//InitializeMagick(NULL);
			InitializeComponent();
			duration = 0;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~myoNazz()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^  label1;
	public: System::Windows::Forms::PictureBox^ pictureBox1;
	public: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Button^  button1;
	public: myoguyo guy;
	

	public: void advance()
	{
		this->pictureBox2->Location = System::Drawing::Point(guy.xPos, guy.yPos);
	}

	public: void turn(char orientation)
	{
		switch (orientation)
		{
		case 'u':
			{
				this->pictureBox2->Image = hellomyoVisualStudio2012::Image::FromFile(L"C:/Users/baile_000/Pictures/up.png");
				break;
			}
		case 'd':
			{
				this->pictureBox2->Image = hellomyoVisualStudio2012::Image::FromFile(L"C:/Users/baile_000/Pictures/down.png");
				break;
			}
		case 'l':
			{
				this->pictureBox2->Image = hellomyoVisualStudio2012::Image::FromFile(L"C:/Users/baile_000/Pictures/left.png");
				break;
			}
		case 'r':
			{
				this->pictureBox2->Image = hellomyoVisualStudio2012::Image::FromFile(L"C:/Users/baile_000/Pictures/right.png");
				break;
			}
		case 'y':
			{
				this->pictureBox2->Image = hellomyoVisualStudio2012::Image::FromFile(L"C:/Users/baile_000/Pictures/y.png");
				break;
			}
		case 'i':
			{
				this->pictureBox2->Image = hellomyoVisualStudio2012::Image::FromFile(L"C:/Users/baile_000/Pictures/i.png");
				break;
			}
		case 'h':
			{
				this->pictureBox2->Image = hellomyoVisualStudio2012::Image::FromFile(L"C:/Users/baile_000/Pictures/h.png");
				break;
			}
		case 'k':
			{
				this->pictureBox2->Image = hellomyoVisualStudio2012::Image::FromFile(L"C:/Users/baile_000/Pictures/k.png");
				break;
			}
		default:
			break;
		}
	}

	public: 
		int num;
			void myoNazzFunc(char temp)
			{
				if(temp==102)
				{
					label1->Text="Action is: fist";
					guy.moveForward();
					advance();
				}
				else if(temp==114)
				{
					label1->Text="Action is: rest";
				}
				else if(temp==115)
				{
					label1->Text="Action is: fingersSpread";
					guy.reverse();
					advance();
				}
				else if(temp==105)
				{
					label1->Text="Action is: waveIn";
					char newDirection = guy.changeDirection('l');
					
					start=clock();
					while(duration<400)
					{
						duration = clock() - start;
					}
						turn(newDirection);
						duration = 0;

				}
				else if(temp==111)
				{
					label1->Text="Action is: waveOut";
					char newDirection = guy.changeDirection('r');
					start = clock();
					while(duration<400)
					{
						duration = clock() - start;
					}
					turn(newDirection);
					duration = 0;
				}
				else if(temp==100)
				{
					label1->Text="Action is: doubleTap";
				}
				else 
				{
					label1->Text="Action is: unkown";
					
				}
				label1->Show();
				//Close();
			}
			void closeFunc()
			{
				Close();
			}
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 12);

			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(700, 500);
			this->pictureBox1->BackgroundImage = hellomyoVisualStudio2012::Image::FromFile("C:/Users/baile_000/Pictures/houselayout.png");
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->SendToBack();
						
			
			//image->rotate(10);
			//image->display();
			this->pictureBox2->Location = System::Drawing::Point(guy.xPos, guy.yPos);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(25, 25);
			//this->pictureBox2->Image = Magick::Image::draw("C:/Users/baile_000/Pictures/right.png");
			this->pictureBox2->Image = hellomyoVisualStudio2012::Image::FromFile("C:/Users/baile_000/Pictures/right.png");
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->BringToFront();

			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(371, 500);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &myoNazz::button1_Click);
			// 
			// myoNazz
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(700, 500);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"myoNazz";
			this->Text = L"myoNazz";
			this->Load += gcnew System::EventHandler(this, &myoNazz::myoNazz_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void myoNazz_Load(System::Object^  sender, System::EventArgs^  e) {
			 }

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 Close();
			 }
};
}
