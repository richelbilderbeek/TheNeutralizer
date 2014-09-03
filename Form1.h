
#pragma once
#include "spatial neutrality.h"
#include <string>
#include "console.h"
#include <iostream>
#include <windows.h> 
#include "container.h"
#include <vcclr.h>
#include <stdlib.h>
#include "imageloader.h"




extern container P;



namespace gui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		
		Form1(void)
		{
			InitializeComponent();
			void set_time(const int& t);
			void set_species(const int& s);
			void add_systemLog(const std::string& text);
			void updateSpeciesChart(const int& val);
			void drawMetaChart(const std::vector<double>& yvals);
			void drawLocalChart(const std::vector<double>& yvals);
			//changeMetaText();
			//
			//TODO: Add the constructor code here
			//
		}
	private: System::Windows::Forms::TextBox^  m;

	public: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  L;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  theta;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  M_size;
	private: System::Windows::Forms::Label^  label6;








	private: System::Windows::Forms::TextBox^  seed;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  specRate;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;

	private: System::Windows::Forms::TextBox^  systemLog;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  speciesChart;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  metaChart;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  localChart;


	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label_time;
	private: System::Windows::Forms::Label^  label_species;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  rankChart;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::Label^  label11;










	private: System::Windows::Forms::Label^  label4;


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;


	private: System::Windows::Forms::Button^  button2;




	private: System::ComponentModel::IContainer^  components;
	protected: 

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea9 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series9 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea10 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series10 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title7 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea11 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series11 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title8 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea12 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series12 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title9 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->m = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->L = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->theta = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->M_size = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->seed = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->specRate = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->systemLog = (gcnew System::Windows::Forms::TextBox());
			this->speciesChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->metaChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->localChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label_time = (gcnew System::Windows::Forms::Label());
			this->label_species = (gcnew System::Windows::Forms::Label());
			this->rankChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label11 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->speciesChart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->metaChart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->localChart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rankChart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(133, 283);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(137, 78);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Run";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(12, 283);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(115, 78);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Update Parameters";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(428, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(271, 18);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Program Copyright Thijs Janzen 2014";
			// 
			// m
			// 
			this->m->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->m->Location = System::Drawing::Point(188, 99);
			this->m->Name = L"m";
			this->m->Size = System::Drawing::Size(82, 31);
			this->m->TabIndex = 9;
			this->m->Text = L"0.01";
			this->m->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(38, 102);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(144, 25);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Migration rate";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(188, 134);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(82, 31);
			this->textBox1->TabIndex = 11;
			this->textBox1->Text = L"1";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// L
			// 
			this->L->AutoSize = true;
			this->L->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->L->Location = System::Drawing::Point(15, 137);
			this->L->Name = L"L";
			this->L->Size = System::Drawing::Size(167, 25);
			this->L->TabIndex = 12;
			this->L->Text = L"Dispersal radius";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Stencil", 32.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(1, 2);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(415, 51);
			this->label3->TabIndex = 13;
			this->label3->Text = L"THE NEUTRALIZER";
			// 
			// theta
			// 
			this->theta->Location = System::Drawing::Point(363, 434);
			this->theta->Name = L"theta";
			this->theta->Size = System::Drawing::Size(47, 20);
			this->theta->TabIndex = 14;
			this->theta->Text = L"42";
			this->theta->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(320, 437);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 13);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Theta";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"Lake.bmp";
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(12, 367);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(115, 47);
			this->button3->TabIndex = 17;
			this->button3->Text = L"Exit";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// M_size
			// 
			this->M_size->Location = System::Drawing::Point(363, 456);
			this->M_size->Name = L"M_size";
			this->M_size->Size = System::Drawing::Size(47, 20);
			this->M_size->TabIndex = 18;
			this->M_size->Text = L"1e6";
			this->M_size->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(284, 459);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(73, 13);
			this->label6->TabIndex = 19;
			this->label6->Text = L"Meta-pop size";
			// 
			// seed
			// 
			this->seed->Location = System::Drawing::Point(363, 408);
			this->seed->Name = L"seed";
			this->seed->Size = System::Drawing::Size(47, 20);
			this->seed->TabIndex = 28;
			this->seed->Text = L"42";
			this->seed->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(284, 411);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(73, 13);
			this->label7->TabIndex = 29;
			this->label7->Text = L"Random seed";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(26, 174);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(156, 25);
			this->label8->TabIndex = 30;
			this->label8->Text = L"Speciation rate";
			// 
			// specRate
			// 
			this->specRate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->specRate->Location = System::Drawing::Point(188, 171);
			this->specRate->Name = L"specRate";
			this->specRate->Size = System::Drawing::Size(82, 31);
			this->specRate->TabIndex = 31;
			this->specRate->Text = L"1e-6";
			this->specRate->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(15, 243);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(59, 25);
			this->label9->TabIndex = 33;
			this->label9->Text = L"Time";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(183, 243);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(107, 25);
			this->label10->TabIndex = 34;
			this->label10->Text = L"# Species";
			// 
			// systemLog
			// 
			this->systemLog->AcceptsReturn = true;
			this->systemLog->AcceptsTab = true;
			this->systemLog->AllowDrop = true;
			this->systemLog->Cursor = System::Windows::Forms::Cursors::WaitCursor;
			this->systemLog->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->systemLog->Location = System::Drawing::Point(12, 422);
			this->systemLog->Multiline = true;
			this->systemLog->Name = L"systemLog";
			this->systemLog->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->systemLog->Size = System::Drawing::Size(258, 56);
			this->systemLog->TabIndex = 36;
			this->systemLog->Text = L"System msg log";
			this->systemLog->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->systemLog->UseWaitCursor = true;
			// 
			// speciesChart
			// 
			chartArea9->AxisX->Title = L"Time";
			chartArea9->AxisY->Maximum = 50;
			chartArea9->AxisY->Minimum = 0;
			chartArea9->AxisY->Title = L"Number of Species";
			chartArea9->Name = L"ChartArea1";
			this->speciesChart->ChartAreas->Add(chartArea9);
			this->speciesChart->Location = System::Drawing::Point(12, 484);
			this->speciesChart->Name = L"speciesChart";
			series9->ChartArea = L"ChartArea1";
			series9->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastLine;
			series9->Color = System::Drawing::Color::Blue;
			series9->Legend = L"Legend1";
			series9->Name = L"Species";
			this->speciesChart->Series->Add(series9);
			this->speciesChart->Size = System::Drawing::Size(398, 215);
			this->speciesChart->TabIndex = 37;
			// 
			// metaChart
			// 
			chartArea10->AxisX->Title = L"Number of Individuals per Species (log2)";
			chartArea10->AxisY->LineColor = System::Drawing::Color::Transparent;
			chartArea10->AxisY->Title = L"Number of Species";
			chartArea10->Name = L"ChartArea1";
			this->metaChart->ChartAreas->Add(chartArea10);
			this->metaChart->Location = System::Drawing::Point(421, 40);
			this->metaChart->Name = L"metaChart";
			series10->ChartArea = L"ChartArea1";
			series10->Name = L"Series1";
			this->metaChart->Series->Add(series10);
			this->metaChart->Size = System::Drawing::Size(277, 215);
			this->metaChart->TabIndex = 38;
			this->metaChart->Text = L"chart1";
			title7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			title7->Name = L"Title1";
			title7->Text = L"Meta Community";
			this->metaChart->Titles->Add(title7);
			// 
			// localChart
			// 
			chartArea11->AxisX->Title = L"Number of Individuals per Species (log2)";
			chartArea11->AxisY->Maximum = 10;
			chartArea11->AxisY->Minimum = 0;
			chartArea11->AxisY->Title = L"Number of Species";
			chartArea11->Name = L"ChartArea1";
			this->localChart->ChartAreas->Add(chartArea11);
			this->localChart->Location = System::Drawing::Point(421, 261);
			this->localChart->Name = L"localChart";
			series11->ChartArea = L"ChartArea1";
			series11->Name = L"Series1";
			this->localChart->Series->Add(series11);
			this->localChart->Size = System::Drawing::Size(277, 215);
			this->localChart->TabIndex = 39;
			this->localChart->Text = L"chart1";
			title8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			title8->Name = L"Title1";
			title8->Text = L"Local Community";
			this->localChart->Titles->Add(title8);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(188, 62);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(82, 31);
			this->textBox3->TabIndex = 42;
			this->textBox3->Text = L"100";
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(128, 65);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(54, 25);
			this->label13->TabIndex = 43;
			this->label13->Text = L"Size";
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(133, 367);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(137, 47);
			this->button4->TabIndex = 44;
			this->button4->Text = L"Stop / reset";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// label_time
			// 
			this->label_time->AutoSize = true;
			this->label_time->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label_time->Location = System::Drawing::Point(80, 243);
			this->label_time->Name = L"label_time";
			this->label_time->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->label_time->Size = System::Drawing::Size(23, 25);
			this->label_time->TabIndex = 45;
			this->label_time->Text = L"0";
			this->label_time->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label_species
			// 
			this->label_species->AutoSize = true;
			this->label_species->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label_species->Location = System::Drawing::Point(296, 243);
			this->label_species->Name = L"label_species";
			this->label_species->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->label_species->Size = System::Drawing::Size(23, 25);
			this->label_species->TabIndex = 46;
			this->label_species->Text = L"1";
			// 
			// rankChart
			// 
			chartArea12->AxisX->MajorGrid->Enabled = false;
			chartArea12->AxisX->Maximum = 50;
			chartArea12->AxisX->Minimum = 0;
			chartArea12->AxisX->Title = L"Species Rank in Abundance";
			chartArea12->AxisY->IsLogarithmic = true;
			chartArea12->AxisY->IsStartedFromZero = false;
			chartArea12->AxisY->MajorGrid->Enabled = false;
			chartArea12->AxisY->Maximum = 400;
			chartArea12->AxisY->Minimum = 0.001;
			chartArea12->AxisY->Title = L"Perecentage Relative Abundance";
			chartArea12->AxisY->TitleAlignment = System::Drawing::StringAlignment::Near;
			chartArea12->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			chartArea12->Name = L"ChartArea1";
			this->rankChart->ChartAreas->Add(chartArea12);
			legend3->Enabled = false;
			legend3->Name = L"Legend1";
			this->rankChart->Legends->Add(legend3);
			this->rankChart->Location = System::Drawing::Point(422, 484);
			this->rankChart->Name = L"rankChart";
			series12->ChartArea = L"ChartArea1";
			series12->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastLine;
			series12->Color = System::Drawing::Color::Black;
			series12->Legend = L"Legend1";
			series12->Name = L"Rank chart";
			this->rankChart->Series->Add(series12);
			this->rankChart->Size = System::Drawing::Size(277, 215);
			this->rankChart->TabIndex = 47;
			title9->Name = L"Title1";
			title9->Text = L"Rank Abundance";
			this->rankChart->Titles->Add(title9);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->checkBox1->Location = System::Drawing::Point(27, 202);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->checkBox1->Size = System::Drawing::Size(246, 29);
			this->checkBox1->TabIndex = 48;
			this->checkBox1->Text = L"Initial Monodominance";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(287, 283);
			this->trackBar1->Maximum = 50;
			this->trackBar1->Minimum = 1;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(123, 42);
			this->trackBar1->TabIndex = 49;
			this->trackBar1->Value = 30;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &Form1::trackBar1_Scroll);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(319, 328);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(61, 20);
			this->label11->TabIndex = 50;
			this->label11->Text = L"Speed";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(710, 710);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->rankChart);
			this->Controls->Add(this->label_species);
			this->Controls->Add(this->label_time);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->localChart);
			this->Controls->Add(this->metaChart);
			this->Controls->Add(this->speciesChart);
			this->Controls->Add(this->systemLog);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->specRate);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->seed);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->M_size);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->theta);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->L);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->m);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"The Neutralizer - Community Ecology Research 2015";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->speciesChart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->metaChart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->localChart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rankChart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

