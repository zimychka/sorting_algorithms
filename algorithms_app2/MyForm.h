#pragma once

#include <chrono>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <random>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <format>
#include "TableForm.h"


int* dataGeneration(int n);
int* selectionSort(int n, int* data_gen);
void heapSort(int data[], int n, int i);
int* completeHeapSort(int n, int* data_gen);
bool moveToFile(int** results, int points, int algs_num, int* checks);
int* bubbleSort(int n, int* data);
int* insertionSort(int n, int* data);
void printArray(int size, int* data);
void quickSort(int left, int right, int* data);
int* completeQuickSort(int n, int* data);


namespace algorithmsapp2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	public ref class MyForm : public System::Windows::Forms::Form
	{

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
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
		}

	private:

		// размер вектора
		const int n = 1000;

		int pace = 100;
		int points = n / pace + 1;	 

		int* data_gen = new int[n];
		int user_size = 0;
		int* data = new int[user_size];
		int algs_num = 1;
		const int check_size = 6;
		int* checks = new int[check_size];
		int position = 1;
		int** results = new int* [points];
		bool isRead = false;
		int test_size = 20;
		int* empty;

		int** new_results;
		int* new_checks;
		int new_points;
		int new_algs_num;
		int** end_res;
		int* end_checks;
		int end_points;
		int end_algs_num;
		cli::array<String^>^ stringArray;
		cli::array<Color>^ colorArray = gcnew cli::array<Color>(5);
		

	private: System::Windows::Forms::CheckBox^ checkBox_selection;
	private: System::Windows::Forms::CheckBox^ checkBox_heap;
	private: System::Windows::Forms::Button^ btn_algs;
	private: System::Windows::Forms::Button^ btn_gen;
	private: System::Windows::Forms::Button^ btn_res;
	private: System::Windows::Forms::Button^ btn_export;
	private: System::Windows::Forms::Button^ btn_import;
	private: System::Windows::Forms::Button^ btn_table;
	private: System::Windows::Forms::Button^ btn_graph;
	private: System::Windows::Forms::Label^ label_algs;
	private: System::Windows::Forms::Label^ label_algs_info;
	private: System::Windows::Forms::Label^ label_gen;
	private: System::Windows::Forms::Label^ label_gen_info;
	private: System::Windows::Forms::Label^ label_res;
	private: System::Windows::Forms::Label^ label_res_info;
	private: System::Windows::Forms::Label^ label_export;
	private: System::Windows::Forms::Label^ label_import;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart;
	private: System::Windows::Forms::CheckBox^ checkBox_quick;
	private: System::Windows::Forms::CheckBox^ checkBox_bubble;
	private: System::Windows::Forms::CheckBox^ checkBox_insertion;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->checkBox_selection = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_heap = (gcnew System::Windows::Forms::CheckBox());
			this->btn_algs = (gcnew System::Windows::Forms::Button());
			this->btn_gen = (gcnew System::Windows::Forms::Button());
			this->btn_res = (gcnew System::Windows::Forms::Button());
			this->btn_export = (gcnew System::Windows::Forms::Button());
			this->btn_import = (gcnew System::Windows::Forms::Button());
			this->btn_table = (gcnew System::Windows::Forms::Button());
			this->btn_graph = (gcnew System::Windows::Forms::Button());
			this->label_algs = (gcnew System::Windows::Forms::Label());
			this->label_algs_info = (gcnew System::Windows::Forms::Label());
			this->label_gen = (gcnew System::Windows::Forms::Label());
			this->label_gen_info = (gcnew System::Windows::Forms::Label());
			this->label_res = (gcnew System::Windows::Forms::Label());
			this->label_res_info = (gcnew System::Windows::Forms::Label());
			this->label_export = (gcnew System::Windows::Forms::Label());
			this->label_import = (gcnew System::Windows::Forms::Label());
			this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->checkBox_quick = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_bubble = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_insertion = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->BeginInit();
			this->SuspendLayout();
			// 
			// checkBox_selection
			// 
			this->checkBox_selection->AutoSize = true;
			this->checkBox_selection->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox_selection->Location = System::Drawing::Point(27, 188);
			this->checkBox_selection->Name = L"checkBox_selection";
			this->checkBox_selection->Size = System::Drawing::Size(236, 29);
			this->checkBox_selection->TabIndex = 0;
			this->checkBox_selection->Text = L"Сортировка Выбором";
			this->checkBox_selection->UseVisualStyleBackColor = true;
			// 
			// checkBox_heap
			// 
			this->checkBox_heap->AutoSize = true;
			this->checkBox_heap->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox_heap->Location = System::Drawing::Point(27, 223);
			this->checkBox_heap->Name = L"checkBox_heap";
			this->checkBox_heap->Size = System::Drawing::Size(203, 29);
			this->checkBox_heap->TabIndex = 1;
			this->checkBox_heap->Text = L"Сортировка Кучей";
			this->checkBox_heap->UseVisualStyleBackColor = true;
			// 
			// btn_algs
			// 
			this->btn_algs->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_algs->Location = System::Drawing::Point(27, 294);
			this->btn_algs->Name = L"btn_algs";
			this->btn_algs->Size = System::Drawing::Size(236, 48);
			this->btn_algs->TabIndex = 2;
			this->btn_algs->Text = L"Принять";
			this->btn_algs->UseVisualStyleBackColor = true;
			this->btn_algs->Click += gcnew System::EventHandler(this, &MyForm::btn_algs_Click);
			// 
			// btn_gen
			// 
			this->btn_gen->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_gen->Location = System::Drawing::Point(335, 132);
			this->btn_gen->Name = L"btn_gen";
			this->btn_gen->Size = System::Drawing::Size(234, 48);
			this->btn_gen->TabIndex = 3;
			this->btn_gen->Text = L"Сгенерировать";
			this->btn_gen->UseVisualStyleBackColor = true;
			this->btn_gen->Click += gcnew System::EventHandler(this, &MyForm::btn_gen_Click);
			// 
			// btn_res
			// 
			this->btn_res->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_res->Location = System::Drawing::Point(335, 294);
			this->btn_res->Name = L"btn_res";
			this->btn_res->Size = System::Drawing::Size(236, 48);
			this->btn_res->TabIndex = 6;
			this->btn_res->Text = L"Рассчитать";
			this->btn_res->UseVisualStyleBackColor = true;
			this->btn_res->Click += gcnew System::EventHandler(this, &MyForm::btn_res_Click);
			// 
			// btn_export
			// 
			this->btn_export->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_export->Location = System::Drawing::Point(637, 35);
			this->btn_export->Name = L"btn_export";
			this->btn_export->Size = System::Drawing::Size(215, 49);
			this->btn_export->TabIndex = 7;
			this->btn_export->Text = L"Запись в файл";
			this->btn_export->UseVisualStyleBackColor = true;
			this->btn_export->Click += gcnew System::EventHandler(this, &MyForm::btn_export_Click);
			// 
			// btn_import
			// 
			this->btn_import->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_import->Location = System::Drawing::Point(637, 132);
			this->btn_import->Name = L"btn_import";
			this->btn_import->Size = System::Drawing::Size(215, 48);
			this->btn_import->TabIndex = 8;
			this->btn_import->Text = L"Чтение из файла";
			this->btn_import->UseVisualStyleBackColor = true;
			this->btn_import->Click += gcnew System::EventHandler(this, &MyForm::btn_import_Click);
			// 
			// btn_table
			// 
			this->btn_table->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_table->Location = System::Drawing::Point(637, 238);
			this->btn_table->Name = L"btn_table";
			this->btn_table->Size = System::Drawing::Size(212, 46);
			this->btn_table->TabIndex = 9;
			this->btn_table->Text = L"Вывод таблицы";
			this->btn_table->UseVisualStyleBackColor = true;
			this->btn_table->Click += gcnew System::EventHandler(this, &MyForm::btn_table_Click);
			// 
			// btn_graph
			// 
			this->btn_graph->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_graph->Location = System::Drawing::Point(637, 294);
			this->btn_graph->Name = L"btn_graph";
			this->btn_graph->Size = System::Drawing::Size(212, 48);
			this->btn_graph->TabIndex = 10;
			this->btn_graph->Text = L"Вывод графика";
			this->btn_graph->UseVisualStyleBackColor = true;
			this->btn_graph->Click += gcnew System::EventHandler(this, &MyForm::btn_graph_Click);
			// 
			// label_algs
			// 
			this->label_algs->AutoSize = true;
			this->label_algs->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_algs->Location = System::Drawing::Point(22, 28);
			this->label_algs->Name = L"label_algs";
			this->label_algs->Size = System::Drawing::Size(254, 25);
			this->label_algs->TabIndex = 11;
			this->label_algs->Text = L"Алгоритмы сортировки";
			// 
			// label_algs_info
			// 
			this->label_algs_info->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_algs_info->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label_algs_info->Location = System::Drawing::Point(31, 345);
			this->label_algs_info->Name = L"label_algs_info";
			this->label_algs_info->Size = System::Drawing::Size(236, 31);
			this->label_algs_info->TabIndex = 14;
			this->label_algs_info->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label_gen
			// 
			this->label_gen->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_gen->Location = System::Drawing::Point(330, 28);
			this->label_gen->Name = L"label_gen";
			this->label_gen->Size = System::Drawing::Size(237, 58);
			this->label_gen->TabIndex = 15;
			this->label_gen->Text = L"Генерация вектора случайных чисел";
			// 
			// label_gen_info
			// 
			this->label_gen_info->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_gen_info->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label_gen_info->Location = System::Drawing::Point(337, 183);
			this->label_gen_info->Name = L"label_gen_info";
			this->label_gen_info->Size = System::Drawing::Size(232, 34);
			this->label_gen_info->TabIndex = 16;
			this->label_gen_info->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label_res
			// 
			this->label_res->AutoSize = true;
			this->label_res->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_res->Location = System::Drawing::Point(330, 226);
			this->label_res->Name = L"label_res";
			this->label_res->Size = System::Drawing::Size(220, 25);
			this->label_res->TabIndex = 17;
			this->label_res->Text = L"Расчёт результатов";
			// 
			// label_res_info
			// 
			this->label_res_info->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_res_info->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label_res_info->Location = System::Drawing::Point(338, 345);
			this->label_res_info->Name = L"label_res_info";
			this->label_res_info->Size = System::Drawing::Size(236, 34);
			this->label_res_info->TabIndex = 18;
			this->label_res_info->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label_export
			// 
			this->label_export->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_export->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label_export->Location = System::Drawing::Point(637, 82);
			this->label_export->Name = L"label_export";
			this->label_export->Size = System::Drawing::Size(215, 39);
			this->label_export->TabIndex = 19;
			this->label_export->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label_import
			// 
			this->label_import->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_import->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label_import->Location = System::Drawing::Point(637, 183);
			this->label_import->Name = L"label_import";
			this->label_import->Size = System::Drawing::Size(215, 31);
			this->label_import->TabIndex = 21;
			this->label_import->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// chart
			// 
			chartArea1->AxisX->IntervalAutoMode = System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;
			chartArea1->AxisX->Title = L"Size of vector, N";
			chartArea1->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			chartArea1->AxisY->IntervalAutoMode = System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;
			chartArea1->AxisY->Title = L"Sorting time, microseconds";
			chartArea1->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			chartArea1->Name = L"ChartArea1";
			this->chart->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart->Legends->Add(legend1);
			this->chart->Location = System::Drawing::Point(27, 396);
			this->chart->Name = L"chart";
			this->chart->Size = System::Drawing::Size(1448, 562);
			this->chart->TabIndex = 22;
			this->chart->Text = L"chart1";
			this->chart->Visible = false;
			// 
			// checkBox_quick
			// 
			this->checkBox_quick->AutoSize = true;
			this->checkBox_quick->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox_quick->Location = System::Drawing::Point(27, 153);
			this->checkBox_quick->Name = L"checkBox_quick";
			this->checkBox_quick->Size = System::Drawing::Size(229, 29);
			this->checkBox_quick->TabIndex = 23;
			this->checkBox_quick->Text = L"Сортировка Быстрая";
			this->checkBox_quick->UseVisualStyleBackColor = true;
			// 
			// checkBox_bubble
			// 
			this->checkBox_bubble->AutoSize = true;
			this->checkBox_bubble->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox_bubble->Location = System::Drawing::Point(27, 117);
			this->checkBox_bubble->Name = L"checkBox_bubble";
			this->checkBox_bubble->Size = System::Drawing::Size(270, 29);
			this->checkBox_bubble->TabIndex = 24;
			this->checkBox_bubble->Text = L"Сортировка Пузырьковая";
			this->checkBox_bubble->UseVisualStyleBackColor = true;
			// 
			// checkBox_insertion
			// 
			this->checkBox_insertion->AutoSize = true;
			this->checkBox_insertion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox_insertion->Location = System::Drawing::Point(27, 82);
			this->checkBox_insertion->Name = L"checkBox_insertion";
			this->checkBox_insertion->Size = System::Drawing::Size(251, 29);
			this->checkBox_insertion->TabIndex = 25;
			this->checkBox_insertion->Text = L"Сортировка Вставками";
			this->checkBox_insertion->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(881, 378);
			this->Controls->Add(this->checkBox_insertion);
			this->Controls->Add(this->checkBox_bubble);
			this->Controls->Add(this->checkBox_quick);
			this->Controls->Add(this->chart);
			this->Controls->Add(this->label_import);
			this->Controls->Add(this->label_export);
			this->Controls->Add(this->label_res_info);
			this->Controls->Add(this->label_res);
			this->Controls->Add(this->label_gen_info);
			this->Controls->Add(this->label_gen);
			this->Controls->Add(this->label_algs_info);
			this->Controls->Add(this->label_algs);
			this->Controls->Add(this->btn_graph);
			this->Controls->Add(this->btn_table);
			this->Controls->Add(this->btn_import);
			this->Controls->Add(this->btn_export);
			this->Controls->Add(this->btn_res);
			this->Controls->Add(this->btn_gen);
			this->Controls->Add(this->btn_algs);
			this->Controls->Add(this->checkBox_heap);
			this->Controls->Add(this->checkBox_selection);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Sorting Algorithms Time";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// Выбор алгоритмов сортировки
	private: System::Void btn_algs_Click(System::Object^ sender, System::EventArgs^ e) {

		if (checkBox_insertion->Checked) {
			algs_num += 1; checks[1] = true;
		}
		if (checkBox_bubble->Checked) {
			algs_num += 1; checks[2] = true;
		}
		if (checkBox_quick->Checked) {
			algs_num += 1; checks[3] = true;
		}
		if (checkBox_selection->Checked) {
			algs_num += 1; checks[4] = true;
		}
		if (checkBox_heap->Checked) {
			algs_num += 1; checks[5] = true;
		}
		for (int i = 1; i < check_size; i++) {
			if (checks[i] > 0) { checks[i] = position; position++; }
		}
		this->label_algs_info->Text = "Готово!";

		stringArray = gcnew cli::array<String^>(check_size);
		for (int i = 1; i < check_size; i++) {
			if (checks[i] > 0) {
				switch (i) {
				case 1:
					stringArray[checks[i]] = "Insertion Sort"; break;
				case 2:
					stringArray[checks[i]] = "Bubble Sort"; break;
				case 3:
					stringArray[checks[i]] = "Quick Sort"; break;
				case 4:
					stringArray[checks[i]] = "Selection Sort"; break;
				case 5:
					stringArray[checks[i]] = "Heap Sort"; break;
				}
			}
		}
	}

		   // Генерация вектора случайных чисел
	private: System::Void btn_gen_Click(System::Object^ sender, System::EventArgs^ e) {
		srand(time(0));
		this->data_gen = dataGeneration(n);
		this->label_gen_info->Text = "Готово!";
	}

		   // Расчет результатов
	private: System::Void btn_res_Click(System::Object^ sender, System::EventArgs^ e) {

		for (int i = 0; i < points; i++) {
			results[i] = new int[algs_num];
		}

		for (int i = 0; i < points; i++) {
			results[i][0] = i * pace;

			for (int j = 1; j < algs_num; j++) {
				if ((checks[1] > 0) && (j == checks[1])) {
					results[i][j] = *insertionSort(i * pace, data_gen);
				}
				else if ((checks[2] > 0) && (j == checks[2])) {
					results[i][j] = *bubbleSort(i * pace, data_gen);
				}
				else if ((checks[3] > 0) && (j == checks[3])) {
					results[i][j] = *completeQuickSort(i * pace, data_gen);
				}
				else if ((checks[4] > 0) && (j == checks[4])) {
					results[i][j] = *selectionSort(i * pace, data_gen);
				}
				else if ((checks[5] > 0) && (checks[5] == j)) {
					results[i][j] = *completeHeapSort(i * pace, data_gen);
				}
				//if (results[1][j] >= 100) results[1][j] /= 10;
			}
		}
		this->label_res_info->Text = "Готово!";
	}

		   // Вывод таблицы
	private: System::Void btn_table_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!isRead) {
			end_res = results;
			end_checks = checks;
			end_points = points;
			end_algs_num = algs_num;
		}

		TableForm1^ tableForm = gcnew TableForm1();
		tableForm->FillTableData(end_res, end_algs_num, end_points, stringArray);
		tableForm->Show();
	}

		   // Запись в файл
	private: System::Void btn_export_Click(System::Object^ sender, System::EventArgs^ e) {
		int res = remove("table.csv");
		bool isExport = moveToFile(results, points, algs_num, checks);
		this->label_export->Text = "Готово!";
	}

		   // Чтение из файла
	private: System::Void btn_import_Click(System::Object^ sender, System::EventArgs^ e) {
		vector<int> v_results;
		vector<string> v_names;

		ifstream inData;
		inData.open("table.csv");
		if (inData.is_open()) {
			string line, col;

			getline(inData, line);
			stringstream ss(line);
			while (getline(ss, col, ',')) {
				v_names.push_back(col);
			}

			while (getline(inData, line)) {
				stringstream ss(line);
				while (getline(ss, col, ',')) {
					stringstream s;
					s << col;
					int num;
					s >> num;
					v_results.push_back(num);
				}
			}
			inData.close();
		}

		new_algs_num = v_names.size();
		new_points = v_results.size() / new_algs_num;

		new_results = new int* [new_points];
		for (int i = 0; i < new_points; i++) {
			new_results[i] = new int[new_algs_num];
		}

		for (int i = 0; i < new_points; i++) {
			for (int j = 0; j < new_algs_num; j++) {
				new_results[i][j] = v_results[i * new_algs_num + j];
			}
		}

		new_checks = new int[check_size];
		for (int i = 0; i < check_size; i++) {
			new_checks[i] = 0;

		}
		int pos = 1;
		for (int i = 0; i < new_algs_num; i++) {
			if (v_names[i] == "Insertion Sort") { new_checks[1] = pos; pos++; }
			else if (v_names[i] == "Bubble Sort") { new_checks[2] = pos; pos++; }
			else if (v_names[i] == "Quick Sort") { new_checks[3] = pos; pos++; }
			else if (v_names[i] == "Selection Sort") { new_checks[4] = pos; pos++; }
			else if (v_names[i] == "Heap Sort") {new_checks[5] = pos;}
		}

		isRead = true;
		this->label_import->Text = "Готово!";

		end_res = new_results;
		end_checks = new_checks;
		end_points = new_points;
		end_algs_num = new_algs_num;

		stringArray = gcnew cli::array<String^>(check_size);
		for (int i = 1; i < check_size; i++) {
			if (new_checks[i] > 0) {
				switch (i) {
				case 1:
					stringArray[new_checks[i]] = "Insertion Sort"; break;
				case 2:
					stringArray[new_checks[i]] = "Bubble Sort"; break;
				case 3:
					stringArray[new_checks[i]] = "Quick Sort"; break;
				case 4:
					stringArray[new_checks[i]] = "Selection Sort"; break;
				case 5:
					stringArray[new_checks[i]] = "Heap Sort"; break;
				}
			}
		}
	}

		   // Вывод графика
	private: System::Void btn_graph_Click(System::Object^ sender, System::EventArgs^ e) {

		if (!isRead) {
			end_res = results;
			end_checks = checks;
			end_points = points;
			end_algs_num = algs_num;
		}
		colorArray[0] = Color::Red;
		colorArray[1] = Color::Green;
		colorArray[2] = Color::Blue;
		colorArray[3] = Color::Purple;
		colorArray[4] = Color::DarkOrange;

		for (int i = 1; i < check_size; i++) {
			if (end_checks[i] > 0) {
				String^ name = stringArray[end_checks[i]];
				this->chart->Series->Add(name);
				this->chart->Series[name]->ChartType =
					System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
				this->chart->Series[name]->Points->Clear();
				this->chart->Series[name]->BorderWidth = 2;
				this->chart->Series[name]->Color = colorArray[end_checks[i] - 1];
				

				for (int j = 1; j < end_points; j++) {
					this->chart->Series[name]->Points->AddXY(end_res[j][0], end_res[j][end_checks[i]]);
					this->chart->Series[name]->Name = name;
				}
			}
		}
		this->chart->SaveImage("chart.png", 
			System::Windows::Forms::DataVisualization::Charting::ChartImageFormat::Png);
		system("chart.png");
	
	}
	};
}


