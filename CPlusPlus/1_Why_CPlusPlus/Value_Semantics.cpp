#include <cassert>
#include <set>
#include <string>
#include <gtest/gtest.h>

//
// This example demonstrates the use of value semantics.
// The set of toppings, t, is passed by value and
// completely copied and encapsulated by the Bagel class.
//

class Bagel {
public:
    Bagel(const std::set<std::string>& ts) : toppings_(ts) {}
private:
    std::set<std::string> toppings_;
};


TEST(ValueSemantics, CreateBagels) {
    
    auto t = std::set<std::string>{};
    t.insert("salt");
    auto a = Bagel{t};
    // 'a' is not affected
    // when adding pepper
    t.insert("pepper");
    // 'a' will have salt
    // 'b' will have salt & pepper
    auto b = Bagel{t};
    // No bagel is affected
    t.insert("oregano");
}

/* Java
 TreeSet<String> t = new TreeSet<String>();
 t.add("salt");
 Bagel a = new Bagel(t);
 // Now 'a' will subtly also have pepper
 t.add("pepper");
 // 'a' and 'b' share the toppings in 't'
 Bagel b= new Bagel(t);
 // Both bagels subtly also have "oregano"
 toppings.add("oregano");
 */