public:
void checkImg(const char* filename, bool& aspects, int& size)
{
	std::vector< std::vector< int> > check;
	toArray(check,P.FileName,size);

	aspects = false;
	if(check.size() == check[0].size()) aspects = true;
}

public:
void set_time(const int& t)
{
	System::String^ str = t.ToString();
	//this->timeBox->Text = str;
	this->label_time->Text = str;
}

public:
void set_species(const int& s)
{
	System::String^ str = s.ToString();
	//this->speciesBox->Text = str;
	this->label_species->Text = str;
}

public:
void add_systemLog(const std::string& text)
{
	System::String^ str = gcnew System::String(text.c_str());
	this->systemLog->AppendText(str);

}

public:
void updateSpeciesChart(const int& tim, const int& val)
{
	this->speciesChart->Series[0]->Points->AddXY(tim,val);


	if(val > this->speciesChart->ChartAreas[0]->AxisY->Maximum) {
		int max = (int)this->speciesChart->ChartAreas[0]->AxisY->Maximum;
		while(val > max) max += 50;
		
		this->speciesChart->ChartAreas[0]->AxisY->Maximum = max;
	}
}

void drawMetaChart(const std::vector<double>& yvals)
{
	int i = 0;
	for(std::vector<double>::const_iterator Y = yvals.begin(); Y != yvals.end(); ++Y)
	{
		this->metaChart->Series[0]->Points->AddXY(i,(*Y));
		i++;
	}
}

