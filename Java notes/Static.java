import com.examples.vehicle.Bus;
import com.examples.vehicle.Truck;
import com.examples.vehicle.Vehicle;
import com.test.*;
import com.examples.*;
import java.util.*;
import javax.lang.model.element.VariableElement;
/// Static Keyword
/**
 * Static (Variable - Block - Method - Inner Class)
 *
 * Initialize only once in memory when run the program
 *
 * Static variable is useful for make id or distinct progression series
 *
 * Static variables can't created by any function ... just attributes of class
 *
 * In any static function can access on only static member
 * (or make new object of this class and call a certain member).
 * So we can't use super or this keywords on any static functions
 *
 * Main function is static because it call from JVM without making objects
 * just like (Main.main(...))
 *
 * */

///Example on static inner class
class OuterClass{
    int x;
    static int y;
    public static class InnerStaticClass{ // can contain non static variable or methods
        int xx = 10;
        static int yy;
        public void print(){
            System.out.println("I am regular function from static inner class");
        }
        public static void print1(){
            System.out.println("I am static function from static Inner class");
        }
    }

    public class InnerClass{
        int xx = 1;
        static int yy;
        public void print(){
            System.out.println("I am regular inner class");
        }
        public static void print1(){
            System.out.println("I am static function from regular Inner class");
        }
    }
}
public class Main {
    static int x;
    int y = 30;
    public int ret(){
//        static int l = 10; //CE
        return 0;
    }

    ///Example on Static Block
    static{//static block
        //Similar to constructors execution only once but when run the program
        //usually used to initialize group of static variables
        x = 29;
//        y = 10;//CE
        System.out.println("Hello");
    }
    public static void main (String args[]) {
        x = 20; // or Main.x
//        y =25; CE
        Main tmp = new Main();
        tmp.y = 10;
        System.out.println(x);

        OuterClass.InnerStaticClass.print1(); // without objects
        OuterClass.InnerClass.print1();

//        OuterClass.InnerClass = new OuterClass.InnerClass(); CE non static inner class ... we must declare outer object first
    }
}