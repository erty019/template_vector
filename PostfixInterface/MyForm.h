#pragma once

#include "Postfix.h"
#include <msclr\marshal_cppstd.h>
namespace PostfixInterface {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ enterBox;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ postfAnswer;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ answerLabel;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->enterBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->postfAnswer = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->answerLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(97, 63);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(143, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введите выражение:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(567, 55);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 28);
			this->button1->TabIndex = 1;
			this->button1->Text = L"решить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// enterBox
			// 
			this->enterBox->Location = System::Drawing::Point(279, 59);
			this->enterBox->Margin = System::Windows::Forms::Padding(4);
			this->enterBox->Name = L"enterBox";
			this->enterBox->Size = System::Drawing::Size(279, 22);
			this->enterBox->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(97, 100);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(148, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Постфиксная форма: ";
			// 
			// postfAnswer
			// 
			this->postfAnswer->AutoSize = true;
			this->postfAnswer->Location = System::Drawing::Point(288, 100);
			this->postfAnswer->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->postfAnswer->Name = L"postfAnswer";
			this->postfAnswer->Size = System::Drawing::Size(0, 16);
			this->postfAnswer->TabIndex = 4;
			this->postfAnswer->Tag = L"label";
			this->postfAnswer->Click += gcnew System::EventHandler(this, &MyForm::postfAnswer_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(97, 138);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(53, 16);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Ответ: ";
			// 
			// answerLabel
			// 
			this->answerLabel->AutoSize = true;
			this->answerLabel->Location = System::Drawing::Point(288, 138);
			this->answerLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->answerLabel->Name = L"answerLabel";
			this->answerLabel->Size = System::Drawing::Size(0, 16);
			this->answerLabel->TabIndex = 6;
			this->answerLabel->Tag = L"label";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1047, 558);
			this->Controls->Add(this->answerLabel);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->postfAnswer);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->enterBox);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string s = msclr::interop::marshal_as<std::string>(enterBox->Text);
		MyPostf calc(s);
		calc.ToPostfix();
		calc.Calculate();
		postfAnswer->Text = Convert::ToString(calc.GetResult());
		
	}
private: System::Void postfAnswer_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
