#include "tty.cpp"
#include "class_to_link.cpp"

CLASS obj;

extern "C" void startup() {

	move_cursor(80);
	print_term("BOOT SUCCESS", LGREEN, true);

	obj.print();
	obj.print_smth();
	obj.print_int();

}