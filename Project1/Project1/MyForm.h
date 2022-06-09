#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <typeinfo>

using namespace std;
using namespace System;
using namespace System::Windows::Forms;
extern int iters;

class support
{
public:
	/*Допоміжні функції*/
	int FindDet(int** M, int size); // Пошук визначника
	int** TransposeMatrix(int** M, int size); // Транспонування матриці
	float* MultiplyMandV(int** M, float* V, int size); // Помножити матрицю на вектор
	float ScalarProd(float* V1, float* V2, int size); // Скалярний добуток

};

class SLAR
{
private:
	int** A; // Матриця А (коефіціенти)
	int* b; // Вектор b (вільні члени)
	int size; // розмір системи
	float eps; //точність обчислень
public:
	support funcs;
	float* X1;
	float* X2;
	float* X3;
	float* X4;
	/*Конструктор*/
	SLAR(int** Ainput, int* binput, int sizeinput, float epsinput);
	/*Геттери*/
	int** GetA();
	int* Getb();
	int GetSize();
	float GetEps();
	/*Методи перевірки матриці*/
	bool SilvesterCrit(); // Чи є матриця А додатно-означеною
	bool IsDDominant(); // Чи має матриця А домінантну діагональ
	bool IsOK(float* Xk1, float* Xk); // Умова закінчення ітераційного процесу
	bool IsSimmetrical(); // Чи є матриця А симетричною
	/*Методи розв'язку системи*/
	float* YakobiMethod(); // Метод Якобі
	float* GausMethod(); // Метод Гауса-Зайделя
	float* GradientMethod(); // Метод спряжених градієнтів
};

namespace Project1 {

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
	private: System::Windows::Forms::NumericUpDown^ MatrixSize;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::GroupBox^ groupBox1;



	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::DataGridView^ Matrix;

	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::DataGridView^ Array;


	private: System::Windows::Forms::RichTextBox^ RTB;

	private: System::Windows::Forms::Button^ StartButton;
	private: System::Windows::Forms::CheckBox^ GradientCheckBox;
	private: System::Windows::Forms::CheckBox^ GausCheckBox;
	private: System::Windows::Forms::CheckBox^ YakobiCheckBox;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::NumericUpDown^ EpsNumeric;
	private: System::Windows::Forms::CheckBox^ GraphicCheckBox;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ Chart;










	protected:

	protected:


























	protected:

	protected:

	protected:

	protected:

	protected:

	protected:


	protected:

	protected:

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->MatrixSize = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->GraphicCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->GradientCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->GausCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->YakobiCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->Matrix = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Array = (gcnew System::Windows::Forms::DataGridView());
			this->RTB = (gcnew System::Windows::Forms::RichTextBox());
			this->StartButton = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->EpsNumeric = (gcnew System::Windows::Forms::NumericUpDown());
			this->Chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MatrixSize))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Matrix))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Array))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EpsNumeric))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Chart))->BeginInit();
			this->SuspendLayout();
			// 
			// MatrixSize
			// 
			this->MatrixSize->Location = System::Drawing::Point(291, 61);
			this->MatrixSize->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8, 0, 0, 0 });
			this->MatrixSize->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->MatrixSize->Name = L"MatrixSize";
			this->MatrixSize->Size = System::Drawing::Size(33, 20);
			this->MatrixSize->TabIndex = 0;
			this->MatrixSize->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->MatrixSize->ValueChanged += gcnew System::EventHandler(this, &MyForm::MatrixSize_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(26, 62);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(259, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Кількість невідомих величин в системі:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(119, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(463, 16);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Розв\'язати систему лінійних рівнянь наближеними методами";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->GraphicCheckBox);
			this->groupBox1->Controls->Add(this->GradientCheckBox);
			this->groupBox1->Controls->Add(this->GausCheckBox);
			this->groupBox1->Controls->Add(this->YakobiCheckBox);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(377, 61);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(314, 100);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Методи:";
			// 
			// GraphicCheckBox
			// 
			this->GraphicCheckBox->AutoSize = true;
			this->GraphicCheckBox->Location = System::Drawing::Point(80, 80);
			this->GraphicCheckBox->Name = L"GraphicCheckBox";
			this->GraphicCheckBox->Size = System::Drawing::Size(168, 20);
			this->GraphicCheckBox->TabIndex = 3;
			this->GraphicCheckBox->Text = L"Графічно (тільки 2 х 2)";
			this->GraphicCheckBox->UseVisualStyleBackColor = true;
			// 
			// GradientCheckBox
			// 
			this->GradientCheckBox->AutoSize = true;
			this->GradientCheckBox->Location = System::Drawing::Point(80, 53);
			this->GradientCheckBox->Name = L"GradientCheckBox";
			this->GradientCheckBox->Size = System::Drawing::Size(168, 20);
			this->GradientCheckBox->TabIndex = 2;
			this->GradientCheckBox->Text = L"Спряжених градієнтів";
			this->GradientCheckBox->UseVisualStyleBackColor = true;
			// 
			// GausCheckBox
			// 
			this->GausCheckBox->AutoSize = true;
			this->GausCheckBox->Location = System::Drawing::Point(80, 26);
			this->GausCheckBox->Name = L"GausCheckBox";
			this->GausCheckBox->Size = System::Drawing::Size(125, 20);
			this->GausCheckBox->TabIndex = 1;
			this->GausCheckBox->Text = L"Гауса-Зайделя";
			this->GausCheckBox->UseVisualStyleBackColor = true;
			// 
			// YakobiCheckBox
			// 
			this->YakobiCheckBox->AutoSize = true;
			this->YakobiCheckBox->Location = System::Drawing::Point(80, -1);
			this->YakobiCheckBox->Name = L"YakobiCheckBox";
			this->YakobiCheckBox->Size = System::Drawing::Size(176, 20);
			this->YakobiCheckBox->TabIndex = 0;
			this->YakobiCheckBox->Text = L"Простої ітерації (Якобі)";
			this->YakobiCheckBox->UseVisualStyleBackColor = true;
			// 
			// Matrix
			// 
			this->Matrix->AllowUserToAddRows = false;
			this->Matrix->AllowUserToDeleteRows = false;
			this->Matrix->AllowUserToResizeColumns = false;
			this->Matrix->AllowUserToResizeRows = false;
			this->Matrix->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->Matrix->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Matrix->ColumnHeadersVisible = false;
			this->Matrix->GridColor = System::Drawing::SystemColors::ButtonShadow;
			this->Matrix->Location = System::Drawing::Point(49, 21);
			this->Matrix->Name = L"Matrix";
			this->Matrix->RowHeadersVisible = false;
			this->Matrix->Size = System::Drawing::Size(172, 181);
			this->Matrix->TabIndex = 3;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->Matrix);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox2->Location = System::Drawing::Point(29, 171);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(332, 208);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Матриця коефіцієнтів:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 99);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(30, 16);
			this->label3->TabIndex = 4;
			this->label3->Text = L"A = ";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label4);
			this->groupBox3->Controls->Add(this->Array);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox3->Location = System::Drawing::Point(457, 171);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(174, 208);
			this->groupBox3->TabIndex = 6;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Вектор вільних членів:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(-3, 99);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(29, 16);
			this->label4->TabIndex = 1;
			this->label4->Text = L"b = ";
			// 
			// Array
			// 
			this->Array->AllowUserToAddRows = false;
			this->Array->AllowUserToDeleteRows = false;
			this->Array->AllowUserToResizeColumns = false;
			this->Array->AllowUserToResizeRows = false;
			this->Array->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->Array->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Array->ColumnHeadersVisible = false;
			this->Array->Location = System::Drawing::Point(54, 21);
			this->Array->Name = L"Array";
			this->Array->RowHeadersVisible = false;
			this->Array->Size = System::Drawing::Size(24, 181);
			this->Array->TabIndex = 0;
			// 
			// RTB
			// 
			this->RTB->Location = System::Drawing::Point(122, 385);
			this->RTB->Name = L"RTB";
			this->RTB->ReadOnly = true;
			this->RTB->Size = System::Drawing::Size(569, 115);
			this->RTB->TabIndex = 7;
			this->RTB->Text = L"";
			// 
			// StartButton
			// 
			this->StartButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->StartButton->Location = System::Drawing::Point(12, 400);
			this->StartButton->Name = L"StartButton";
			this->StartButton->Size = System::Drawing::Size(104, 87);
			this->StartButton->TabIndex = 8;
			this->StartButton->Text = L"Розв\'язати";
			this->StartButton->UseVisualStyleBackColor = true;
			this->StartButton->Click += gcnew System::EventHandler(this, &MyForm::StartButton_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(25, 87);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(59, 20);
			this->label6->TabIndex = 10;
			this->label6->Text = L"ε = 10^";
			// 
			// EpsNumeric
			// 
			this->EpsNumeric->Location = System::Drawing::Point(82, 87);
			this->EpsNumeric->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, System::Int32::MinValue });
			this->EpsNumeric->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, System::Int32::MinValue });
			this->EpsNumeric->Name = L"EpsNumeric";
			this->EpsNumeric->Size = System::Drawing::Size(34, 20);
			this->EpsNumeric->TabIndex = 11;
			this->EpsNumeric->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, System::Int32::MinValue });
			// 
			// Chart
			// 
			chartArea1->Name = L"ChartArea1";
			this->Chart->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->Chart->Legends->Add(legend1);
			this->Chart->Location = System::Drawing::Point(12, 506);
			this->Chart->Name = L"Chart";
			series1->BorderWidth = 3;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Color = System::Drawing::Color::Blue;
			series1->Legend = L"Legend1";
			series1->LegendText = L"A[1]";
			series1->Name = L"Series1";
			series2->BorderWidth = 3;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Color = System::Drawing::Color::Red;
			series2->Legend = L"Legend1";
			series2->LegendText = L"A[2]";
			series2->Name = L"Series2";
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series3->Color = System::Drawing::Color::Green;
			series3->Legend = L"Legend1";
			series3->Name = L"Точка перетину";
			this->Chart->Series->Add(series1);
			this->Chart->Series->Add(series2);
			this->Chart->Series->Add(series3);
			this->Chart->Size = System::Drawing::Size(668, 229);
			this->Chart->TabIndex = 12;
			this->Chart->Text = L"chart1";
			this->Chart->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(693, 738);
			this->Controls->Add(this->Chart);
			this->Controls->Add(this->EpsNumeric);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->StartButton);
			this->Controls->Add(this->RTB);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->MatrixSize);
			this->Location = System::Drawing::Point(2, 0);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SLAE solving";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MatrixSize))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Matrix))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Array))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EpsNumeric))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Chart))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	Matrix->ColumnCount = 2; 
	Matrix->RowCount = 2;
	Matrix->AutoResizeColumns();
	Array->ColumnCount = 1;
	Array->RowCount = 2;
	Array->AutoResizeColumns();
}


