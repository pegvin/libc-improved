#ifndef LIBCI_ISDIGIT_INCLUDE_H_
#define LIBCI_ISDIGIT_INCLUDE_H_ 1

unsigned char lci_isdigit(char a);

#ifdef LIBCI_INCLUDE_ISDIGIT_IMPLEMENTATION

// https://www.rapidtables.com/code/text/ascii-table.html
unsigned char lci_isdigit(char a) {
	return (a > 47 && a < 58);
}

#endif // LIBCI_INCLUDE_ISDIGIT_IMPLEMENTATION

#endif // LIBCI_ISDIGIT_INCLUDE_H_

