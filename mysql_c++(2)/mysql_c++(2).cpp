// mysql_c++(2).cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <string>
#include "Puesto.h"
#include "Empleado.h"
#include "Marca.h"
#include "Producto.h"
#include "Proveedor.h"
#include "Venta.h"
#include "Venta_detalle.h"
#include "Cliente.h"
#include <ctime>

using namespace std;
 
struct Fecha {
	int dia, mes, anio;
};

Fecha hoy() {
	time_t t;
	t = time(NULL);
	struct tm* f;
	f = localtime(&t);
	Fecha aux;
	aux.anio = f->tm_year + 1900;
	aux.mes = f->tm_mon + 1;
	aux.dia = f->tm_mday;
	return aux;
}

string obtener_fecha(Fecha f) {
	string dia, mes, anio, fecha_actual;
	dia = to_string(f.dia);
	mes = to_string(f.mes);
	anio = to_string(f.anio);
	fecha_actual = anio + "-" + mes + "-" + dia;
	return fecha_actual;
}


//-----------------------------CRUD TABLA PUESTOS-----------------------------//
void getData_Puestos();
void deleteData_Puestos();
void updateData_Puestos();
void CRUD_puestos();
 //--------------------------------------------------------------------------//

//-----------------------------CRUD TABLA MARCAS-----------------------------//
void getData_Marcas();
void deleteData_Marcas();
void updateData_Marcas();
void CRUD_marcas();
//--------------------------------------------------------------------------//

//-----------------------------CRUD TABLA CLIENTES-----------------------------//
void getData_Clientes();
void deleteData_Clientes();
void updateData_Clientes();
void CRUD_clientes();
//--------------------------------------------------------------------------//

//-----------------------------CRUD TABLA EMPLEADOS-----------------------------//
void getData_Empleados();
void deleteData_Empleados();
void updateData_Empleados();
void CRUD_empleados();
//--------------------------------------------------------------------------//

//-----------------------------CRUD TABLA PRODUCTOS-----------------------------//
void getData_Productos();
void deleteData_Productos();
void updateData_Productos();
void CRUD_productos();
//--------------------------------------------------------------------------//

//-----------------------------CRUD TABLA PROVEEDORES-----------------------------//
void getData_Proveedores();
void deleteData_Proveedores();
void updateData_Proveedores();
void CRUD_proveedores();

//--------------------------------------------------------------------------//
//-----------------------------FACTURA-----------------------------//
void crear_Factura();
void CRUD_compra_cd();
//--------------------------------------------------------------------------//



//Funcion principal
int main()
{
	
	int op;


	do {
		system("cls");
		cout << "1.CRUD puestos" << endl;
		cout << "2.CRUD marcas" << endl;
		cout << "3.CRUD clientes" << endl;
		cout << "4.CRUD empleados" << endl;
		cout << "5.CRUD productos" << endl;
		cout << "6.CRUD proveedores" << endl;
		cout << "7.CRUD ventas" << endl;
		cout << "0.Salir" << endl;
		cout << "Ingrese la opcion que desea realizar: ";
		cin >> op;

		switch (op) {
		case 1: CRUD_puestos(); break;
		case 2: CRUD_marcas(); break;
		case 3: CRUD_clientes(); break;
		case 4: CRUD_empleados(); break;
		case 5: CRUD_productos(); break;
		case 6: CRUD_proveedores(); break;
		case 7: CRUD_compra_cd(); break;
		case 0: break;
		default: cout << "La opcion que ingreso no existe, intentelo de nuevo" << endl; break;

		}
	} while (op != 0);
	
   system("pause");
  
   return 0;
}


//------------------------------------------------------------------------CRUD TABLA PUESTOS------------------------------------------------------------------------//
void getData_Puestos() {

	system("cls");
	string puesto;

	cout << "Inserte el nombre del puesto: ";
	cin.ignore();
	getline(cin, puesto);

	Puesto p = Puesto(puesto);
	p.ingresar();
}

void deleteData_Puestos() {
	system("cls");
	Puesto p;
	int id;
	cout << "Ingrese el ID del puesto que desea eliminar: ";
	cin >> id;

	p.eliminar(id);
}

