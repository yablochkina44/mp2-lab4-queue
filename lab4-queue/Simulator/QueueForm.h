#pragma once
#include "../lab4-queue/TQueue.h"

namespace Simulator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class QueueForm : public System::Windows::Forms::Form
	{
		int MaxSize;
		int Size;
		double p;
		double q;
		int PopCount;
		int PushCount;

		TQueue<int>* quq;
		int x0, y0, w0, h0;
		Graphics^ gr;
		Random^ rnd1;
		Pen^ GoldPen;
		Pen^ WhitePen;

	private: System::Windows::Forms::Label^ label_push;
	private: System::Windows::Forms::Label^ label_pop;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
		  
	public:
		QueueForm(void)
		{
			InitializeComponent();

			gr = CreateGraphics();
			rnd1 = gcnew Random(); // датчик случайных чисел
			GoldPen = gcnew Pen(Color::Gold);
			GoldPen->Width = 10.0F;
			WhitePen = gcnew Pen(SystemColors::Control);
			WhitePen->Width = 10.0F;

			x0 = 395;
			y0 = 30;
			w0 = 130;
			h0 = 130;
			PopCount = 0;
			PushCount = 0;
		}

	protected:
		~QueueForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox1_maxlen;
	private: System::Windows::Forms::TextBox^ textBox2_len;
	private: System::Windows::Forms::TextBox^ textBox3_p;
	private: System::Windows::Forms::TextBox^ textBox4_q;
	private: System::Windows::Forms::Button^ button_start;
	private: System::Windows::Forms::Button^ button2_stop;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	private:
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1_maxlen = (gcnew System::Windows::Forms::TextBox());
			this->textBox2_len = (gcnew System::Windows::Forms::TextBox());
			this->textBox3_p = (gcnew System::Windows::Forms::TextBox());
			this->textBox4_q = (gcnew System::Windows::Forms::TextBox());
			this->button_start = (gcnew System::Windows::Forms::Button());
			this->button2_stop = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label_push = (gcnew System::Windows::Forms::Label());
			this->label_pop = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(37, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(209, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Максимальная длина очереди";
		
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(38, 69);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(175, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Исходная длина очереди";
		
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(38, 102);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(192, 17);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Шанс добавления элемента";
	
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(37, 137);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(191, 17);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Шанс извлечения элемента";
			// 
			// textBox1_maxlen
			// 
			this->textBox1_maxlen->Location = System::Drawing::Point(262, 36);
			this->textBox1_maxlen->Name = L"textBox1_maxlen";
			this->textBox1_maxlen->Size = System::Drawing::Size(100, 20);
			this->textBox1_maxlen->TabIndex = 4;
			this->textBox1_maxlen->TextChanged += gcnew System::EventHandler(this, &QueueForm::textBox1_maxlen_TextChanged);
			// 
			// textBox2_len
			// 
			this->textBox2_len->Location = System::Drawing::Point(262, 69);
			this->textBox2_len->Name = L"textBox2_len";
			this->textBox2_len->Size = System::Drawing::Size(100, 20);
			this->textBox2_len->TabIndex = 5;
			// 
			// textBox3_p
			// 
			this->textBox3_p->Location = System::Drawing::Point(262, 102);
			this->textBox3_p->Name = L"textBox3_p";
			this->textBox3_p->Size = System::Drawing::Size(100, 20);
			this->textBox3_p->TabIndex = 6;
			// 
			// textBox4_q
			// 
			this->textBox4_q->Location = System::Drawing::Point(262, 137);
			this->textBox4_q->Name = L"textBox4_q";
			this->textBox4_q->Size = System::Drawing::Size(100, 20);
			this->textBox4_q->TabIndex = 7;
			// 
			// button_start
			// 
			this->button_start->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_start->Location = System::Drawing::Point(41, 185);
			this->button_start->Name = L"button_start";
			this->button_start->Size = System::Drawing::Size(95, 33);
			this->button_start->TabIndex = 8;
			this->button_start->Text = L"Старт";
			this->button_start->UseVisualStyleBackColor = true;
			this->button_start->Click += gcnew System::EventHandler(this, &QueueForm::button_start_Click);
			// 
			// button2_stop
			// 
			this->button2_stop->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2_stop->Location = System::Drawing::Point(174, 185);
			this->button2_stop->Name = L"button2_stop";
			this->button2_stop->Size = System::Drawing::Size(95, 33);
			this->button2_stop->TabIndex = 9;
			this->button2_stop->Text = L"Стоп";
			this->button2_stop->UseVisualStyleBackColor = true;
			this->button2_stop->Click += gcnew System::EventHandler(this, &QueueForm::button2_stop_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &QueueForm::timer1_Tick);
			// 
			// label_push
			// 
			this->label_push->AutoSize = true;
			this->label_push->Location = System::Drawing::Point(419, 185);
			this->label_push->Name = L"label_push";
			this->label_push->Size = System::Drawing::Size(13, 13);
			this->label_push->TabIndex = 10;
			this->label_push->Text = L"0";
			// 
			// label_pop
			// 
			this->label_pop->AutoSize = true;
			this->label_pop->Location = System::Drawing::Point(481, 185);
			this->label_pop->Name = L"label_pop";
			this->label_pop->Size = System::Drawing::Size(13, 13);
			this->label_pop->TabIndex = 11;
			this->label_pop->Text = L"0";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(419, 205);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(31, 13);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Push";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(481, 205);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(26, 13);
			this->label8->TabIndex = 13;
			this->label8->Text = L"Pop";
			// 
			// QueueForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(562, 240);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label_pop);
			this->Controls->Add(this->label_push);
			this->Controls->Add(this->button2_stop);
			this->Controls->Add(this->button_start);
			this->Controls->Add(this->textBox4_q);
			this->Controls->Add(this->textBox3_p);
			this->Controls->Add(this->textBox2_len);
			this->Controls->Add(this->textBox1_maxlen);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"QueueForm";
			this->Text = L"QueueForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void button_start_Click(System::Object^ sender, System::EventArgs^ e) {
			MaxSize = Convert::ToInt32(textBox1_maxlen->Text);
			Size = Convert::ToInt32(textBox2_len->Text);
			p = Convert::ToDouble(textBox3_p->Text);
			q = Convert::ToDouble(textBox4_q->Text);

			quq = new TQueue<int>(MaxSize);
			for (int i = 0; i < Size; i++)
			{
				quq->Push(1);
			}
			Draww();
			timer1->Enabled = true;
		}
		void Draww()
		{
			int start = 360 * quq->TopHead() / quq->GetMaxsize();
			int finish = 360 * (quq->GetLen()) / quq->GetMaxsize();
			gr->DrawArc(GoldPen, x0, y0, w0, h0, start, finish);
			 /*дуга некоего элипса который вписан в прямоугольник и имеющий некоторую высоту
			 DrawArc(перо,
			x координата верхнего левого угла прямоугольника,
			y верх левого угла прямоугольника,
			ширина пярмокгольника,
			высота прямоугольника,
			стартовый угол,
			сколько градусов нарисовать)  */
		
		}
		void Clean()
		{
			int start = 360 * quq->TopHead() / quq->GetMaxsize();
			int finish = 360 * (quq->GetLen()) / quq->GetMaxsize();
			gr->DrawArc(WhitePen, x0, y0, w0, h0, start, finish);
		}
	
	private: System::Void textBox1_maxlen_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		Clean();
		if (rnd1->NextDouble() < p)
		{
			if (!quq->IsFull())
			{
				quq->Push(1);
				PushCount++;
			}
		}
		if (rnd1->NextDouble() < q)
		{
			if (!quq->IsEmpty())
			{
				quq->Pop();
				PopCount++;
			}
		}
		Draww();
		label_push->Text = Convert::ToString(PushCount);
		label_pop->Text = Convert::ToString(PopCount);
	}
	private: System::Void button2_stop_Click(System::Object^ sender, System::EventArgs^ e) {
		timer1->Enabled = false;
	}
	};
}