void drawLocalChart(const std::vector<double>& yvals)
{
	this->localChart->Series[0]->Points->Clear();
	
	int i = 0;

	for(std::vector<double>::const_iterator Y = yvals.begin(); Y != yvals.end(); ++Y)
	{
		if((*Y) > this->localChart->ChartAreas[0]->AxisY->Maximum) this->localChart->ChartAreas[0]->AxisY->Maximum += 5;
		
		this->localChart->Series[0]->Points->AddXY(i,(*Y));
		i++;
	}
}

void drawRankChart(const std::vector<double>& perc)
{
	this->rankChart->Series[0]->Points->Clear();
	//this->rankChart->chartAreas->Axes[0]->Maximum = 100;
//	this->chartArea4->AxisX->Maximum = 105;
	//this->rankChart->AxisX->Maximum = 100;
	std::size_t max = (int)this->rankChart->ChartAreas[0]->AxisX->Maximum;

	while(perc.size() > max) max += 50;
		
    this->rankChart->ChartAreas[0]->AxisX->Maximum = max;

	//if(perc.size() > this->rankChart->ChartAreas[0]->AxisX->Maximum) this->rankChart->ChartAreas[0]->AxisX->Maximum = "Auto";

	for(std::size_t i = 0; i < perc.size(); ++i)
	{
		double val = perc[i];
		this->rankChart->Series[0]->Points->AddY(val);
	}
}

