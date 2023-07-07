#ifndef LIBCI_POW_INCLUDE_H_
#define LIBCI_POW_INCLUDE_H_ 1

long int lci_powl(long int num, long int raisedTo);

#ifdef LIBCI_INCLUDE_POW_IMPLEMENTATION

long int lci_powl(long int num, long int raisedTo) {
	long int initialNum = num;
    for (long int i = 0; i < raisedTo; ++i) num *= initialNum;
    return num;
}

#endif // LIBCI_INCLUDE_POW_IMPLEMENTATION
#endif // LIBCI_POW_INCLUDE_H_