private: System::Void MatrixSize_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	Matrix->ColumnCount = Convert::ToInt32(MatrixSize->Value);
	Matrix->RowCount = Convert::ToInt32(MatrixSize->Value);
	Matrix->AutoResizeColumns();
	Array->RowCount = Convert::ToInt32(MatrixSize->Value);
	Array->AutoResizeColumns();
	if (MatrixSize->Value != 2) {
		GraphicCheckBox->Enabled = false;
		GraphicCheckBox->Checked = false;
	}
	else {
		GraphicCheckBox->Enabled = true;
	}


}

private: bool DataCheck(int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (Convert::ToInt32(Matrix->Rows[i]->Cells[j]->Value) > 999 || Convert::ToInt32(Matrix->Rows[i]->Cells[j]->Value) < -999) {
				return false;
			}
			
		}
		if (Convert::ToInt32(Array->Rows[i]->Cells[0]->Value) > 999 || Convert::ToInt32(Array->Rows[i]->Cells[0]->Value) < -999) {
			return false;
		}
	}
	return true;
}

private: void ScanMatrix(int** A, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			A[i][j] = Convert::ToInt32(Matrix->Rows[i]->Cells[j]->Value);
			Matrix->AutoResizeColumns();
		}
		
	}
}

private: void ScanArray(int* b, int size) {
	for (int i = 0; i < size; i++) {
		b[i] = Convert::ToInt32(Array->Rows[i]->Cells[0]->Value);
		Array->AutoResizeColumns();
	}
}

