#pragma once
#include <msclr\marshal_cppstd.h>
#include "AgregarStock.h"

namespace SistemaBebidas {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace msclr::interop;

	/// <summary>
	/// Resumen de AgregarStock
	/// </summary>
	public ref class AgregarStock : public System::Windows::Forms::Form
	{
	public:
		AgregarStock(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~AgregarStock()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ inStock;
	private: System::Windows::Forms::TextBox^ inNombre;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Button^ Actualizar;

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->inStock = (gcnew System::Windows::Forms::TextBox());
			this->inNombre = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->Actualizar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Snow;
			this->label1->Location = System::Drawing::Point(147, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(344, 42);
			this->label1->TabIndex = 58;
			this->label1->Text = L"AGREGAR STOCK";
			this->label1->Click += gcnew System::EventHandler(this, &AgregarStock::label1_Click);
			// 
			// inStock
			// 
			this->inStock->Location = System::Drawing::Point(304, 165);
			this->inStock->Name = L"inStock";
			this->inStock->Size = System::Drawing::Size(229, 20);
			this->inStock->TabIndex = 56;
			this->inStock->TextChanged += gcnew System::EventHandler(this, &AgregarStock::inStock_TextChanged);
			// 
			// inNombre
			// 
			this->inNombre->Location = System::Drawing::Point(304, 115);
			this->inNombre->Name = L"inNombre";
			this->inNombre->Size = System::Drawing::Size(229, 20);
			this->inNombre->TabIndex = 57;
			this->inNombre->TextChanged += gcnew System::EventHandler(this, &AgregarStock::inNombre_TextChanged);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::Color::White;
			this->label13->Location = System::Drawing::Point(60, 163);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(197, 20);
			this->label13->TabIndex = 55;
			this->label13->Text = L"Ingrese el stock a agregar:";
			this->label13->Click += gcnew System::EventHandler(this, &AgregarStock::label13_Click);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::White;
			this->label12->Location = System::Drawing::Point(60, 115);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(238, 20);
			this->label12->TabIndex = 54;
			this->label12->Text = L"Ingrese el nombre del Producto: ";
			this->label12->Click += gcnew System::EventHandler(this, &AgregarStock::label12_Click);
			// 
			// Actualizar
			// 
			this->Actualizar->Location = System::Drawing::Point(227, 220);
			this->Actualizar->Name = L"Actualizar";
			this->Actualizar->Size = System::Drawing::Size(131, 30);
			this->Actualizar->TabIndex = 53;
			this->Actualizar->Text = L"Modificar Stock";
			this->Actualizar->UseVisualStyleBackColor = true;
			this->Actualizar->Click += gcnew System::EventHandler(this, &AgregarStock::Actualizar_Click);
			// 
			// AgregarStock
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::HotTrack;
			this->ClientSize = System::Drawing::Size(604, 280);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->inStock);
			this->Controls->Add(this->inNombre);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->Actualizar);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Name = L"AgregarStock";
			this->Text = L"AgregarStock";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Actualizar_Click(System::Object^ sender, System::EventArgs^ e) {
		//Obtenerlo de form
		String^ nombre = this->inNombre->Text;
		String^ stockResto = this->inStock->Text;
		std::string param1 = marshal_as<std::string>(stockResto);
		int restar = std::stoi(param1);

		String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=sistemabebidas;Integrated Security=True";
		SqlConnection sqlConn(connString); //se crea el objeto conexion
		sqlConn.Open();
		String^ sqlQuery = "SELECT stock FROM productos WHERE nombre=@nombre";
		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@nombre", nombre);
		SqlDataReader^ fila = command.ExecuteReader();
		int stockActual = 0;
		if (fila->Read()) {
			stockActual = fila->GetInt32(0);
		}
		stockActual += restar;

		sqlConn.Close();

		sqlQuery = "UPDATE productos SET stock = @nuevoStock WHERE nombre = @nombre";
		SqlConnection sqlConn1(connString);
		sqlConn1.Open();
		SqlCommand command1(sqlQuery, % sqlConn1);

		command1.Parameters->AddWithValue("@nombre", nombre);
		command1.Parameters->AddWithValue("@nuevoStock", stockActual);
		command1.ExecuteNonQuery();
		sqlConn1.Close();

		inNombre->Text = "";
		inStock->Text = "";
	}
	private: System::Void inStock_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void inNombre_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label13_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label12_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