int* dataGeneration(int n) {
	int* data = new int[n];
	for (int i = 0; i < n; i++) {
		data[i] = rand() % n;
	}
	return data;
}


int* selectionSort(int n, int* data_gen) {
	int* data_sort = new int[n];
	std::copy(data_gen, data_gen + n, data_sort);

	int min_index = 0;

	const auto start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < n - 1; i++) {
		min_index = i;
		for (int k = i + 1; k < n; k++) {
			if (data_sort[min_index] > data_sort[k]) {
				min_index = k;
			}
		}
		std::swap(data_sort[i], data_sort[min_index]);
	}

	int time = std::chrono::duration_cast<std::chrono::microseconds>
		(std::chrono::high_resolution_clock::now() - start).count();

	int* result = &time;

	return result;
}


int* completeHeapSort(int n, int* data_gen) {

	int* data_sort = new int[n];
	std::copy(data_gen, data_gen + n, data_sort);
	
	const auto start = std::chrono::high_resolution_clock::now();

	//rearrange heap
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapSort(data_sort, n, i);
	}

	//complete sorting
	for (int i = n - 1; i >= 0; i--) {
		std::swap(data_sort[i], data_sort[0]);

		heapSort(data_sort, i, 0);
	}

	int time = std::chrono::duration_cast<std::chrono::microseconds>
		(std::chrono::high_resolution_clock::now() - start).count();
	
	int* result = &time;
	return result;
}


