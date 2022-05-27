#pragma once
#include "ConexionDB2.h"
#include "string"
#include<mysql.h>
#include<stdlib.h>



class Venta {
private:
	int no_factura=0;
	string serie, fechafactura, idempleado, nit, idcliente, fechaingreso;
	

public:
	Venta() {

	}
	Venta(string serie_v, string fecha_factura, string id_empleado, string NIT) {
		serie = serie_v;
		fechafactura = fecha_factura;
		idempleado = id_empleado; 
		nit = NIT;
	}

	//metodos set y get
	void setNoFactura(int nfactura) { no_factura = nfactura; }
	void setSerie(string serie_v) { serie = serie_v; }
	void setFechaFactura(string fecha_factura) { fechafactura = fecha_factura; }	
	void setIdEmpleado(string id_empleado) { idempleado = id_empleado; }


	int getNoFactura() { return no_factura; }
	string getSerie() { return serie; }
	string getFechaFactura() { return fechafactura; }
	string getIdEmpleado() { return idempleado; }
	
	void ingresar() {
		int q_estado;
		string no_factura_aux;
		ConexionBD2 cn = ConexionBD2();

		cn.abrir_conexion();
		if (cn.getConectar()) {
			no_factura_aux = to_string(no_factura);
			string insertar = "INSERT INTO `proyecto_final_programacion`.`ventas` (`nofactura`,`serie`,`fechafactura`,`idcliente`,`idempleado`,`fechaingreso`) VALUES('" + no_factura_aux + "','" + serie + "','" + fechafactura + "','" + idcliente + "','" + idempleado + "','" + fechaingreso + "')";
			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (q_estado) {
				cout << "Hubo un error al ingresar los datos" << endl;
			}
		}
		cn.cerrar_conexion();
	}
	
	
	void no_facturas() {
		no_factura = 0;
		int q_estado;
		ConexionBD2 cn = ConexionBD2();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select max(idventa) from ventas";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					no_factura = stoi(fila[0]) + 1;
					
				}
			}
		}
		cn.cerrar_conexion();
	}
	
	void datos_restantes() {
		system("cls");
		int q_estado;
		ConexionBD2 cn = ConexionBD2();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select fechaingreso, idcliente from clientes where NIT = '" + nit + "';";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					fechaingreso = fila[0];
					idcliente = fila[1];
				}
			}
		}
		cn.cerrar_conexion();
	}
	
	void crear_factura() {
		system("cls");

		cout << "No.Factura: "<<no_factura;
	
		cout << "\t\t\t\tSerie: " << serie << endl;
		
		cout << "ID de empleado: "<<idempleado;
	
		cout << "\t\t\tFecha de la factura: " << fechafactura << endl;

		cout << "NIT del cliente: "<<nit<<endl;

		cout << "Fecha de ingreso: " << fechaingreso << endl;

		cout << "ID del cliente: " << idcliente << endl;

		cout <<"_________________________________________________________________________________________________________"<< endl;
		
	}
};