public:
void resetCharts()
{
	this->localChart->Series[0]->Points->Clear();
	this->metaChart->Series[0]->Points->Clear();
	P.graphedMeta = false;
	this->speciesChart->Series[0]->Points->Clear();
	
}



void updateParams()
{
			P.Seed = int::Parse(seed->Text);
//			P.update = int::Parse(updateInterval->Text);
			P.m = double::Parse(m->Text);
			P.theta = double::Parse(theta->Text);
			P.L = int::Parse(textBox1->Text);
			P.Jm = (int)double::Parse(M_size->Text);
		//	P.N = int::Parse(textBox2->Text);
			P.speciationRate = double::Parse(specRate->Text);
			P.size = int::Parse(textBox3->Text);
			P.monoDominance = checkBox1->Checked;
			

//			System::String ^ dispType = comboBox->Text;
//			std::string result;
//			To_string(dispType,result);
//			P.dispersalType = result;		
}
public:
void resetText()
{
	this->button1->Text = "Run";
}


void displayParams()
{
	System::String^ dispType = gcnew System::String(P.dispersalType.c_str());



	MessageBox::Show(        "Size             \t=\t" + P.size         + "\n" + 
							 "Migration rate   \t=\t" + P.m			   + "\n" +
							 "Dispersal radius \t=\t" + P.L			   + "\n" +
							 "Speciation rate  \t=\t" + P.speciationRate + "\n\n" +
							 "Theta            \t=\t" + P.theta		   + "\n" +
							 "Meta_pop size    \t=\t" + P.Jm           + "\n" +
						//	 "Turnover         \t=\t" + P.N			  +  "\n"   +
							 "Seed             \t=\t" + P.Seed		   + "\n" +
							 "Update Interval  \t=\t" + P.update	   + "\n"
						//	 "Dispersal Type   \t=\t" + dispType + "\n"
								, "Message");


}