private: bool HasNoSolution(int** A) {
	int counter = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (A[i][j] == 0) {
				counter++;
			}
		}
	}
	if (counter >= 3) {
		return true;
	}
	if ((A[0][0] == 0 && A[1][1] == 0) || (A[1][0] == 0 && A[0][1] == 0)) {
		return true;
	}
	if (A[0][1] == 0 || A[1][1] == 0) {
		return true;
	}
	return false;
}

private: void Graphic(int** A, int* b, float* X4, float eps) {
	float x = -max(abs(A[0][0]), max(abs(A[0][1]), max(abs(A[1][0]), abs(A[1][1])))), y1, y2;
	if (abs(x) > 100) {
		eps = pow(10, -1);
	}	
	if (abs(x) > 1000) {
		eps = 1;
	}
	int k = -x;
		while (x <= k) {
			y1 = (b[0] - A[0][0] * x) / A[0][1];
			y2 = (b[1] - A[1][0] * x) / A[1][1];
			if (abs(y2 - y1) < eps) {
				Chart->Series[2]->Points->AddXY(x, y1);
				X4[0] = x; X4[1] = y1;
				break;
			}
			x += eps;

		}
		int t1 = x - 10; int t2 = x + 10;
	
	y1 = (b[0] - A[0][0] * t1) / A[0][1];
	Chart->Series[0]->Points->AddXY(t1, y1);
	y2 = (b[0] - A[0][0] * t2) / A[0][1];
	Chart->Series[0]->Points->AddXY(t2, y2);
	y1 = (b[1] - A[1][0] * t1) / A[1][1];
	Chart->Series[1]->Points->AddXY(t1, y1);
	y2 = (b[1] - A[1][0] * t2) / A[1][1];
	Chart->Series[1]->Points->AddXY(t2, y2);

}

private: void WriteDownResults(SLAR system)
{
	int** Ainf = system.GetA(); int* binf = system.Getb(); 
	int sizeinf = system.GetSize();
	ofstream fout;
	string spaceg, spacel;
	fout.open("results.txt", ios::app);
	fout << "Розмір: " << sizeinf << "\n";
	for (int i = 0; i < sizeinf; i++) {
		for (int j = 0; j < sizeinf; j++) {
			fout << Ainf[i][j] << " ";
		}
		fout << "     " << binf[i] << "\n";
	}
	string txt = "";
	if (YakobiCheckBox->Checked) {
		txt += "\nМетод Якобі: ";
		if (system.IsDDominant()) {
			for (int i = 0; i < sizeinf; i++) {
				txt += "X[" + to_string(i + 1) + "]: " + to_string(system.X1[i]) + " ";
			}
			txt += "\n";
		}
		else { txt += "*Метод не є збіжним*\n"; }
	    
	}
	if (GausCheckBox->Checked) {
		txt += "\nМетод Гауса-Зайделя: ";
		if (system.IsDDominant() || system.SilvesterCrit()) {
			
			for (int i = 0; i < sizeinf; i++) {
				txt += "X[" + to_string(i + 1) + "]: " + to_string(system.X2[i]) + " ";
			}
			txt += "\n";
		}
		else { txt += "*Метод не є збіжним*\n"; }
	}
	if (GradientCheckBox->Checked) {
		txt += "\nМетод спряжених градієнтів: ";
		if (system.SilvesterCrit() && system.IsSimmetrical()) {
			
			for (int i = 0; i < sizeinf; i++) {
				txt += "X[" + to_string(i + 1) + "]: " + to_string(system.X3[i]) + " ";
			}
			txt += "\n";
		}
		else { txt += "*Метод не є збіжним*\n"; }
	}
	if (GraphicCheckBox->Checked) {
        txt += "\nГрафічний метод: ";
		for (int i = 0; i < sizeinf; i++) {
			txt += "X[" + to_string(i + 1) + "]: " + to_string(system.X4[i]) + " ";
		}
		txt += "\n";
	}
	txt += "\n----------------------------------------------------------\n";
	for (int i = 0; i < txt.size(); i++) {
		fout << txt[i];
	}
	fout.close();
}