void heapSort(int data[], int n, int i) {
	//Recursive function of sorting between root and 2 children

	int biggest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	// if right child more than root
	if (right < n && data[right] > data[biggest]) {
		biggest = right;
	}

	// if left child more than root
	if (left < n && data[left] > data[biggest]) {
		biggest = left;
	}

	// if biggest value isnt root
	if (biggest != i) {
		std::swap(data[biggest], data[i]);

		heapSort(data, n, biggest);
	}
}

int* insertionSort(int n, int* data) {

	int* data_sort = new int[n];
	std::copy(data, data + n, data_sort);

	const auto start = std::chrono::high_resolution_clock::now();

	for (int i = 1; i < n; i++) {

		int cell = data_sort[i];
		int j = i - 1;

		while (j >= 0 && data_sort[j] > cell) {
			data_sort[j + 1] = data_sort[j];
			j--;
		}
		data_sort[j + 1] = cell;
	}

	int time = std::chrono::duration_cast<std::chrono::microseconds>
		(std::chrono::high_resolution_clock::now() - start).count();

	int* result = &time;
	return result;
}

int* bubbleSort(int n, int* data) {

	int* data_sort = new int[n];
	std::copy(data, data + n, data_sort);


	const auto start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (data_sort[j] > data_sort[j + 1]){
				std::swap(data_sort[j], data_sort[j + 1]);
			}
		}
	}

	int time = std::chrono::duration_cast<std::chrono::microseconds>
		(std::chrono::high_resolution_clock::now() - start).count();

	int* result = &time;

	return result;
}

