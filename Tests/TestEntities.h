//
// Created by geo_r on 24/05/2021.
//
#include "../Repo/RepoTemp.h"
#include <cassert>

void testEntities()
{
    //Test client
    Client c = Client();
    assert(c.getId() > 0);
    assert(c.getUsername() == "");

    Client c1 = Client("Strada zambilicii", "Relu65", true);
    Client c3;

    c3 = c1;
    assert(c3 == c1);

    assert(c1.getId() > 0);
    assert(c1.getUsername() == "Relu65");
    assert(c1.getId() != c.getId());

    //Test courier
    Courier cu1 = Courier();
    assert(cu1.getId() > 0);
    assert(cu1.getName() == "");

    Courier cu2 = Courier("Marus");
    Courier cu3 = cu2;
    assert(cu3 == cu2);
    assert(cu2.getId() != cu1.getId());
    assert(cu2.getName() == "Marus");
    assert(cu2.getId() > 0);

    //Test Order
    Order o = Order();

    assert(o.getId() > 0);
    assert(o.getAdress() == "");

    Order o2 = Order(1,1,1,"Strada zambilicii", "Fara smecherie aici", 10);
    assert(o2.getPrice() == 10);

    Order o3;
    o3 = o2;
    assert(o3 == o2);

    Restaurant res = Restaurant();
    assert(res.getAdress() == "");

    Restaurant res1 = Restaurant("Soviet", "Adresa");
    assert(res1.getAdress() == "Adresa");
    assert(res1.getName() == "Soviet");

    Restaurant res3;

    res3 = res1;

    assert(res3 == res1);
}

