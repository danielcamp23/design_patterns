/*
Single Responsability Principle:
After crceating a journal, it is asked to store that journal in some location.
The programmer might be tempted to create a persistence method inside Journal class, which is not a good
aproach, since in the future, that persistence could be changed to add more functionality and if besides Journal,
there are another classes that store entries in a similar way, the programmer would have to go to each of then and replace
the code needed.

This design pattern states that these fuctionalities should be modular
*/

#include "pch.h"
#include <iostream>
#include <string>
#include <exception>
#include "Journal.h"
#include "PersistenceManager.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
	Journal myJournal("Journal of Daniel");
	PersistenceManager persistenceManager;
	for (;;) {
		string entry;
		cout << "New entry (-1 to exit): ";
		std::getline(cin, entry);
		if (entry.find("-1") != string::npos) {
			break;
		}
		myJournal.addEntry(entry);
	}
	myJournal.readEntries();
	try {
		persistenceManager.save(myJournal.getEntries(), myJournal.getTitle());
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}

	try {
		persistenceManager.read(myJournal.getTitle());
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}

	return 0;
}
