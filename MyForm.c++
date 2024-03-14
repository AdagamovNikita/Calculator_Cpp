#pragma once

namespace CalculatorEXAM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
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
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_exit;
	private: System::Windows::Forms::Label^ result_label;
	private: System::Windows::Forms::Button^ btn_ac;
	private: System::Windows::Forms::Button^ btn_minus_plus;
	private: System::Windows::Forms::Button^ btn_percent;






	private: System::Windows::Forms::Button^ btn_divide;

	private: System::Windows::Forms::Button^ sem;
	private: System::Windows::Forms::Button^ devyt;
	private: System::Windows::Forms::Button^ btn_mult;










	private: System::Windows::Forms::Button^ chetyre;
	private: System::Windows::Forms::Button^ pyt;
	private: System::Windows::Forms::Button^ shest;
	private: System::Windows::Forms::Button^ btn_minus;






	private: System::Windows::Forms::Button^ odyn;
	private: System::Windows::Forms::Button^ dva;
	private: System::Windows::Forms::Button^ tri;
	private: System::Windows::Forms::Button^ btn_plus;

	private: System::Windows::Forms::Button^ nol;
	private: System::Windows::Forms::Button^ btn_dot;








	private: System::Windows::Forms::Button^ btn_equal;



	private: System::Windows::Forms::Button^ vosem;
	private: float first_num;
	private: char user_action;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: bool is_equal = false;
	protected:

	protected:


	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button_exit = (gcnew System::Windows::Forms::Button());
			this->result_label = (gcnew System::Windows::Forms::Label());
			this->btn_ac = (gcnew System::Windows::Forms::Button());
			this->btn_minus_plus = (gcnew System::Windows::Forms::Button());
			this->btn_percent = (gcnew System::Windows::Forms::Button());
			this->btn_divide = (gcnew System::Windows::Forms::Button());
			this->sem = (gcnew System::Windows::Forms::Button());
			this->vosem = (gcnew System::Windows::Forms::Button());
			this->devyt = (gcnew System::Windows::Forms::Button());
			this->btn_mult = (gcnew System::Windows::Forms::Button());
			this->chetyre = (gcnew System::Windows::Forms::Button());
			this->pyt = (gcnew System::Windows::Forms::Button());
			this->shest = (gcnew System::Windows::Forms::Button());
			this->btn_minus = (gcnew System::Windows::Forms::Button());
			this->odyn = (gcnew System::Windows::Forms::Button());
			this->dva = (gcnew System::Windows::Forms::Button());
			this->tri = (gcnew System::Windows::Forms::Button());
			this->btn_plus = (gcnew System::Windows::Forms::Button());
			this->nol = (gcnew System::Windows::Forms::Button());
			this->btn_dot = (gcnew System::Windows::Forms::Button());
			this->btn_equal = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button_exit
			// 
			this->button_exit->BackColor = System::Drawing::Color::Transparent;
			this->button_exit->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_exit.BackgroundImage")));
			this->button_exit->Font = (gcnew System::Drawing::Font(L"MV Boli", 4.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_exit->Location = System::Drawing::Point(16, 14);
			this->button_exit->Margin = System::Windows::Forms::Padding(2);
			this->button_exit->Name = L"button_exit";
			this->button_exit->Size = System::Drawing::Size(30, 24);
			this->button_exit->TabIndex = 0;
			this->button_exit->Text = L"X";
			this->button_exit->UseVisualStyleBackColor = false;
			this->button_exit->Click += gcnew System::EventHandler(this, &MyForm::button_exit_Click);
			// 
			// result_label
			// 
			this->result_label->BackColor = System::Drawing::Color::Transparent;
			this->result_label->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->result_label->Font = (gcnew System::Drawing::Font(L"MV Boli", 25.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->result_label->Location = System::Drawing::Point(12, 39);
			this->result_label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->result_label->Name = L"result_label";
			this->result_label->Size = System::Drawing::Size(378, 58);
			this->result_label->TabIndex = 1;
			this->result_label->Text = L"0";
			this->result_label->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// btn_ac
			// 
			this->btn_ac->Font = (gcnew System::Drawing::Font(L"MV Boli", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_ac->Location = System::Drawing::Point(16, 99);
			this->btn_ac->Margin = System::Windows::Forms::Padding(2);
			this->btn_ac->Name = L"btn_ac";
			this->btn_ac->Size = System::Drawing::Size(80, 63);
			this->btn_ac->TabIndex = 2;
			this->btn_ac->Text = L"AC";
			this->btn_ac->UseVisualStyleBackColor = true;
			this->btn_ac->Click += gcnew System::EventHandler(this, &MyForm::btn_ac_Click);
			// 
			// btn_minus_plus
			// 
			this->btn_minus_plus->Font = (gcnew System::Drawing::Font(L"MV Boli", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_minus_plus->Location = System::Drawing::Point(110, 99);
			this->btn_minus_plus->Margin = System::Windows::Forms::Padding(2);
			this->btn_minus_plus->Name = L"btn_minus_plus";
			this->btn_minus_plus->Size = System::Drawing::Size(80, 63);
			this->btn_minus_plus->TabIndex = 3;
			this->btn_minus_plus->Text = L"+/-";
			this->btn_minus_plus->UseVisualStyleBackColor = true;
			this->btn_minus_plus->Click += gcnew System::EventHandler(this, &MyForm::btn_minus_plus_Click);
			// 
			// btn_percent
			// 
			this->btn_percent->Font = (gcnew System::Drawing::Font(L"MV Boli", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_percent->Location = System::Drawing::Point(202, 99);
			this->btn_percent->Margin = System::Windows::Forms::Padding(2);
			this->btn_percent->Name = L"btn_percent";
			this->btn_percent->Size = System::Drawing::Size(80, 63);
			this->btn_percent->TabIndex = 4;
			this->btn_percent->Text = L"%";
			this->btn_percent->UseVisualStyleBackColor = true;
			this->btn_percent->Click += gcnew System::EventHandler(this, &MyForm::btn_percent_Click);
			// 
			// btn_divide
			// 
			this->btn_divide->BackColor = System::Drawing::Color::Transparent;
			this->btn_divide->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->btn_divide->FlatAppearance->BorderSize = 0;
			this->btn_divide->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Red;
			this->btn_divide->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn_divide->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btn_divide->Font = (gcnew System::Drawing::Font(L"MV Boli", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_divide->Location = System::Drawing::Point(298, 99);
			this->btn_divide->Margin = System::Windows::Forms::Padding(2);
			this->btn_divide->Name = L"btn_divide";
			this->btn_divide->Size = System::Drawing::Size(80, 63);
			this->btn_divide->TabIndex = 5;
			this->btn_divide->Text = L"/";
			this->btn_divide->UseVisualStyleBackColor = false;
			this->btn_divide->Click += gcnew System::EventHandler(this, &MyForm::btn_divide_Click);
			// 
			// sem
			// 
			this->sem->Font = (gcnew System::Drawing::Font(L"MV Boli", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sem->Location = System::Drawing::Point(16, 173);
			this->sem->Margin = System::Windows::Forms::Padding(2);
			this->sem->Name = L"sem";
			this->sem->Size = System::Drawing::Size(80, 63);
			this->sem->TabIndex = 6;
			this->sem->Text = L"7";
			this->sem->UseVisualStyleBackColor = true;
			this->sem->Click += gcnew System::EventHandler(this, &MyForm::BtnNumber_Click);
			// 
			// vosem
			// 
			this->vosem->Font = (gcnew System::Drawing::Font(L"MV Boli", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->vosem->Location = System::Drawing::Point(110, 173);
			this->vosem->Margin = System::Windows::Forms::Padding(2);
			this->vosem->Name = L"vosem";
			this->vosem->Size = System::Drawing::Size(80, 63);
			this->vosem->TabIndex = 7;
			this->vosem->Text = L"8";
			this->vosem->UseVisualStyleBackColor = true;
			this->vosem->Click += gcnew System::EventHandler(this, &MyForm::BtnNumber_Click);
			// 
			// devyt
			// 
			this->devyt->Font = (gcnew System::Drawing::Font(L"MV Boli", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->devyt->Location = System::Drawing::Point(202, 173);
			this->devyt->Margin = System::Windows::Forms::Padding(2);
			this->devyt->Name = L"devyt";
			this->devyt->Size = System::Drawing::Size(80, 63);
			this->devyt->TabIndex = 8;
			this->devyt->Text = L"9";
			this->devyt->UseVisualStyleBackColor = true;
			this->devyt->Click += gcnew System::EventHandler(this, &MyForm::BtnNumber_Click);
			// 
			// btn_mult
			// 
			this->btn_mult->Font = (gcnew System::Drawing::Font(L"MV Boli", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_mult->Location = System::Drawing::Point(298, 173);
			this->btn_mult->Margin = System::Windows::Forms::Padding(2);
			this->btn_mult->Name = L"btn_mult";
			this->btn_mult->Size = System::Drawing::Size(80, 63);
			this->btn_mult->TabIndex = 9;
			this->btn_mult->Text = L"*";
			this->btn_mult->UseVisualStyleBackColor = true;
			this->btn_mult->Click += gcnew System::EventHandler(this, &MyForm::btn_mult_Click);
			// 
			// chetyre
			// 
			this->chetyre->Font = (gcnew System::Drawing::Font(L"MV Boli", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->chetyre->Location = System::Drawing::Point(16, 248);
			this->chetyre->Margin = System::Windows::Forms::Padding(2);
			this->chetyre->Name = L"chetyre";
			this->chetyre->Size = System::Drawing::Size(80, 63);
			this->chetyre->TabIndex = 10;
			this->chetyre->Text = L"4";
			this->chetyre->UseVisualStyleBackColor = true;
			this->chetyre->Click += gcnew System::EventHandler(this, &MyForm::BtnNumber_Click);
			// 
			// pyt
			// 
			this->pyt->Font = (gcnew System::Drawing::Font(L"MV Boli", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pyt->Location = System::Drawing::Point(110, 248);
			this->pyt->Margin = System::Windows::Forms::Padding(2);
			this->pyt->Name = L"pyt";
			this->pyt->Size = System::Drawing::Size(80, 63);
			this->pyt->TabIndex = 11;
			this->pyt->Text = L"5";
			this->pyt->UseVisualStyleBackColor = true;
			this->pyt->Click += gcnew System::EventHandler(this, &MyForm::BtnNumber_Click);
			// 
			// shest
			// 
			this->shest->Font = (gcnew System::Drawing::Font(L"MV Boli", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->shest->Location = System::Drawing::Point(202, 248);
			this->shest->Margin = System::Windows::Forms::Padding(2);
			this->shest->Name = L"shest";
			this->shest->Size = System::Drawing::Size(80, 63);
			this->shest->TabIndex = 12;
			this->shest->Text = L"6";
			this->shest->UseVisualStyleBackColor = true;
			this->shest->Click += gcnew System::EventHandler(this, &MyForm::BtnNumber_Click);
			// 
			// btn_minus
			// 
			this->btn_minus->Font = (gcnew System::Drawing::Font(L"MV Boli", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_minus->Location = System::Drawing::Point(298, 245);
			this->btn_minus->Margin = System::Windows::Forms::Padding(2);
			this->btn_minus->Name = L"btn_minus";
			this->btn_minus->Size = System::Drawing::Size(80, 63);
			this->btn_minus->TabIndex = 13;
			this->btn_minus->Text = L"-";
			this->btn_minus->UseVisualStyleBackColor = true;
			this->btn_minus->Click += gcnew System::EventHandler(this, &MyForm::btn_minus_Click);
			// 
			// odyn
			// 
			this->odyn->Font = (gcnew System::Drawing::Font(L"MV Boli", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->odyn->Location = System::Drawing::Point(16, 325);
			this->odyn->Margin = System::Windows::Forms::Padding(2);
			this->odyn->Name = L"odyn";
			this->odyn->Size = System::Drawing::Size(80, 63);
			this->odyn->TabIndex = 14;
			this->odyn->Text = L"1";
			this->odyn->UseVisualStyleBackColor = true;
			this->odyn->Click += gcnew System::EventHandler(this, &MyForm::BtnNumber_Click);
			// 
			// dva
			// 
			this->dva->Font = (gcnew System::Drawing::Font(L"MV Boli", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dva->Location = System::Drawing::Point(110, 325);
			this->dva->Margin = System::Windows::Forms::Padding(2);
			this->dva->Name = L"dva";
			this->dva->Size = System::Drawing::Size(80, 63);
			this->dva->TabIndex = 15;
			this->dva->Text = L"2";
			this->dva->UseVisualStyleBackColor = true;
			this->dva->Click += gcnew System::EventHandler(this, &MyForm::BtnNumber_Click);
			// 
			// tri
			// 
			this->tri->Font = (gcnew System::Drawing::Font(L"MV Boli", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tri->Location = System::Drawing::Point(202, 325);
			this->tri->Margin = System::Windows::Forms::Padding(2);
			this->tri->Name = L"tri";
			this->tri->Size = System::Drawing::Size(80, 63);
			this->tri->TabIndex = 16;
			this->tri->Text = L"3";
			this->tri->UseVisualStyleBackColor = true;
			this->tri->Click += gcnew System::EventHandler(this, &MyForm::BtnNumber_Click);
			// 
			// btn_plus
			// 
			this->btn_plus->Font = (gcnew System::Drawing::Font(L"MV Boli", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_plus->Location = System::Drawing::Point(298, 325);
			this->btn_plus->Margin = System::Windows::Forms::Padding(2);
			this->btn_plus->Name = L"btn_plus";
			this->btn_plus->Size = System::Drawing::Size(80, 63);
			this->btn_plus->TabIndex = 17;
			this->btn_plus->Text = L"+";
			this->btn_plus->UseVisualStyleBackColor = true;
			this->btn_plus->Click += gcnew System::EventHandler(this, &MyForm::btn_plus_Click);
			// 
			// nol
			// 
			this->nol->Font = (gcnew System::Drawing::Font(L"MV Boli", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nol->Location = System::Drawing::Point(16, 400);
			this->nol->Margin = System::Windows::Forms::Padding(2);
			this->nol->Name = L"nol";
			this->nol->Size = System::Drawing::Size(80, 63);
			this->nol->TabIndex = 18;
			this->nol->Text = L"0";
			this->nol->UseVisualStyleBackColor = true;
			this->nol->Click += gcnew System::EventHandler(this, &MyForm::BtnNumber_Click);
			// 
			// btn_dot
			// 
			this->btn_dot->Font = (gcnew System::Drawing::Font(L"MV Boli", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_dot->Location = System::Drawing::Point(110, 400);
			this->btn_dot->Margin = System::Windows::Forms::Padding(2);
			this->btn_dot->Name = L"btn_dot";
			this->btn_dot->Size = System::Drawing::Size(80, 63);
			this->btn_dot->TabIndex = 20;
			this->btn_dot->Text = L".";
			this->btn_dot->UseVisualStyleBackColor = true;
			this->btn_dot->Click += gcnew System::EventHandler(this, &MyForm::btn_dot_Click);
			// 
			// btn_equal
			// 
			this->btn_equal->Font = (gcnew System::Drawing::Font(L"MV Boli", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_equal->Location = System::Drawing::Point(202, 400);
			this->btn_equal->Margin = System::Windows::Forms::Padding(2);
			this->btn_equal->Name = L"btn_equal";
			this->btn_equal->Size = System::Drawing::Size(176, 63);
			this->btn_equal->TabIndex = 21;
			this->btn_equal->Text = L"=";
			this->btn_equal->UseVisualStyleBackColor = true;
			this->btn_equal->Click += gcnew System::EventHandler(this, &MyForm::btn_equal_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(16, 468);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(361, 208);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 22;
			this->pictureBox1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(390, 677);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btn_equal);
			this->Controls->Add(this->btn_dot);
			this->Controls->Add(this->nol);
			this->Controls->Add(this->btn_plus);
			this->Controls->Add(this->tri);
			this->Controls->Add(this->dva);
			this->Controls->Add(this->odyn);
			this->Controls->Add(this->btn_minus);
			this->Controls->Add(this->shest);
			this->Controls->Add(this->pyt);
			this->Controls->Add(this->chetyre);
			this->Controls->Add(this->btn_mult);
			this->Controls->Add(this->devyt);
			this->Controls->Add(this->vosem);
			this->Controls->Add(this->sem);
			this->Controls->Add(this->btn_divide);
			this->Controls->Add(this->btn_percent);
			this->Controls->Add(this->btn_minus_plus);
			this->Controls->Add(this->btn_ac);
			this->Controls->Add(this->button_exit);
			this->Controls->Add(this->result_label);
			this->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Font = (gcnew System::Drawing::Font(L"Segoe Script", 4, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Calculator";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	

	
	private: System::Void button_exit_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void BtnNumber_Click(System::Object^ sender, System::EventArgs^ e) {
		Button^ button = safe_cast<Button^>(sender);

		if (this->result_label->Text == "0" || is_equal) {
			this->result_label->Text = button->Text;
			is_equal = false;
		}
		else
			this->result_label->Text = this->result_label->Text + button->Text;

	}
	private: System::Void btn_plus_Click(System::Object^ sender, System::EventArgs^ e) {
		math_action('+');
	}
	private: System::Void btn_minus_Click(System::Object^ sender, System::EventArgs^ e) {
		math_action('-');
	}
	private: System::Void btn_mult_Click(System::Object^ sender, System::EventArgs^ e) {
		math_action('*');
	}
	private: System::Void btn_divide_Click(System::Object^ sender, System::EventArgs^ e) {
		math_action('/');
	}
	private: System::Void math_action(char action) {
		this->first_num = System::Convert::ToDouble(this->result_label->Text);
		this->user_action = action;
		this->result_label->Text = "0";
	}
	private: System::Void btn_equal_Click(System::Object^ sender, System::EventArgs^ e) {
		if (user_action == ' ')
			return;
		float second = System::Convert::ToDouble(this->result_label->Text);
		float res;
		switch (this->user_action) {
		case '+': res = this->first_num + second; break;
		case '-': res = this->first_num - second; break;
		case '*': res = this->first_num * second; break;
		case '%': res = this->first_num * second / 100; break;
		case '/': 
			if (second == 0) {
				res = 0;
				MessageBox::Show(this, "You can't divide by zero!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		    }
			else
				res = this->first_num / second;
			break;
		}
		this->is_equal = true;
		this->result_label->Text = System::Convert::ToString(res);
	}
	private: System::Void btn_ac_Click(System::Object^ sender, System::EventArgs^ e) {
		this->result_label->Text = "0";
		this->first_num = 0;
		this->user_action = ' ';
		this->is_equal = false;
	}
	private: System::Void btn_minus_plus_Click(System::Object^ sender, System::EventArgs^ e) {
		int num = System::Convert::ToInt32(this->result_label->Text);
		num *= -1;
		this->result_label->Text = System::Convert::ToString(num);
	}
	private: System::Void btn_percent_Click(System::Object^ sender, System::EventArgs^ e) {
		math_action('%');
	}
	private: System::Void btn_dot_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ text = this->result_label->Text;
		if (!text->Contains(","))
			this->result_label->Text = text + ",";
	}
};
}