private: System::Void StartButton_Click(System::Object^ sender, System::EventArgs^ e) {
	Chart->Series[0]->Points->Clear();
	Chart->Series[1]->Points->Clear();
	Chart->Series[2]->Points->Clear();
	support funcs;
	RTB->Text = "";
	if (YakobiCheckBox->Checked == false && GausCheckBox->Checked == false && GradientCheckBox->Checked == false && GraphicCheckBox->Checked == false) {
		MessageBox::Show("Оберіть хоча б один метод", "Помилка!");
		return;
	}
	float epsinput = pow(10, Convert::ToInt32(EpsNumeric->Value));
	int sizeinput = Convert::ToInt32(MatrixSize->Value);
	if (!DataCheck(sizeinput)) {
		MessageBox::Show("Некоректні дані", "Помилка!");
		return;
	}
	int** Ainput = new int* [sizeinput];
	for (int i = 0; i < sizeinput; i++) {
		Ainput[i] = new int[sizeinput];
	}
	ScanMatrix(Ainput, sizeinput);
	int* binput = new int[sizeinput];
	ScanArray(binput, sizeinput);
	SLAR system(Ainput, binput, sizeinput, epsinput);
	if (funcs.FindDet(system.GetA(), system.GetSize()) == 0) {
		MessageBox::Show("Дану систему неможливо розв'язати запропонованими методами, адже визначник матриці А дорівнює нулю", "Увага!");
		return;
	}
	if (YakobiCheckBox->Checked) {
		RTB->Text += "Метод Якобі:\n";
		if (system.IsDDominant()) {
			system.X1 = system.YakobiMethod();
			for (int i = 0; i < system.GetSize(); i++) {
				RTB->Text += "X[" + Convert::ToString(i+1) + "]: " + Convert::ToString(system.X1[i]) + "   ";
			}
			RTB->Text += "\nІтерацій: "+ Convert::ToString(iters) +"\n\n";
		}
		else {
			RTB->Text += "*Метод не є збіжним*\n\n";
		}
	}
	if (GausCheckBox->Checked) {
		RTB->Text += "Метод Гауса-Зайделя:\n";
		if (system.IsDDominant() || system.SilvesterCrit()) {
			system.X2 = system.GausMethod();
			for (int i = 0; i < system.GetSize(); i++) {
				RTB->Text += "X[" + Convert::ToString(i + 1) + "]: " + Convert::ToString(system.X2[i]) + "   ";
			}
			RTB->Text += "\nІтерацій: " + Convert::ToString(iters) + "\n\n";
		}
		else {
			RTB->Text += "*Метод не є збіжним*\n\n";
		}
	}
	if (GradientCheckBox->Checked) {
		RTB->Text += "Метод спряжених градієнтів:\n";
		if (system.SilvesterCrit() && system.IsSimmetrical()) {
			system.X3 = system.GradientMethod();
			for (int i = 0; i < system.GetSize(); i++) {
				RTB->Text += "X[" + Convert::ToString(i + 1) + "]: " + Convert::ToString(system.X3[i]) + "   ";
			}
			RTB->Text += "\nІтерацій: " + Convert::ToString(iters) + "\n\n";
		}
		else {
			RTB->Text += "*Метод не є збіжним*\n\n";
		}

	}
	if (GraphicCheckBox->Checked) {
		RTB->Text += "Грaфічний метод:\n";	
		if (HasNoSolution(system.GetA())) {
			RTB->Text += "*Рішення немає*\n\n";
		}
		else {
			Chart->Visible = true;
			Graphic(system.GetA(), system.Getb(), system.X4, system.GetEps());
			RTB->Text += "x = " + Convert::ToString(system.X4[0]) + "   y = " + Convert::ToString(system.X4[1]);
		}
	}
	else {
		Chart->Visible = false;
	}
	WriteDownResults(system);
	
	
}




};
}

