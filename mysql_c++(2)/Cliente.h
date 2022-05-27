#pragma once
#include "Persona.h"
#include "ConexionDB2.h"
#include<mysql.h>



class Cliente : Persona {
private:
	string NIT, correo_electronico, fechaingreso;

public:
	Cliente() {

	}
	Cliente(string name, string lastname, string tel, string genre, string nit, string email, string date_ing) : Persona(name, lastname, tel, genre) {
		NIT = nit;
		correo_electronico = email;
		fechaingreso = date_ing;
	}
	//metodos set y get
	void setNit(string n) { NIT = n; }
	void setCorreo(string c_e) { correo_electronico = c_e; }
	void setFechaIng(string date_ing) { fechaingreso = date_ing; }
	void setNombres(string name) { nombres = name; }
	void setApellidos(string lastname) { apellidos = lastname; }
	void setTelefono(string tel) { telefono = tel; }
	void setGenero(string genre) { genero = genre; }

	string getNit() { return NIT; }
	string getCorreo() { return correo_electronico; }
	string getFechaIng() { return fechaingreso; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getTelefono() { return telefono; }
	string getGenero() { return genero; }

	void leer() {
		system("cls");
		int q_estado;
		ConexionBD2 cn = ConexionBD2();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "\t\tClientes" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << "ID de cliente: " << fila[0] << endl;
					cout << "Nombres: " << fila[1] << endl;
					cout << "Apellidos: " << fila[2] << endl;
					cout << "NIT: " << fila[3] << endl;
					cout << "Genero: " << fila[4] << endl;
					cout << "Telefono: " << fila[5] << endl;
					cout << "Correo electronico: " << fila[6] << endl;
					cout << "Fecha de ingreso: " << fila[7] << endl;
					cout << "____________________________________________" << endl;
				}
			}
		}
		cout << "____________________________________________" << endl;
		cn.cerrar_conexion();
		system("pause");
	}


	
	void ingresar() {
		int q_estado;
		ConexionBD2 cn = ConexionBD2();

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string insertar = "INSERT INTO `proyecto_final_programacion`.`clientes`(`nombres`,`apellidos`,`NIT`,`genero`,`telefono`,`correo_electronico`,`fechaingreso`) VALUES('"+nombres+"','"+apellidos+"','"+NIT+"','"+genero+"','"+telefono+"','"+correo_electronico+"','"+fechaingreso+"');";
			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (q_estado) {
				system("cls");
				cout << "Ingreso exitoso" << endl;
			}
		}
		else {
			system("cls");
			cout << "Hubo un error al ingresar los datos" << endl;

		}
		cn.cerrar_conexion();
		system("pause");
	}

	
	void eliminar(int id_p) {

		int q_estado;
		ConexionBD2 cn = ConexionBD2();

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string id_p1 = to_string(id_p);
			string eliminar = "DELETE from clientes where idcliente = " + id_p1 + "";
			const char* i = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				system("cls");
				cout << "Eliminacion exitosa" << endl;

			}
		}
		else {
			system("cls");
			cout << "Hubo un error a la hora de eliminar el registro deseado" << endl;
		}
		cn.cerrar_conexion();
		system("pause");
	}

	void actualizar(int id_p) {

		int q_estado;
		ConexionBD2 cn = ConexionBD2();

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string id_p1 = to_string(id_p);
			string eliminar = "UPDATE `proyecto_final_programacion`.`clientes` SET `nombres` = '"+nombres+"', `apellidos` = '"+apellidos+"', `NIT` = '"+NIT+"', `genero` = '"+genero+"', `telefono` = '"+telefono+"', `correo_electronico` = '"+correo_electronico+"', `fechaingreso` = '"+fechaingreso+"' WHERE `idcliente` = "+id_p1+"";
			const char* i = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (q_estado) {
				system("cls");
				cout << "Actualizacion exitosa" << endl;
			}
		}
		else {
			system("cls");
			cout << "Hubo un error a la hora de eliminar el registro deseado" << endl;
		}
		cn.cerrar_conexion();
		system("pause");
	}
};