void quickSort(int left, int right, int* data) {
	if (left > right) return;

	int pivot = data[(left + right) / 2];
	int i = left;
	int j = right;
	
	while (i <= j) {
		while (data[i] < pivot) i++;
		while (data[j] > pivot) j--;
		if (i <= j) {
			std::swap(data[i], data[j]);
			i++;
			j--;
		}
	}
	quickSort(left, j, data);
	quickSort(i, right, data);
}

int* completeQuickSort(int n, int* data) {
	int* data_sort = new int[n];
	std::copy(data, data + n, data_sort);

	const auto start = std::chrono::high_resolution_clock::now();

	quickSort(0, n - 1, data_sort);

	int time = std::chrono::duration_cast<std::chrono::microseconds>
		(std::chrono::high_resolution_clock::now() - start).count();

	int* result = &time;
	return result;
}

bool moveToFile(int** results, int points, int algs_num, int* checks) {
	std::ofstream outData;
	outData.open("table.csv", std::ios_base::trunc);
	char* headerNames[6] = { "Vector size", "Insertion Sort", "Bubble Sort", 
		"Quick Sort", "Selection Sort", "Heap Sort" };
	outData << headerNames[0];
	for (int i = 1; i < 6; i++) {
		if (checks[i] > 0) {
			outData << "," << headerNames[i];
		}
	}
	outData << std::endl;

	for (int i = 0; i < points; i++) {
		for (int j = 0; j < algs_num - 1; j++) {
			outData << results[i][j] << ",";
		}
		outData << results[i][algs_num - 1] << std::endl;
	}
	outData.close();

	return true;
}

void printArray(int size, int* data) {
	for (int i = 0; i < size; i++) {
		printf("%d ", data[i]);
	}
	printf("\n\n");
}