void updateData_Puestos() {
	system("cls");

	int id;
	string puesto;

	cout << "Ingrese el ID del puesto que desea eliminar: ";
	cin >> id;
	cout << "Ingrese el nuevo nombre del puesto: ";
	cin.ignore();
	getline(cin, puesto);

	Puesto p = Puesto(puesto);
	p.actualizar(id);
}

void CRUD_puestos() {

	Puesto p;

	int op;

	do {
		system("cls");
		cout << "1.Ingresar Puesto" << endl;
		cout << "2.Leer puestos" << endl;
		cout << "3.Eliminar puesto" << endl;
		cout << "4.Actualizar puesto" << endl;
		cout << "0.Salir" << endl;
		cout << "Ingrese la opcion que desea realizar: ";
		cin >> op;

		switch (op) {
		case 1: getData_Puestos(); break;
		case 2: p.leer(); break;
		case 3: deleteData_Puestos(); break;
		case 4: updateData_Puestos(); break;
		case 0: break;
		default: system("cls"); cout << "La opcion que ingreso no existe, vuelva a intentarlo"; break;
		}
	} while (op != 0);
	
}

//------------------------------------------------------------------------CRUD TABLA MARCAS------------------------------------------------------------------------//

void getData_Marcas() {
	system("cls");
	string marca;

	cout << "Inserte el nombre de la marca: ";
	cin.ignore();
	getline(cin, marca);

	Marca m = Marca(marca);
	m.ingresar();
}

void deleteData_Marcas() {
	system("cls");
	Marca m;
	int id;
	cout << "Ingrese el ID de la marca que desea eliminar: ";
	cin >> id;

	m.eliminar(id);
}

void updateData_Marcas() {
	system("cls");

	int id;
	string marca;

	cout << "Ingrese el ID de la marca que desea eliminar: ";
	cin >> id;
	cout << "Ingrese el nuevo nombre de la marca: ";
	cin.ignore();
	getline(cin, marca);

	Marca m = Marca(marca);
	m.actualizar(id);
}

void CRUD_marcas() {
	Marca m;

	int op;

	do {
		system("cls");
		cout << "1.Ingresar marca" << endl;
		cout << "2.Leer marcas" << endl;
		cout << "3.Eliminar marca" << endl;
		cout << "4.Actualizar marca" << endl;
		cout << "0.Salir" << endl;
		cout << "Ingrese la opcion que desea realizar: ";
		cin >> op;

		switch (op) {
		case 1: getData_Marcas(); break;
		case 2: m.leer(); break;
		case 3: deleteData_Marcas(); break;
		case 4: updateData_Marcas(); break;
		case 0: break;
		default: system("cls"); cout << "La opcion que ingreso no existe, vuelva a intentarlo"; break;
		}
	} while (op != 0);
}


//------------------------------------------------------------------------CRUD TABLA CLIENTES------------------------------------------------------------------------//

void getData_Clientes() {
	system("cls");
	string nombre,apellido,telefono,genero,nit,email,fechaingreso;

	cout << "Ingrese el nombre del cliente: ";
	cin.ignore();
	getline(cin, nombre);
	cout << "Ingrese los apellidos del cliente: ";
	getline(cin, apellido);
	cout << "Ingrese el numero de telefono del cliente: ";
	getline(cin, telefono);
	cout << "Ingrese el genero (1/0) del cliente: ";
	getline(cin, genero);
	cout << "Ingrese el nunero de NIT del cliente: ";
	getline(cin, nit);
	cout << "Ingrese el correo electronico del cliente: ";
	getline(cin, email);
	cout << "Ingrese la fecha de ingreso del cliente: ";
	getline(cin, fechaingreso);


	Cliente c = Cliente(nombre, apellido, telefono, genero, nit, email, fechaingreso);
	c.ingresar();

}

void deleteData_Clientes() {
	system("cls");
	Cliente c;
	int id;
	cout << "Ingrese el ID del cliente que desea eliminar: ";
	cin >> id;

	c.eliminar(id);
}

