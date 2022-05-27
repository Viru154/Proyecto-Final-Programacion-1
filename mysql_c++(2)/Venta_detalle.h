#pragma once
#include "ConexionDB2.h"
#include "string"
#include<mysql.h>
#include<stdlib.h>



class Venta_detalle {
private:
	string idventa, precio_unitario, nombreproducto;
	float precio_total,cantidad;
	int idproducto;

public:
	Venta_detalle() {

	}
	Venta_detalle(string id_venta, int id_producto, float cantidad_vd, string preciounitario) {
		idventa = id_venta;
		idproducto = id_producto;
		cantidad = cantidad_vd;
		precio_unitario = preciounitario;
	}

	//metodos set y get
	void setIdVenta(string id_venta) { idventa = id_venta; }
	void setIdProducto(int id_producto) { idproducto = id_producto; }
	void setCantidad(float cantidad_vd) { cantidad = cantidad_vd; }
	void setPrecioUnitario(string preciounitario) { precio_unitario = preciounitario; }


	string getIdVenta() { return idventa; }
	int getIdProducto() { return idproducto; }
	float getCantidad() { return cantidad; }
	string getPrecioUnitario() { return precio_unitario; }

	void ingresar() {
		int q_estado;
		string id_producto_aux;
		string cantidad_aux;
		ConexionBD2 cn = ConexionBD2();
		
		cn.abrir_conexion();
		if (cn.getConectar()) {
			id_producto_aux = to_string(idproducto);
			cantidad_aux = to_string(cantidad);
			string insertar = "INSERT INTO `proyecto_final_programacion`.`ventas_detalle` (`idventa`,`idproducto`,`cantidad`,`precio_unitario`) VALUES('" + idventa + "','" + id_producto_aux + "','" + cantidad_aux + "','" + precio_unitario + "');";
			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (q_estado) {
				cout << "Hubo un error al ingresar los datos" << endl;
			}
		}
		cn.cerrar_conexion();
	}

	void get_idventa() {
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
					idventa = fila[0];

				}
			}
		}
		cn.cerrar_conexion();
	}

	void datos_restantes_ventas_detalle() {
		int q_estado;
		ConexionBD2 cn = ConexionBD2();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id_producto_aux = to_string(idproducto);
			string consulta = "select precio_venta, producto from productos where idproducto = "+id_producto_aux+";";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					precio_unitario = fila[0];
					nombreproducto = fila[1];
				}
			}
		}
		cn.cerrar_conexion();
	}

	void lectura_productos(int codigo) {
		int q_estado;
		float sub_total = 0;
		ConexionBD2 cn = ConexionBD2();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id_p1 = to_string(codigo);
			string consulta = "select producto, precio_venta, idproducto from productos where idproducto = "+id_p1+";";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << "Nombre del producto: " << fila[0] << " " << "\tPrecio Unitario: " << fila[1] << " " << "\tID del producto: " << fila[2];
					cout <<"\t"<< "Cantidad del producto: ";
					cin >> cantidad;
					sub_total = cantidad * stoi(fila[1]);
					cout << "Subtotal: " << sub_total << endl;
					cout << "\n";
					precio_total += sub_total;
				}
			}
		}
		cn.cerrar_conexion();
	}

	void ingreso_productos() {
		
		cin.ignore();
		while (idproducto != 0) {
			cout << "ID del producto: ";
			cin >> idproducto;
			if (idproducto != 0) {
				lectura_productos(idproducto);
				get_idventa();
				datos_restantes_ventas_detalle();
				ingresar();
			}
		}
		cout << "Total: " << precio_total << endl;
		cout << "_________________________________________________________" << endl;
		system("pause");
	}

};

