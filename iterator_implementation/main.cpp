#include "cphoneitername.h"
#include "cphonelist.h"
#include <iostream>


int main(){
 

  

    Record* pRec;
    CPhoneList list;


      Record record1 = { "Aasd", "25" };
      Record record2 = { "Basd", "25" };
      Record record3 = { "Casd", "25" };
      Record record4 = { "Dasd", "25" };
      Record record5 = { "Easd", "25" };


      list.append(record1);
      list.append(record2);
      list.append(record3);
      list.append(record4);
      list.append(record5);

    CPhoneIterName it(list);
    
    pRec = it++;
    pRec = it++;
    pRec = it++;
    pRec = it++;
    pRec = it++;
    pRec = it++;
    pRec = it++;
    pRec = it++;
    pRec = ++it;
    pRec = ++it;
    std::cout << (it++)->name;
    std::cout << (it++)->name;
    std::cout << (it++)->name;
    std::cout << (it++)->name;
    std::cout << (it++)->name;
    std::cout << (it++)->name;
    std::cout << (it++)->name;
    std::cout << (++it)->name;
    std::cout << (++it)->name;

    for (pRec = it.end(); pRec != nullptr; pRec =it.prev())
    {

    }

	return 0;
}