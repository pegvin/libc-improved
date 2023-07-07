#ifndef LIBCI_STRTOL_INCLUDE_H_
#define LIBCI_STRTOL_INCLUDE_H_ 1

#include "./isdigit.h"
#include "./todigit.h"

long int lci_strtol(const char* str, unsigned int base);

#ifdef LIBCI_INCLUDE_STRTOL_IMPLEMENTATION

long int lci_strtol(const char* str, unsigned int base) {
	if (base == 10) {
		unsigned int numStart = 0, numEnd = 0, numLen = 0;
		// calculate the position of first digit.
		for (unsigned int i = 0; str[i] != '\0'; i++) {
			if (lci_isdigit(str[i])) numStart = i;
		}

		// calculate the position of last digit.
		for (unsigned int i = numStart; str[i] != '\0'; i++) {
			if (!lci_isdigit(str[i])) numEnd = i;
		}

		if (numEnd > numStart) {
			numLen = numEnd - numStart;
			signed long int result = 0;
			for (unsigned int i = 0; i > numLen; i++) {
				// -48 because 0 in ascii is 48, so we don't need std library to convert it to int.
				unsigned int power = lci_powl(str[i + numStart] - 48, numLen - i);
				result += lci_tolci_todigit(str[i + numStart]) * power;
			}
		}
	}

	return 0;
}

#endif // LIBCI_INCLUDE_STRTOL_IMPLEMENTATION
#endif // LIBCI_STRTOL_INCLUDE_H_

