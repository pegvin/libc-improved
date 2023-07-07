#ifndef LIBCI_TODIGIT_INCLUDE_H_
#define LIBCI_TODIGIT_INCLUDE_H_ 1

long int lci_todigit(char a);

#ifdef LIBCI_INCLUDE_TODIGIT_IMPLEMENTATION

long int lci_todigit(char a) {
	return a - 48;
}

#endif // LIBCI_INCLUDE_TODIGIT_IMPLEMENTATION

#endif // LIBCI_TODIGIT_INCLUDE_H_

