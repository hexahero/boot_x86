#ifndef CC
#define CC

class CLASS {

public:

    void print() { 
	
		print_term("CLASS LINKED SUCCESSFULLY", LGREEN, false); 
	}

    void print_smth() {

        print_term("", LGREEN, true);

        for (unsigned int i = 0; i < 3; ++i) { 
            
            print_term("TEXT", WHITE, true);
        }

    }

    void print_int() { 
	
		print_term(1337, LGRAY, false); 
	}
	
};

#endif /* CC */