void updateData_Clientes() {
	system("cls");

	int id;
	string nombre, apellido, telefono, genero, nit, correo, fechaingreso;

	cout << "Ingrese el ID del cliente que desea actualizar: ";
	cin >> id;



	cout << "Ingrese el nombre del cliente: ";
	cin.ignore();
	getline(cin, nombre);
	cout << "Ingrese los apellidos del cliente: ";
	getline(cin, apellido);
	cout << "Ingrese el numero de telefono del cliente: ";
	getline(cin, telefono);
	cout << "Ingrese el numero de NIT del cliente: ";
	getline(cin, nit);
	cout << "Ingrese el correo electronico del cliente: ";
	getline(cin, correo);
	cout << "Ingrese la fecha en la que se ingresa el cliente: ";
	getline(cin, fechaingreso);

	Cliente c = Cliente(nombre, apellido, telefono, genero, nit, correo, fechaingreso);
	c.actualizar(id);
}

void CRUD_clientes() {
	Cliente c;

	int op;

	do {
		system("cls");
		cout << "1.Ingresar cliente" << endl;
		cout << "2.Leer clientes" << endl;
		cout << "3.Eliminar cliente" << endl;
		cout << "4.Actualizar cliente" << endl;
		cout << "0.Salir" << endl;
		cout << "Ingrese la opcion que desea realizar: ";
		cin >> op;

		switch (op) {
		case 1: getData_Clientes(); break;
		case 2: c.leer(); break;
		case 3: deleteData_Clientes(); break;
		case 4: updateData_Clientes(); break;
		case 0: break;
		default: system("cls"); cout << "La opcion que ingreso no existe, vuelva a intentarlo"; break;
		}
	} while (op != 0);
}

//------------------------------------------------------------------------CRUD TABLA EMPLEADOS------------------------------------------------------------------------//

void getData_Empleados() {
	system("cls");
	string nombre, apellido, telefono, genero, direccion, dpi, fecha_nacimiento, idpuesto, fecha_inicio_labores, fechaingreso;

	cout << "Ingrese el nombre del empleado: ";
	cin.ignore();
	getline(cin, nombre);
	cout << "Ingrese los apellidos del empleado: ";
	getline(cin, apellido);
	cout << "Ingrese el numero de telefono del empleado: ";
	getline(cin, telefono);
	cout << "Ingrese el genero (1/0) del empleado: ";
	getline(cin, genero);
	cout << "Ingrese la direccion del empleado: ";
	getline(cin, direccion);
	cout << "Ingrese el DPI del empleado: ";
	getline(cin, dpi);
	cout << "Ingrese la fecha de nacimiento del empleado: ";
	getline(cin, fecha_nacimiento);
	cout << "Ingrese el ID del puesto que ocupa el empleado: ";
	getline(cin, idpuesto);
	cout << "Ingrese la fecha en la que el empleado inicio a laburar: ";
	getline(cin, fecha_inicio_labores);
	cout << "Ingrese la fecha del ingreso del empleado al sistema: ";
	getline(cin, fechaingreso);
	


	Empleado e = Empleado(nombre, apellido, telefono, genero, direccion, dpi, fecha_nacimiento, idpuesto, fecha_inicio_labores, fechaingreso);
	e.ingresar();
}

void deleteData_Empleados() {
	system("cls");
	Empleado e;
	int id;
	cout << "Ingrese el ID del empleado que desea eliminar: ";
	cin >> id;

	e.eliminar(id);
}

void updateData_Empleados() {
	system("cls");

	int id;
	string nombre, apellido, telefono, genero, direccion, dpi, fecha_nacimiento, idpuesto, fecha_inicio_labores, fechaingreso;

	cout << "Ingrese el ID del empleado que desea actualizar: ";
	cin >> id;

	cout << "Ingrese el nombre del empleado: ";
	cin.ignore();
	getline(cin, nombre);
	cout << "Ingrese los apellidos del empleado: ";
	getline(cin, apellido);
	cout << "Ingrese el numero de telefono del empleado: ";
	getline(cin, telefono);
	cout << "Ingrese el genero (1/0) del empleado: ";
	getline(cin, genero);
	cout << "Ingrese la direccion del empleado: ";
	getline(cin, direccion);
	cout << "Ingrese el DPI del empleado: ";
	getline(cin, dpi);
	cout << "Ingrese la fecha de nacimiento del empleado: ";
	getline(cin, fecha_nacimiento);
	cout << "Ingrese el ID del puesto que ocupa el empleado: ";
	getline(cin, idpuesto);
	cout << "Ingrese la fecha en la que el empleado inicio a laburar: ";
	getline(cin, fecha_inicio_labores);
	cout << "Ingrese la fecha del ingreso del empleado al sistema: ";
	getline(cin, fechaingreso);



	Empleado e = Empleado(nombre, apellido, telefono, genero, direccion, dpi, fecha_nacimiento, idpuesto, fecha_inicio_labores, fechaingreso);
	e.actualizar(id);

}

