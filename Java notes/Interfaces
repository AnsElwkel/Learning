/**Interfaces before version 8 were fully and pure abstraction
* After version 8 become support default function that has a body
* Methods with body in interfaces -> default (with public modifier is default) , static
* If i create a class then extends from another class contain print() and in
  the same time implements from also another class contain print() method
* when we create a new object from child class and we try to call print()
  the print() from parent class called ...not in interface
* Any fields in interfaces have ( public static final ) access
* Functional interface -> contain one method
* Nested interface available
* Marker interface -> empty interface
* Generic interface like as C++ templates
 */

/**Benefitst of interfaces
 * 1- To achieve security
 * 2- Allow multiple implements
 * 3- Interface can extend an interface and also can extend multiple inheritance
 * 4- Loose coupling
 * */
public interface INTERFACE {
    void print();
    void goals();
    String s = "a"; // public static final
    default void init(){
        System.out.println("init");
    }
    static void init2(){
        System.out.println("init");
    }
}
