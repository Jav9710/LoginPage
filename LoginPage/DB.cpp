#include "pch.h"
#include "DB.h"

DB::DB() {
	connectionString = "datasource=localhost; username=root; password=root; database=login";
	connection = gcnew MySqlConnection(connectionString);
}

void DB::openConnection() {
	connection->Open();
}

void DB::closeConnection() {
	connection->Close();
}

DataTable^ DB::getDataTable() {
	String^ sql = "select * from users";
	MySqlCommand^ pointer = gcnew MySqlCommand(sql, connection);
	MySqlDataAdapter^ data = gcnew MySqlDataAdapter(pointer);
	DataTable^ table = gcnew DataTable();
	data->Fill(table);
	return table;
}

String^ DB::getData() {
	String^ sql = "SELECT * FROM users WHERE name = 'Luis'";
	MySqlCommand^ pointer = gcnew MySqlCommand(sql, connection);
	MySqlDataReader^ data = pointer->ExecuteReader();
	String^ data1;
	if (data->Read()){
		data1 = data->GetString(1);
	}
	data->Close();
	return data1;
}