void checkParams()
{
	if(P.speciationRate >= 1e-2) {
	/*	MessageBox::Show( "You have selected a very high speciation rate \n" + 
						  "which might cause the progam to slow down or crash\n" + 
						  "do you want to proceed?")*/
	  if( MessageBox::Show("You have selected a very high speciation rate \n" + 
						   "which might cause the progam to slow down or crash\n" + 
						   "do you want to continue?",
						   "Speciation Rate Error Check",MessageBoxButtons::YesNo,
						   MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::No)
      {
         P.speciationRate = 1e-6;
		 MessageBox::Show("Speciation rate was reset to\t" + "1e-6" + "\n","Message");
		 System::String^ str = "1e-6";
		 this->specRate->Text = str;
      }
	}

	if(P.L == 0) {
		MessageBox::Show("Dispersal radius is too small\n\n" + 
						 "The Dispersal radius is reset to 1",
						 "Dispersal radius check");
		P.L = 1;
		System::String^ str = "1";
		this->textBox1->Text = str;
	}

	if(P.size > 500) {
		if( MessageBox::Show("You have selected a very large size \n" + 
						   "which might cause the progam to slow down or crash\n" + 
						   "do you want to continue?",
						   "World size check",MessageBoxButtons::YesNo,
						   MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::No)
		  {
			 P.size = 100;
			 MessageBox::Show("World size was reset to\t" + "100" + "\n","Message");
			 System::String^ str = "100";
			 this->textBox3->Text = str;
		  }
	}

	if(P.size != P.previousSize && P.isPaused == true) {
		MessageBox::Show("I'm sorry, but you can't change the size when pauzed\n" +
					     "you will have to press 'stop/reset' first!\n"
						 );
		P.size = P.previousSize;
		System::String^ str = P.size.ToString();
	    this->textBox3->Text = str;
	}
	P.previousSize = P.size;

}



private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) { //go
			 
			 if(this->button1->Text == "Pause")
			 {
				  P.isPaused = true;
				  this->button1->Text = "Continue";
			 }
			 else
			 {
				 P.isPaused = false;
				 this->button1->Text = "Pause";
			 }
			 
			 updateParams();
			 if(P.isRunning == false) {
				reset_simulation(this);
				go(this);
			 }
	}

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {  //read parameters
			 updateParams();
			 checkParams();
			// if(P.isRunning == false) displayParams();
			// else {
			//	 MessageBox::Show("Parameters updated","Message");
			 //}
			 displayParams();
		 }

private: System::Void file_Click(System::Object^  sender, System::EventArgs^  e) {
			
			 if(openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			  {		
				  System::String ^ f = openFileDialog1->FileName;
				  char * str;
				  To_CharStar(f,str);
				  P.FileName = str;
				  bool aspects;
				  int fieldArea;
				  checkImg(P.FileName,aspects,fieldArea);

				  if(aspects == true) 
				  {
					  MessageBox::Show("Environment File Stored\nAspect ratio is correct\nYou are good to go!","Message");
					  P.imageChosen = true;
					  P.imageRight = true;

					  P.N = (int)(0.25 * fieldArea);
					  System::String^ str = P.N.ToString(); 
//					  this->textBox2->Text = str;
				  }
				  if(aspects == false) 
				  {
						  MessageBox::Show("Source File has wrong aspects\n please pick another file","Message");
						  P.imageChosen = false;
						  P.imageRight = false;
				  }
			  }
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

			 exit(0);
		 }

private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(P.isRunning == true) {			 
				stop_simul();
				P.isRunning = false;

				this->speciesChart->ChartAreas[0]->AxisY->Maximum = 50;
				this->localChart->ChartAreas[0]->AxisY->Maximum = 10;

				this->button1->Text = "Run";
			 }
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(P.isRunning == true) {			 
				stop_simul();
				P.isRunning = false;

				this->speciesChart->ChartAreas[0]->AxisY->Maximum = 50;
				this->localChart->ChartAreas[0]->AxisY->Maximum = 10;

				this->button1->Text = "Run";

				updateParams();
			 
				reset_simulation(this);
				go(this);
			 }
		}

private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
			//P.update = this->trackBar1->Value;
			 int speed = this->trackBar1->Value;
			  if(speed > 20) {
				 P.turnover = P.N;
				 P.update = speed - 20 + 1;
			 }
			 else {
				 P.update = 1;
				 P.turnover = 1+(int)(P.N * (1 - exp(-0.5 * speed)));
			 }


		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