void CRUD_empleados() {
	Empleado e;

	int op;

	do {
		system("cls");
		cout << "1.Ingresar empleado" << endl;
		cout << "2.Leer empleados" << endl;
		cout << "3.Eliminar empleado" << endl;
		cout << "4.Actualizar empleado" << endl;
		cout << "0.Salir" << endl;
		cout << "Ingrese la opcion que desea realizar: ";
		cin >> op;

		switch (op) {
		case 1: getData_Empleados(); break;
	    case 2: e.leer(); break;
		case 3: deleteData_Empleados(); break;
		case 4: updateData_Empleados(); break;
		case 0: break;
		default: system("cls"); cout << "La opcion que ingreso no existe, vuelva a intentarlo"; break;
		}
	} while (op != 0);
}

//------------------------------------------------------------------------CRUD TABLA PRODUCTOS------------------------------------------------------------------------//

void getData_Productos() {

	system("cls");
	string producto, idmarca, descripcion, img, precio_costo, precio_venta, existencia, fechaingreso;

	cout << "Ingrese el nombre del producto: ";
	cin.ignore();
	getline(cin, producto);
	cout << "Ingrese el ID de la marca del producto: ";
	getline(cin, idmarca);
	cout << "Ingrese la descripcion del producto: ";
	getline(cin, descripcion);
	cout << "Ingrese la imagen del producto: ";
	getline(cin, img);
	cout << "Ingrese el precio costo del producto: ";
	getline(cin, precio_costo);
	cout << "Ingrese el precio venta del producto: ";
	getline(cin, precio_venta);
	cout << "Ingrese el total de productos disponibles: ";
	getline(cin, existencia);
	cout << "Ingrese la fecha en la que ingresa el producto: ";
	getline(cin, fechaingreso);

	Producto p = Producto(producto, idmarca, descripcion, img, precio_costo, precio_venta, existencia, fechaingreso);
	p.ingresar();

}

void deleteData_Productos() {
	system("cls");
	Producto p;
	int id;
	cout << "Ingrese el ID del producto que desea eliminar: ";
	cin >> id;

	p.eliminar(id);
}

void updateData_Productos() {
	system("cls");
	string producto, idmarca, descripcion, img, precio_costo, precio_venta, existencia, fechaingreso;
	int id;

	cout << "Ingrese el ID del producto que desea actualizar: ";
	cin >> id;

	cout << "Ingrese el nombre del producto: ";
	cin.ignore();
	getline(cin, producto);
	cout << "Ingrese el ID de la marca del producto: ";
	getline(cin, idmarca);
	cout << "Ingrese la descripcion del producto: ";
	getline(cin, descripcion);
	cout << "Ingrese la imagen del producto: ";
	getline(cin, img);
	cout << "Ingrese el precio costo del producto: ";
	getline(cin, precio_costo);
	cout << "Ingrese el precio venta del producto: ";
	getline(cin, precio_venta);
	cout << "Ingrese el total de productos disponibles: ";
	getline(cin, existencia);
	cout << "Ingrese la fecha en la que ingresa el producto: ";
	getline(cin, fechaingreso);

	Producto p = Producto(producto, idmarca, descripcion, img, precio_costo, precio_venta, existencia, fechaingreso);
	p.actualizar(id);
}

void CRUD_productos() {
	Producto p;

	int op;

	do {
		system("cls");
		cout << "1.Ingresar producto" << endl;
		cout << "2.Leer productos" << endl;
		cout << "3.Eliminar producto" << endl;
		cout << "4.Actualizar producto" << endl;
		cout << "0.Salir" << endl;
		cout << "Ingrese la opcion que desea realizar: ";
		cin >> op;

		switch (op) {
		case 1: getData_Productos(); break;
		case 2: p.leer(); break;
		case 3: deleteData_Productos(); break;
		case 4: updateData_Productos(); break;
	    case 0: break;
		default: system("cls"); cout << "La opcion que ingreso no existe, vuelva a intentarlo"; break;
		}
	} while (op != 0);
}

