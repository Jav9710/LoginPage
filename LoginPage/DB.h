#pragma once
#include <string>


using namespace std;
using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

ref class DB
{
	private:
		String^ connectionString;
		MySqlConnection^ connection;

	public:
		DB();
		void openConnection();
		void closeConnection();
		String^ getData();
		DataTable^ getDataTable();
		
};