//------------------------------------------------------------------------CRUD TABLA PROVEEDORES------------------------------------------------------------------------//

void getData_Proveedores() {
	system("cls");
	string proveedor, nit, direccion, telefono;

	cout << "Ingrese el nombre del proveedor: ";
	cin.ignore();
	getline(cin, proveedor);
	cout << "Ingrese el nit del proveedor: ";
	getline(cin, nit);
	cout << "Ingrese la direccion del proveedor: ";
	getline(cin, direccion);
	cout << "Ingresee el numero de telefono del proveedor: ";
	getline(cin, telefono);

	Proveedor p = Proveedor(proveedor, nit, direccion, telefono);
	p.ingresar();
}

void deleteData_Proveedores() {
	system("cls");
	Proveedor p;
	int id;
	cout << "Ingrese el ID del proveedor que desea eliminar: ";
	cin >> id;

	p.eliminar(id);
}

void updateData_Proveedores() {
	system("cls");
	string proveedor, nit, direccion, telefono;
	int id;

	cout << "Ingrese el ID del proveedor que desea actualizar: ";
	cin >> id;
	/*CREAR UNA FUNCION DE BUSQUEDA*/
	cout << "Ingrese el nombre del proveedor: ";
	cin.ignore();
	getline(cin, proveedor);
	cout << "Ingrese el nit del proveedor: ";
	getline(cin, nit);
	cout << "Ingrese la direccion del proveedor: ";
	getline(cin, direccion);
	cout << "Ingresee el numero de telefono del proveedor: ";
	getline(cin, telefono);

	Proveedor p = Proveedor(proveedor, nit, direccion, telefono);
	p.actualizar(id);


}

void CRUD_proveedores() {
	Proveedor p;

	int op;

	do {
		system("cls");
		cout << "1.Ingresar proveedor" << endl;
		cout << "2.Leer proveedores" << endl;
		cout << "3.Eliminar proveedor" << endl;
		cout << "4.Actualizar proveedor" << endl;
		cout << "0.Salir" << endl;
		cout << "Ingrese la opcion que desea realizar: ";
		cin >> op;

		switch (op) {
		case 1: getData_Proveedores(); break;
		case 2: p.leer(); break;
		case 3: deleteData_Proveedores(); break;
		case 4: updateData_Proveedores(); break;
		case 0: break;
		default: system("cls"); cout << "La opcion que ingreso no existe, vuelva a intentarlo"; break;
		}
	} while (op != 0);

}

//------------------------------------------------------------------------FACTURA------------------------------------------------------------------------//

void crear_Factura() {
	
	Venta_detalle v2;
	system("cls");
	
	Fecha actual;
	actual = hoy();
	
	string no_factura, serie, idempleado,nit, fecha_factura;

	cout << "Serie: ";
	cin.ignore();
	getline(cin, serie);
	cout << "ID de empleado: ";
	getline(cin, idempleado);
	cout << "NIT del cliente: ";
	getline(cin, nit);

	fecha_factura = obtener_fecha(actual);
	
	Venta v = Venta(serie, fecha_factura, idempleado, nit);
	v.datos_restantes();
	v.no_facturas();
	v.ingresar();

	v.crear_factura();

	v2.ingreso_productos();
}

void CRUD_compra_cd() {
	Venta v;
	Venta_detalle v2;

	int op;

	do {
		system("cls");
		cout << "1.Ingresar Factura" << endl;
		//cout << "2.Leer proveedores" << endl;
		//cout << "3.Eliminar proveedor" << endl;
		//cout << "4.Actualizar proveedor" << endl;
		cout << "0.Salir" << endl;
		cout << "Ingrese la opcion que desea realizar: ";
		cin >> op;

		switch (op) {
		case 1: crear_Factura(); break;
		case 2: v.datos_restantes(); break;
		//case 3: deleteData_Proveedores(); break;
		//case 4: updateData_Proveedores(); break;
		//case 0: break;
		default: system("cls"); cout << "La opcion que ingreso no existe, vuelva a intentarlo"; break;
		}
	} while (op != 0);
}


